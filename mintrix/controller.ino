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

bool integerState(int integer) {
  Serial.println(integer%2);
  if (integer%2 > 0) {
    return false;
  } else {
    return true;
  }
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
    delay(customDelay);
  }
}

void MartixLights(CRGB colorOne, CRGB colorTwo, int recursions = 10, int customDelay = 500) {
  bool currentState = true;
  
  for(int x=0; x < recursions; x++) {
    CRGB currentColor = CRGB::Black;

    if (currentState = true) {
      currentColor = colorOne;
    } else {
      currentColor = colorTwo;
    }
    
    for(int y=0; y < 81; x++) {
      bool currentIntegerState = integerState(y);
      Serial.println(currentIntegerState);

      if (currentIntegerState == currentState) {
        Mintrix.leds[y] = currentColor;
      }
    }
    Mintrix.show();

    if (currentState = true) {
      currentState = false;
    } else {
      currentState = true;
    }
    delay(customDelay);
  }
}

//
// Loop and Setup Methods
//

void setup() {
  Serial.begin(9600);
  Mintrix.clear();
  Mintrix.show();
}

void loop() {
  MartixLights(CRGB::Blue, CRGB::Red);
}
