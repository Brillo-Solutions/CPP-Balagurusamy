// Interface for temperature sensor (I - Interface Segregation, D - Dependency Inversion)
interface ITemperatureSensor {
    float getTemperature();
}

// Interface for fan actuator (I - Interface Segregation, D - Dependency Inversion)
interface IFanActuator {
    void turnOn();
    void turnOff();
    boolean isOn();
}

// Interface for notification sender (I - Interface Segregation, D - Dependency Inversion)
interface INotificationSender {
    void sendNotification(String message);
}

// Concrete temperature sensor (S - Single Responsibility, O - Open for extension)
class DHTSensor implements ITemperatureSensor {
    @Override
    public float getTemperature() {
        // Simulate reading from DHT sensor
        return 25.5f; // Mock value
    }
}

// Concrete fan actuator (S - Single Responsibility, O - Open for extension)
class RelayFan implements IFanActuator {
    private boolean state = false;

    @Override
    public void turnOn() {
        state = true;
        System.out.println("Fan turned ON");
    }

    @Override
    public void turnOff() {
        state = false;
        System.out.println("Fan turned OFF");
    }

    @Override
    public boolean isOn() {
        return state;
    }
}

// Concrete notification sender (S - Single Responsibility, O - Open for extension)
class EmailNotifier implements INotificationSender {
    @Override
    public void sendNotification(String message) {
        System.out.println("Email sent: " + message);
    }
}

// Temperature controller (S - Single Responsibility, L - Liskov Substitution via interfaces)
class TemperatureController {
    private final ITemperatureSensor sensor;
    private final IFanActuator fan;
    private final INotificationSender notifier;
    private final float threshold;

    public TemperatureController(ITemperatureSensor sensor, IFanActuator fan,
                               INotificationSender notifier, float threshold) {
        this.sensor = sensor;
        this.fan = fan;
        this.notifier = notifier;
        this.threshold = threshold;
    }

    public void control() {
        float temp = sensor.getTemperature();
        System.out.println("Current temperature: " + temp + "°C");

        if (temp > threshold && !fan.isOn()) {
            fan.turnOn();
            notifier.sendNotification("Fan turned on due to high temperature");
        } else if (temp <= threshold && fan.isOn()) {
            fan.turnOff();
            notifier.sendNotification("Fan turned off as temperature normalized");
        }
    }
}

public class SolidJavaDemo {
    public static void main(String[] args) {
        // Create components (D - Dependency Inversion)
        ITemperatureSensor sensor = new DHTSensor();
        IFanActuator fan = new RelayFan();
        INotificationSender notifier = new EmailNotifier();

        // Controller depends on abstractions
        TemperatureController controller = new TemperatureController(sensor, fan, notifier, 25.0f);

        // Simulate IoT loop
        for (int i = 0; i < 3; i++) {
            controller.control();
            // In real IoT, this would be in loop() with delays
        }
    }
}