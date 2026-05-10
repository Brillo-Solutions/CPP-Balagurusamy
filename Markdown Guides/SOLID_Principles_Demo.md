# SOLID Principles in C++: IoT Temperature Controller Demonstration

## Introduction

Imagine you're building with blocks. SOLID principles are like rules for building with blocks that make your structure strong, easy to change, and fun to work with. If you follow these rules, your code won't fall apart when you want to add new features or fix bugs.

SOLID is an acronym for five design principles that help you write better code. Think of it like cooking: each principle is an ingredient that makes your code "taste" better (be more maintainable and flexible).

The principles are:
- **S**ingle Responsibility Principle (SRP) - One job per class
- **O**pen-Closed Principle (OCP) - Open for extension, closed for modification
- **L**iskov Substitution Principle (LSP) - Subtypes should work like their parents
- **I**nterface Segregation Principle (ISP) - Don't force classes to use methods they don't need
- **D**ependency Inversion Principle (DIP) - Depend on ideas, not specific things

We'll use an IoT Temperature Controller system to show how these principles work. This system monitors temperature, controls a fan, and sends notifications - inspired by real IoT projects like appliance control and water level monitoring.

## The Problem

We need to build an IoT Temperature Controller system that monitors temperature, controls a fan actuator, and sends notifications when the temperature exceeds a threshold. The system should be extensible for different sensors, actuators, and notification methods, following SOLID principles. This is inspired by IoT projects like smart appliance control and water level monitoring systems.

## Initial Design (Violating SOLID Principles)

```cpp
#include <iostream>
#include <string>

// Bad design - violates all SOLID principles
class IoTController {
private:
    float temperature = 25.5f; // Mock temperature
    bool fanState = false;
    std::string notificationType = "email"; // Hard-coded

public:
    void control() {
        // Read temperature (hard-coded sensor)
        float temp = temperature;

        // Control logic mixed with hardware control
        if (temp > 25.0f) {
            if (!fanState) {
                // Direct fan control
                fanState = true;
                std::cout << "Fan turned ON" << std::endl;

                // Mixed notification logic
                if (notificationType == "email") {
                    std::cout << "Email sent: High temperature detected!" << std::endl;
                } else if (notificationType == "sms") {
                    std::cout << "SMS sent: High temperature detected!" << std::endl;
                }
                // Adding new notification types requires modifying this class!
            }
        } else {
            if (fanState) {
                fanState = false;
                std::cout << "Fan turned OFF" << std::endl;
            }
        }
    }

    // To add new sensor type, modify this class!
    void setTemperature(float temp) { temperature = temp; }
};

int main() {
    IoTController controller;
    controller.control();
    return 0;
}
```

This design violates SOLID principles because:
- **SRP**: The class handles sensing, actuation, and notification
- **OCP**: Adding new sensors/actuators/notifiers requires modifying the class
- **LSP**: Not applicable yet
- **ISP**: Clients are forced to depend on methods they don't use
- **DIP**: High-level logic depends on low-level implementation details

## Refactored Design Following SOLID Principles

### Step 1: Single Responsibility Principle (SRP) - "One Job Per Class"

**Imagine:** You're a chef. Would you cook, serve food, AND clean the kitchen all at once? No! You'd have separate people for cooking, serving, and cleaning. That's SRP - each class should do only ONE thing well.

**The Problem (Bad Code):**
```cpp
class BadChef {
public:
    void cook() { /* cooking logic */ }
    void serve() { /* serving logic */ }
    void clean() { /* cleaning logic */ }
};
```

This class does too many things! If you change how cleaning works, you might break cooking accidentally.

**The Solution (Good Code):**
```cpp
class Cook {
public:
    void cook() { /* only cooking */ }
};

class Server {
public:
    void serve() { /* only serving */ }
};

class Cleaner {
public:
    void clean() { /* only cleaning */ }
};
```

**In Our IoT Example:**
Each IoT component class does ONLY one thing - inspired by the separation seen in ApplianceManager, TankManager, WifiManager, and MqttManager in the reference .ino files.

