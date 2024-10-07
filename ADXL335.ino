// Define analog pins for each axis of the ADXL335
const int xPin = A0;  // X-axis pin
const int yPin = A1;  // Y-axis pin
const int zPin = A2;  // Z-axis pin

// These values depend on your reference voltage (typically 3.3V or 5V) and sensitivity of the ADXL335 (300 mV/g)
const float sensitivity = 0.330; // 300 mV/g
const float VRef = 3.3;          // Reference voltage, change if using a different voltage
const float zero_G = VRef / 2.0; // Voltage at 0g (midpoint voltage)

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Read raw analog values from accelerometer
  int rawX = analogRead(xPin);
  int rawY = analogRead(yPin);
  int rawZ = analogRead(zPin);

  // Convert raw values to voltage (using the reference voltage)
  float voltageX = (rawX / 1023.0) * VRef;
  float voltageY = (rawY / 1023.0) * VRef;
  float voltageZ = (rawZ / 1023.0) * VRef;

  // Calculate acceleration in g's (gravity) for each axis
  float accelX = (voltageX - zero_G) / sensitivity;
  float accelY = (voltageY - zero_G) / sensitivity;
  float accelZ = (voltageZ - zero_G) / sensitivity;

  // Print values to Serial Monitor
  Serial.print("X: ");
  Serial.print(accelX);
  Serial.print(" g, Y: ");
  Serial.print(accelY);
  Serial.print(" g, Z: ");
  Serial.print(accelZ);
  Serial.println(" g");

  // Delay before next reading
  delay(500);
}
