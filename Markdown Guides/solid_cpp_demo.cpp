#include <iostream>
#include <string>

// Using raw pointers (*) and references (&) for manual memory management

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
    ITemperatureSensor& sensor;  // Reference (&) - cannot be null, cannot be reassigned
    IFanActuator& fan;
    INotificationSender& notifier;
    float threshold;

public:
    TemperatureController(ITemperatureSensor* s,  // Raw pointer (*) parameter
                         IFanActuator* f,
                         INotificationSender* n,
                         float t)
        : sensor(*s), fan(*f), notifier(*n), threshold(t) {  // Dereference * to initialize references &
    }

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
    // Manual memory management with raw pointers (*) and new/delete
    ITemperatureSensor* sensor = new DHTSensor();  // Raw pointer (*) with new
    IFanActuator* fan = new RelayFan();
    INotificationSender* notifier = new EmailNotifier();

    // Controller uses references (&) to the objects - demonstrates both * and &
    TemperatureController controller(sensor, fan, notifier, 25.0f);

    // Simulate IoT loop
    for (int i = 0; i < 3; ++i) {
        controller.control();
        // In real IoT, this would be in loop() with delays
    }

    // Manual cleanup with delete
    delete sensor;
    delete fan;
    delete notifier;

    return 0;
}