```cpp
#include <iostream>
#include <string>

// Interface for temperature sensor
class ITemperatureSensor {
public:
    virtual float getTemperature() const = 0;
    virtual ~ITemperatureSensor() = default;
};

// Interface for fan actuator
class IFanActuator {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
    virtual ~IFanActuator() = default;
};

// Interface for notification sender
class INotificationSender {
public:
    virtual void sendNotification(const std::string& message) = 0;
    virtual ~INotificationSender() = default;
};

// Temperature sensor - ONLY reads temperature, nothing else!
class DHTSensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        // DHT-specific logic only
        // Simulate reading from DHT sensor
        return 25.5f; // Mock value
    }
};

// Fan actuator - ONLY controls fan, nothing else!
class RelayFan : public IFanActuator {
private:
    bool state = false;

public:
    void turnOn() override {
        state = true;
        std::cout << "Fan turned ON via relay" << std::endl;
        // GPIO control logic for relay
    }

    void turnOff() override {
        state = false;
        std::cout << "Fan turned OFF via relay" << std::endl;
        // GPIO control logic for relay
    }

    bool isOn() const override {
        return state;
    }
};

// Email notifier - ONLY sends email notifications, nothing else!
class EmailNotifier : public INotificationSender {
public:
    void sendNotification(const std::string& message) override {
        // Email-specific logic only
        validateEmailAddress();
        std::cout << "Email notification: " << message << std::endl;
        // SMTP connection, authentication, send...
    }

private:
    void validateEmailAddress() {
        // Email validation logic
    }
};
```

**Why SRP is Important:**
- **Easy to change:** Want to improve temperature sensing? Only touch DHTSensor
- **Easy to test:** Test each IoT component separately
- **Less bugs:** Changes in sensing don't break actuation
- **Reusable:** Use RelayFan in other IoT projects
```

### Step 2: Open-Closed Principle (OCP) - "Open for Extension, Closed for Modification"

**Imagine:** You have a toy box. Instead of breaking it open to add new toys, you want to design it so you can just add toys through an opening without changing the box itself. That's OCP!

**The Problem (Bad Code):**
```cpp
class ToyBox {
public:
    void addToy(std::string toyType) {
        if (toyType == "car") {
            // add car logic
        } else if (toyType == "doll") {
            // add doll logic
        }
        // To add a new toy, you must MODIFY this class!
    }
};
```

**The Solution (Good Code):**
```cpp
class Toy {
public:
    virtual void play() = 0;
};

class Car : public Toy {
public:
    void play() override { /* car playing */ }
};

class Doll : public Toy {
public:
    void play() override { /* doll playing */ }
};

class ToyBox {
private:
    std::vector<std::unique_ptr<Toy>> toys;
public:
    void addToy(std::unique_ptr<Toy> toy) {
        toys.push_back(std::move(toy));
        // No modification needed to add new toys!
    }
};
```

**In Our IoT Example:**
The TemperatureController can work with new sensors, actuators, and notifiers without changing its code.

```cpp
#include <memory>

// IoT Controller - Open for extension, closed for modification
class TemperatureController {
private:
    std::unique_ptr<ITemperatureSensor> sensor;
    std::unique_ptr<IFanActuator> fan;
    std::unique_ptr<INotificationSender> notifier;
    float threshold;

public:
    // Constructor accepts ANY implementations of the interfaces
    TemperatureController(std::unique_ptr<ITemperatureSensor> s,
                         std::unique_ptr<IFanActuator> f,
                         std::unique_ptr<INotificationSender> n,
                         float t)
        : sensor(std::move(s)), fan(std::move(f)), notifier(std::move(n)), threshold(t) {}

    // Control logic - doesn't change when we add new components!
    void control() {
        float temp = sensor->getTemperature();
        std::cout << "Temperature: " << temp << "°C" << std::endl;

        if (temp > threshold && !fan->isOn()) {
            fan->turnOn();
            notifier->sendNotification("Fan activated due to high temperature");
        } else if (temp <= threshold && fan->isOn()) {
            fan->turnOff();
            notifier->sendNotification("Temperature normalized, fan deactivated");
        }
    }
};

// Different sensor implementations - can add without modifying controller
class DS18B20Sensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        return 24.8f; // Different sensor implementation
    }
};

class UltrasonicSensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        return 26.2f; // Yet another sensor type
    }
};

// Different actuator implementations
class ServoFan : public IFanActuator {
private:
    bool state = false;
public:
    void turnOn() override {
        state = true;
        std::cout << "Servo fan activated" << std::endl;
    }
    void turnOff() override {
        state = false;
        std::cout << "Servo fan deactivated" << std::endl;
    }
    bool isOn() const override { return state; }
};

