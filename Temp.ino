// Constants
const int analogPin = A0;  // Pin where voltage input is connected

void setup() {
  // Initialize serial communication at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read the voltage from the analog pin
  int sensorValue = analogRead(analogPin);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Print the voltage to the serial monitor
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");

  // Wait for 1 second (1000 milliseconds)
  delay(1000);
}
