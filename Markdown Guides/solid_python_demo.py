from abc import ABC, abstractmethod

# Interface for temperature sensor (I - Interface Segregation, D - Dependency Inversion)
class ITemperatureSensor(ABC):
    @abstractmethod
    def get_temperature(self) -> float:
        pass

# Interface for fan actuator (I - Interface Segregation, D - Dependency Inversion)
class IFanActuator(ABC):
    @abstractmethod
    def turn_on(self) -> None:
        pass

    @abstractmethod
    def turn_off(self) -> None:
        pass

    @abstractmethod
    def is_on(self) -> bool:
        pass

# Interface for notification sender (I - Interface Segregation, D - Dependency Inversion)
class INotificationSender(ABC):
    @abstractmethod
    def send_notification(self, message: str) -> None:
        pass

# Concrete temperature sensor (S - Single Responsibility, O - Open for extension)
class DHTSensor(ITemperatureSensor):
    def get_temperature(self) -> float:
        # Simulate reading from DHT sensor
        return 25.5  # Mock value

# Concrete fan actuator (S - Single Responsibility, O - Open for extension)
class RelayFan(IFanActuator):
    def __init__(self):
        self.state = False

    def turn_on(self) -> None:
        self.state = True
        print("Fan turned ON")

    def turn_off(self) -> None:
        self.state = False
        print("Fan turned OFF")

    def is_on(self) -> bool:
        return self.state

# Concrete notification sender (S - Single Responsibility, O - Open for extension)
class EmailNotifier(INotificationSender):
    def send_notification(self, message: str) -> None:
        print(f"Email sent: {message}")

# Temperature controller (S - Single Responsibility, L - Liskov Substitution via interfaces)
class TemperatureController:
    def __init__(self, sensor: ITemperatureSensor, fan: IFanActuator,
                 notifier: INotificationSender, threshold: float):
        self.sensor = sensor
        self.fan = fan
        self.notifier = notifier
        self.threshold = threshold

    def control(self) -> None:
        temp = self.sensor.get_temperature()
        print(f"Current temperature: {temp}°C")

        if temp > self.threshold and not self.fan.is_on():
            self.fan.turn_on()
            self.notifier.send_notification("Fan turned on due to high temperature")
        elif temp <= self.threshold and self.fan.is_on():
            self.fan.turn_off()
            self.notifier.send_notification("Fan turned off as temperature normalized")

def main():
    # Create components (D - Dependency Inversion)
    sensor = DHTSensor()
    fan = RelayFan()
    notifier = EmailNotifier()

    # Controller depends on abstractions
    controller = TemperatureController(sensor, fan, notifier, 25.0)

    # Simulate IoT loop
    for _ in range(3):
        controller.control()
        # In real IoT, this would be in loop() with delays

if __name__ == "__main__":
    main()