// Different notification implementations
class SMSNotifier : public INotificationSender {
public:
    void sendNotification(const std::string& message) override {
        std::cout << "SMS: " << message << std::endl;
    }
};

int main() {
    // Create controller with any combination of implementations
    auto sensor = std::make_unique<DHTSensor>();
    auto fan = std::make_unique<RelayFan>();
    auto notifier = std::make_unique<EmailNotifier>();
    TemperatureController controller(std::move(sensor), std::move(fan), std::move(notifier), 25.0f);

    controller.control();

    // Want to use different components? Just create new implementations
    // and inject them - NO CHANGES to TemperatureController needed!
    // auto newSensor = std::make_unique<DS18B20Sensor>();
    // auto newFan = std::make_unique<ServoFan>();
    // auto newNotifier = std::make_unique<SMSNotifier>();
    // TemperatureController newController(std::move(newSensor), std::move(newFan), std::move(newNotifier), 25.0f);

    return 0;
}
```

**Why OCP is Important:**
- **Easy to add features:** Want infrared sensors? Just create InfraredSensor and inject it
- **No breaking changes:** Adding new IoT components doesn't break existing code
- **Future-proof:** Your IoT system can grow with new devices
- **Team friendly:** Multiple developers can add sensors/actuators without conflicts
```

### Step 3: Liskov Substitution Principle (LSP) - "Children Should Act Like Their Parents"

**Imagine:** You have a "Bird" class that can fly. If you create a "Penguin" that inherits from Bird, but penguins can't fly, that's wrong! Penguins should either fly or not inherit from Bird. That's LSP - child classes must behave like their parent classes.

**The Problem (Bad Code):**
```cpp
class Bird {
public:
    virtual void fly() { std::cout << "Flying!" << std::endl; }
};

class Penguin : public Bird {
public:
    void fly() override {
        throw std::runtime_error("Penguins can't fly!");
    }
};

void makeBirdFly(Bird* bird) {
    bird->fly();  // Crashes if penguin!
}
```

**The Solution (Good Code):**
```cpp
class Bird {
public:
    virtual void move() { std::cout << "Moving!" << std::endl; }
};

class Sparrow : public Bird {
public:
    void fly() override { std::cout << "Flying high!" << std::endl; }
    void move() override { fly(); }
};

class Penguin : public Bird {
public:
    void swim() { std::cout << "Swimming!" << std::endl; }
    void move() override { swim(); }
};
```

**In Our IoT Example:**
All IoT components must behave according to their interface contracts.

```cpp
// All concrete implementations properly implement their interfaces
// This ensures LSP compliance - any ITemperatureSensor can be used wherever ITemperatureSensor is expected

// Example of LSP violation (don't do this):
class BrokenSensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        // This violates LSP because it doesn't return a temperature value
        // It throws an exception instead of providing the expected behavior
        throw std::runtime_error("Sensor malfunction!");
    }
};

// Correct implementation - actually returns temperature
class WorkingSensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        // Validate and actually return temperature reading
        return 23.7f; // Valid temperature value
    }
};

// Example of LSP violation in actuator:
class BrokenActuator : public IFanActuator {
public:
    void turnOn() override {
        // This violates LSP because turnOn doesn't actually turn the fan on
        // It just logs instead of performing the expected actuation
        std::cout << "Pretending to turn fan on" << std::endl;
    }
    void turnOff() override { /* similar issue */ }
    bool isOn() const override { return false; } // Always returns false!
};

// Correct implementation - actually controls the fan
class WorkingActuator : public IFanActuator {
private:
    bool state = false;
public:
    void turnOn() override {
        state = true;
        // Actually control GPIO pin to turn fan on
        std::cout << "Fan physically turned ON" << std::endl;
    }
    void turnOff() override {
        state = false;
        // Actually control GPIO pin to turn fan off
        std::cout << "Fan physically turned OFF" << std::endl;
    }
    bool isOn() const override {
        return state; // Returns actual state
    }
};

// This function can work with ANY ITemperatureSensor
void monitorTemperature(const ITemperatureSensor* sensor) {
    float temp = sensor->getTemperature();  // Will work reliably for all sensors
    std::cout << "Monitored temperature: " << temp << "°C" << std::endl;
}

// This function can work with ANY IFanActuator
void controlFan(IFanActuator* actuator, bool shouldBeOn) {
    if (shouldBeOn && !actuator->isOn()) {
        actuator->turnOn();  // Will actually turn fan on
    } else if (!shouldBeOn && actuator->isOn()) {
        actuator->turnOff();  // Will actually turn fan off
    }
}

int main() {
    WorkingSensor workingSensor;
    WorkingActuator workingActuator;

    // Both functions work reliably with proper implementations
    monitorTemperature(&workingSensor);
    controlFan(&workingActuator, true);

    // Broken implementations would cause unexpected behavior!
    // BrokenSensor brokenSensor;
    // monitorTemperature(&brokenSensor);  // Would throw exception

    return 0;
}
```

