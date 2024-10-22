/* LEDstrip Scroller | AIR Lab DIMIA led strip workshop 2024

   The code provides a scrolling motion on the LED strip for the ESP32

   Syntax for changing color:
   leds[number of LED] = CRGB(Red value, Green value, Blue value); (Values are 0-255)
   FastLED.show()

*/

#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 23

CRGB leds[NUM_LEDS];

int r = 255;
int g = 0;
int b = 100;

int i = 0; // pixel index
long timer = 0;
int interval = 100;

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

  if (millis() - timer > interval) { // the code in this block runs every interval (100 milliseconds)
    timer = millis(); // Zero the timer to "now"
    
    i++;  //increment index variable
    if (i == 10) i = 0; // reset to zero at i == 10, to match amount of LEDs on strip

    FastLED.clear();
    leds[i] = CRGB(r, g, b);
    FastLED.show();
  }
}