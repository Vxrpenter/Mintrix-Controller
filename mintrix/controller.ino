#include<Mintrix.h>

//
// Custom Utility Methods
//

int calculateLedPosition(int row, int led) {
  int exactRow = row-1;
  int exactLed = led-1;
  
  int returnValue = exactRow*9+exactLed;
  return returnValue;
}

void FillCompletely(CRGB color) {
  for(int x=0; x < 81; x++) {
    Mintrix.leds[x] = color;
  }
  Mintrix.show();
}

void TracePathFrom(int row, int led, CRGB color, int customDelay = 500) {
  int exactLed = calculateLedPosition(row, led);
  for(int x=exactLed; x < 81; x++) {
    Mintrix.leds[x] = color;
    Mintrix.show();
    delay(customDelay);
    Mintrix.leds[x] = CRGB::Black;
    Mintrix.show();
    delay(customDelay);
  }
}

void BlinkLED(int row, int led, CRGB color, int recursions, int customDelay = 500) {
  int exactLed = calculateLedPosition(row, led);
  for(int x=0; x < recursions; x++) {
    Mintrix.leds[exactLed] = color;
    Mintrix.show();
    delay(customDelay);
    Mintrix.leds[exactLed] = CRGB::Black;
    Mintrix.show();
  }
}

//
// Loop and Setup Methods
//

void setup() {
  Mintrix.clear();
  Mintrix.show();
}

void loop() {
  BlinkLED(1, 5, CRGB::Red, 50);
}