**Why LSP is Important:**
- **Reliable IoT:** You can trust that any ITemperatureSensor will return temperature readings
- **Easy testing:** Test with any concrete component and expect consistent behavior
- **Polymorphism works:** Interface pointers can be used safely with implementations
- **No surprises:** IoT system behaves predictably with different hardware
```

### Step 4: Interface Segregation Principle (ISP) - "Don't Force Unwanted Methods on Classes"

**Imagine:** You have a universal remote control with buttons for TV, DVD, and radio. But your TV doesn't need the radio buttons, and your DVD doesn't need TV buttons. That's annoying! ISP says: give each device only the buttons it needs.

**The Problem (Bad Code):**
```cpp
class UniversalRemote {
public:
    virtual void turnOnTV() = 0;
    virtual void turnOnDVD() = 0;
    virtual void turnOnRadio() = 0;
    // TV class is forced to implement radio methods it doesn't need!
};

class TV : public UniversalRemote {
public:
    void turnOnTV() override { /* TV logic */ }
    void turnOnDVD() override { /* ??? TV doesn't control DVD */ }
    void turnOnRadio() override { /* ??? TV doesn't control radio */ }
};
```

**The Solution (Good Code):**
```cpp
class ITVControl {
public:
    virtual void turnOnTV() = 0;
};

class IDVDControl {
public:
    virtual void turnOnDVD() = 0;
};

class TV : public ITVControl {
public:
    void turnOnTV() override { /* only TV logic */ }
};

class DVD : public IDVDControl {
public:
    void turnOnDVD() override { /* only DVD logic */ }
};
```

**In Our IoT Example:**
Different IoT components implement only the interfaces they actually need.

```cpp
#include <vector>

// Basic sending interface
class INotificationSender {
public:
    virtual void send(const std::string& message, const std::string& recipient) = 0;
    virtual ~INotificationSender() = default;
};

// Separate interface for senders that can retry failed sends
class IRetryableSender {
public:
    virtual bool retry(const std::string& message, const std::string& recipient, int maxRetries) = 0;
    virtual ~IRetryableSender() = default;
};

// Separate interface for senders that can send to multiple recipients at once
class IBulkSender {
public:
    virtual void sendBulk(const std::vector<std::string>& messages, const std::vector<std::string>& recipients) = 0;
    virtual ~IBulkSender() = default;
};

// Email sender with retry capability - implements both interfaces it needs
class RetryableEmailSender : public EmailNotificationSender, public IRetryableSender {
public:
    bool retry(const std::string& message, const std::string& recipient, int maxRetries) override {
        for (int i = 0; i < maxRetries; ++i) {
            try {
                send(message, recipient);  // Uses inherited send method
                return true;
            } catch (const std::exception& e) {
                std::cout << "Retry " << (i + 1) << " failed: " << e.what() << std::endl;
            }
        }
        return false;
    }
};

// SMS sender with bulk capability - implements both interfaces it needs
class BulkSmsSender : public SmsNotificationSender, public IBulkSender {
public:
    void sendBulk(const std::vector<std::string>& messages, const std::vector<std::string>& recipients) override {
        if (messages.size() != recipients.size()) {
            throw std::invalid_argument("Messages and recipients count must match");
        }
        for (size_t i = 0; i < messages.size(); ++i) {
            send(messages[i], recipients[i]);  // Uses inherited send method
        }
    }
};

// Basic push sender - only implements basic sending, no extra interfaces
class BasicPushSender : public PushNotificationSender {
    // No extra methods - just basic sending
};

// Usage example:
void sendWithRetry(IRetryableSender* sender, const std::string& message, const std::string& recipient) {
    if (!sender->retry(message, recipient, 3)) {
        std::cout << "Failed to send after retries" << std::endl;
    }
}

void sendBulk(IBulkSender* sender, const std::vector<std::string>& messages, const std::vector<std::string>& recipients) {
    sender->sendBulk(messages, recipients);
}

