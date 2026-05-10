#include <iostream>
#include <memory>
#include <string>

// Interface for temperature sensor (I - Interface Segregation, D - Dependency Inversion)
class ITemperatureSensor {
public:
    virtual ~ITemperatureSensor() = default;
    virtual float getTemperature() const = 0;
};

// Interface for fan actuator (I - Interface Segregation, D - Dependency Inversion)
class IFanActuator {
public:
    virtual ~IFanActuator() = default;
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual bool isOn() const = 0;
};

// Interface for notification sender (I - Interface Segregation, D - Dependency Inversion)
class INotificationSender {
public:
    virtual ~INotificationSender() = default;
    virtual void sendNotification(const std::string& message) = 0;
};

// Concrete temperature sensor (S - Single Responsibility, O - Open for extension)
class DHTSensor : public ITemperatureSensor {
public:
    float getTemperature() const override {
        // Simulate reading from DHT sensor
        return 25.5f; // Mock value
    }
};

// Concrete fan actuator (S - Single Responsibility, O - Open for extension)
class RelayFan : public IFanActuator {
private:
    bool state = false;
public:
    void turnOn() override {
        state = true;
        std::cout << "Fan turned ON" << std::endl;
    }
    void turnOff() override {
        state = false;
        std::cout << "Fan turned OFF" << std::endl;
    }
    bool isOn() const override {
        return state;
    }
};

// Concrete notification sender (S - Single Responsibility, O - Open for extension)
class EmailNotifier : public INotificationSender {
public:
    void sendNotification(const std::string& message) override {
        std::cout << "Email sent: " << message << std::endl;
    }
};

// Temperature controller (S - Single Responsibility, L - Liskov Substitution via interfaces)
class TemperatureController {
private:
    std::unique_ptr<ITemperatureSensor> sensor;
    std::unique_ptr<IFanActuator> fan;
    std::unique_ptr<INotificationSender> notifier;
    float threshold;

public:
    TemperatureController(std::unique_ptr<ITemperatureSensor> s,
                         std::unique_ptr<IFanActuator> f,
                         std::unique_ptr<INotificationSender> n,
                         float t)
        : sensor(std::move(s)), fan(std::move(f)), notifier(std::move(n)), threshold(t) {}

    void control() {
        float temp = sensor->getTemperature();
        std::cout << "Current temperature: " << temp << "°C" << std::endl;

        if (temp > threshold && !fan->isOn()) {
            fan->turnOn();
            notifier->sendNotification("Fan turned on due to high temperature");
        } else if (temp <= threshold && fan->isOn()) {
            fan->turnOff();
            notifier->sendNotification("Fan turned off as temperature normalized");
        }
    }
};

int main() {
    // Create components using unique_ptr for ownership (D - Dependency Inversion)
    auto sensor = std::make_unique<DHTSensor>();
    auto fan = std::make_unique<RelayFan>();
    auto notifier = std::make_unique<EmailNotifier>();

    // Controller owns the components via unique_ptr
    TemperatureController controller(std::move(sensor), std::move(fan), std::move(notifier), 25.0f);

    // Simulate IoT loop
    for (int i = 0; i < 3; ++i) {
        controller.control();
        // In real IoT, this would be in loop() with delays
    }

    return 0;
}