// Interface for temperature sensor (I - Interface Segregation, D - Dependency Inversion)
interface ITemperatureSensor {
    float GetTemperature();
}

// Interface for fan actuator (I - Interface Segregation, D - Dependency Inversion)
interface IFanActuator {
    void TurnOn();
    void TurnOff();
    bool IsOn();
}

// Interface for notification sender (I - Interface Segregation, D - Dependency Inversion)
interface INotificationSender {
    void SendNotification(string message);
}

// Concrete temperature sensor (S - Single Responsibility, O - Open for extension)
class DHTSensor : ITemperatureSensor {
    public float GetTemperature() {
        // Simulate reading from DHT sensor
        return 25.5f; // Mock value
    }
}

// Concrete fan actuator (S - Single Responsibility, O - Open for extension)
class RelayFan : IFanActuator {
    private bool state = false;

    public void TurnOn() {
        state = true;
        Console.WriteLine("Fan turned ON");
    }

    public void TurnOff() {
        state = false;
        Console.WriteLine("Fan turned OFF");
    }

    public bool IsOn() {
        return state;
    }
}

// Concrete notification sender (S - Single Responsibility, O - Open for extension)
class EmailNotifier : INotificationSender {
    public void SendNotification(string message) {
        Console.WriteLine("Email sent: " + message);
    }
}

// Temperature controller (S - Single Responsibility, L - Liskov Substitution via interfaces)
class TemperatureController {
    private readonly ITemperatureSensor sensor;
    private readonly IFanActuator fan;
    private readonly INotificationSender notifier;
    private readonly float threshold;

    public TemperatureController(ITemperatureSensor sensor, IFanActuator fan,
                               INotificationSender notifier, float threshold) {
        this.sensor = sensor;
        this.fan = fan;
        this.notifier = notifier;
        this.threshold = threshold;
    }

    public void Control() {
        float temp = sensor.GetTemperature();
        Console.WriteLine("Current temperature: " + temp + "°C");

        if (temp > threshold && !fan.IsOn()) {
            fan.TurnOn();
            notifier.SendNotification("Fan turned on due to high temperature");
        } else if (temp <= threshold && fan.IsOn()) {
            fan.TurnOff();
            notifier.SendNotification("Fan turned off as temperature normalized");
        }
    }
}

class SolidCSharpDemo {
    static void Main(string[] args) {
        // Create components (D - Dependency Inversion)
        ITemperatureSensor sensor = new DHTSensor();
        IFanActuator fan = new RelayFan();
        INotificationSender notifier = new EmailNotifier();

        // Controller depends on abstractions
        TemperatureController controller = new TemperatureController(sensor, fan, notifier, 25.0f);

        // Simulate IoT loop
        for (int i = 0; i < 3; i++) {
            controller.Control();
            // In real IoT, this would be in loop() with delays
        }
    }
}