int main() {
    RetryableEmailSender emailSender;
    BulkSmsSender smsSender;
    BasicPushSender pushSender;

    // Use only the interfaces each sender supports
    sendWithRetry(&emailSender, "Hello!", "user@example.com");
    sendBulk(&smsSender, {"Msg1", "Msg2"}, {"+123", "+456"});

    // pushSender doesn't support retry or bulk, so we don't force it to
    INotificationSender* basicSender = &pushSender;
    basicSender->send("Basic message", "device123");

    return 0;
}
```

**Why ISP is Important:**
- **Clean interfaces:** Classes only implement what they actually need
- **Less coupling:** Changes to retry logic don't affect basic senders
- **Easier testing:** Test only the methods each class actually has
- **More flexible:** Can add new capabilities without changing existing classes
```

### Step 5: Dependency Inversion Principle (DIP) - "Depend on Ideas, Not Specific Things"

**Imagine:** You want to drink coffee. Instead of depending on a specific coffee machine, you depend on the idea of "something that makes hot drinks." That way, you can use a coffee machine, tea maker, or hot chocolate machine - as long as it makes hot drinks! That's DIP.

**The Problem (Bad Code):**
```cpp
class CoffeeDrinker {
private:
    SpecificCoffeeMachine machine;  // Depends on specific machine
public:
    void drink() {
        machine.makeCoffee();  // Stuck with this machine forever!
    }
};
```

**The Solution (Good Code):**
```cpp
class IHotDrinkMaker {
public:
    virtual void makeDrink() = 0;
};

class CoffeeDrinker {
private:
    std::unique_ptr<IHotDrinkMaker> drinkMaker;  // Depends on idea
public:
    CoffeeDrinker(std::unique_ptr<IHotDrinkMaker> maker) : drinkMaker(std::move(maker)) {}
    void drink() {
        drinkMaker->makeDrink();  // Can use any drink maker!
    }
};
```

**In Our IoT Example:**
High-level IoT control logic depends on abstractions, not specific hardware implementations. This mirrors how MqttManager in the reference .ino files depends on ApplianceManager or TankManager through composition.

```cpp
// High-level business logic depends on abstraction, not concrete implementations
class NotificationService {
private:
    std::unique_ptr<NotificationManager> manager;  // Depends on abstraction

public:
    // Constructor takes abstraction (interface), not concrete class
    NotificationService(std::unique_ptr<NotificationManager> mgr) : manager(std::move(mgr)) {}

    // Business logic: sending welcome notifications
    void sendWelcomeNotification(const std::string& userId) {
        std::string message = "Welcome to our platform!";
        std::string recipient = getUserContact(userId);
        // Uses abstraction - doesn't know which senders are actually used
        manager->sendToType("email", message, recipient);
    }

    // Business logic: sending security alerts
    void sendSecurityAlert(const std::string& userId) {
        std::string message = "Security alert: Unusual activity detected";
        std::string recipient = getUserContact(userId);
        // Uses abstraction - can easily switch from SMS to email or push
        manager->sendToType("sms", message, recipient);
    }

private:
    std::string getUserContact(const std::string& userId) {
        // Simulate database lookup
        return "user" + userId + "@example.com";
    }
};

// Factory creates the specific implementations, but business logic doesn't know about them
class NotificationServiceFactory {
public:
    // Basic service with standard senders
    static std::unique_ptr<NotificationService> createService() {
        auto manager = std::make_unique<NotificationManager>();
        manager->addSender(std::make_unique<EmailNotificationSender>());
        manager->addSender(std::make_unique<SmsNotificationSender>());
        manager->addSender(std::make_unique<PushNotificationSender>());

        return std::make_unique<NotificationService>(std::move(manager));
    }

    // Advanced service with retry and bulk capabilities
    static std::unique_ptr<NotificationService> createAdvancedService() {
        auto manager = std::make_unique<NotificationManager>();
        manager->addSender(std::make_unique<RetryableEmailSender>());
        manager->addSender(std::make_unique<BulkSmsSender>());
        manager->addSender(std::make_unique<PushNotificationSender>());

        return std::make_unique<NotificationService>(std::move(manager));
    }

    // Test service with mock senders (doesn't actually send anything)
    static std::unique_ptr<NotificationService> createTestService() {
        auto manager = std::make_unique<NotificationManager>();
        // Add mock senders for testing
        // manager->addSender(std::make_unique<MockEmailSender>());
        // manager->addSender(std::make_unique<MockSmsSender>());

        return std::make_unique<NotificationService>(std::move(manager));
    }
};

int main() {
    // Business logic doesn't know or care which senders are used!
    auto service = NotificationServiceFactory::createService();

    // Same code works regardless of sender implementations
    service->sendWelcomeNotification("user123");
    service->sendSecurityAlert("user456");

    // Can easily switch to advanced service without changing business logic
    auto advancedService = NotificationServiceFactory::createAdvancedService();
    advancedService->sendWelcomeNotification("user789");

    // Can use test service for development without changing any business code
    // auto testService = NotificationServiceFactory::createTestService();

    return 0;
}
```

