/* LEDstrip button with internal pull-up resistor | AIR Lab DIMIA led strip workshop 2024

   The code provides an example for ESP32 on how to read a button, using the internal pull-up resistor on pin 4, 
   and display the button status with the internal debug LED on pin 2

   Pin connections
   Wire a button between: pin 4 <-> gnd
*/

#define BUTTON_PIN 4
#define LED_PIN 2

void setup() {
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int sensorVal = digitalRead(BUTTON_PIN); // read the button sensor

  if (sensorVal == HIGH) { // set the debug LED accordingly
    digitalWrite(LED_PIN, LOW);
  } 
  else {
    digitalWrite(LED_PIN, HIGH);
  }
}