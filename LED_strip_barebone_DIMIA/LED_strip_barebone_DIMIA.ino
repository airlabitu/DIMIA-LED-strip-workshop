/* LEDstrip Barebone | AIR Lab DIMIA led strip workshop 2024
 * 
 * The code serves as an absolut minimum for working with LED strips and the ESP32
 * 
 * Syntax for changing color:
 * leds[number of LED] = CRGB(Red value, Green value, Blue value); (Values are 0-255)
 * FastLED.show()
 * 
 */

#include <FastLED.h>
#define NUM_LEDS 10
#define DATA_PIN 23

CRGB leds[NUM_LEDS];


void setup() 
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  for (int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB(0,0,0); // turn off all LEDs in array
  }
  FastLED.show(); // send data to LED strip
}


void loop()
{
  // turn on LED [3] (the fourth)
  leds[3] = CRGB(255,0,100);
  FastLED.show();
  delay(1000); // wait 1 sec
  
  // turn off LED [3] (the fourth)
  leds[3] = CRGB(0,0,0);
  FastLED.show();
  delay(1000); // wait 1 sec

}