**Why DIP is Important:**
- **Easy to change:** Want to use database instead of files? Just change the factory
- **Easy to test:** Inject mock objects without changing business logic
- **Flexible:** Business rules don't get tied to specific technologies
- **Reusable:** Business logic can work with different implementations
```

## Complete Example

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <memory>

// Include all the classes defined above...

int main() {
    try {
        // Create notification service using factory
        auto service = NotificationServiceFactory::createService();

        // Send different types of notifications
        service->sendWelcomeNotification("123");
        service->sendSecurityAlert("456");

        // Demonstrate OCP - we can add new senders without modifying existing code
        auto manager = std::make_unique<NotificationManager>();
        manager->addSender(std::make_unique<EmailNotificationSender>());
        manager->addSender(std::make_unique<SmsNotificationSender>());
        manager->addSender(std::make_unique<PushNotificationSender>());

        // Send to all registered senders
        manager->sendAll("System maintenance tonight", "all_users");

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
```

## Why SOLID Makes Your IoT Code Better (Like a Superhero Team!)

Imagine your IoT system is a superhero team:
- **SRP**: Each device component has one special function (sensing, actuating, notifying)
- **OCP**: The system can add new IoT devices without rebuilding the controller
- **LSP**: New sensors/actuators can replace old ones without breaking the system
- **ISP**: Each IoT component only implements the interfaces it actually uses
- **DIP**: The controller depends on the "idea" of sensors/actuators, not specific hardware

## Benefits of SOLID Design in IoT (Real-World Advantages)

1. **Easier to Fix Hardware Issues**: When a sensor fails, you know exactly which class to debug
2. **Add New IoT Devices Without Breaking Old Ones**: Like adding a humidity sensor without crashing temperature control
3. **Test Individual Components**: You can test fan actuation without worrying about temperature sensing
4. **Change Hardware Easily**: Want to switch from DHT to DS18B20 sensor? Just swap the implementation
5. **Reuse Code**: Use your RelayFan actuator in completely different IoT projects

## Testing the SOLID Design (Making Sure It Works)

```cpp
// Example unit test (simplified) - like checking if each superhero can do their job
void testEmailSender() {
    EmailNotificationSender sender;

    // Test normal case
    sender.send("Test message", "test@example.com");
    // Should work without errors

    // Test error case
    try {
        sender.send("Test", "invalid-email");  // Bad email
        // If we get here, test failed!
        assert(false);
    } catch (const std::invalid_argument&) {
        // Good! It caught the error as expected
    }
}

void testNotificationManager() {
    NotificationManager manager;
    manager.addSender(std::make_unique<EmailNotificationSender>());
    manager.addSender(std::make_unique<SmsNotificationSender>());

    // Test sending to specific types
    manager.sendToType("email", "Test", "user@example.com");
    manager.sendToType("sms", "Test", "+1234567890");
    // Should work without mixing up email and SMS
}
```

## Final Thoughts: SOLID is Like Building IoT Systems with LEGO

SOLID principles help you build IoT systems that are:
- **Easy to understand** (each component has one IoT job)
- **Easy to change** (add new sensors/actuators without breaking the system)
- **Reliable** (components work predictably, crucial for IoT)
- **Reusable** (use components in different IoT projects)

This demonstration draws inspiration from real IoT projects like ApplianceControl and WaterLevelMonitor, where managers are separated by responsibility and use dependency injection - perfect examples of SOLID in embedded systems.

Start with small IoT projects and apply one principle at a time. Soon you'll wonder how you ever built IoT systems without SOLID!

Remember: Good IoT code is like a well-organized smart home - everything has its place, and new devices integrate seamlessly!