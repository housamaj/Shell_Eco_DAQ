#include <TM1637Display.h>

// Define the connections to the display
#define CLK 3  // Clock pin (CLK)
#define DIO 4  // Data pin (DIO)

// Create a display object, set the CLK and DIO pins
TM1637Display display(CLK, DIO);

// Define the analog input pin for reading voltage
int VOLTAGE_PIN=A1;
void setup() {
  display.setBrightness(0x0f);  // Set brightness (0x0f is max brightness)
  pinMode(VOLTAGE_PIN, INPUT);  // Set A0 as input for reading voltage
  Serial.begin(9600);
}

void loop() {
  
  int voltage = analogRead(VOLTAGE_PIN);
  // Read the raw analog value from pin A0 (0 to 1023)
  // int sensorValue = analogRead(VOLTAGE_PIN);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V)
  float poop = voltage * (5.0 / 1023.0);

  // Multiply voltage by 100 to convert to an integer (for displaying 3.30V as 330)
  int displayVoltage = poop * 100;

  // Display the voltage on the 7-segment display (with decimal point)
  display.showNumberDecEx(displayVoltage, 0b01000000, true);  // Show with a decimal at the correct place

  delay(1000);  // Update the display every second
  Serial.println("A1");
}
