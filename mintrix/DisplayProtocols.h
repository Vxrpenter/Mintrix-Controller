int calculateLedPosition(int row, int led) {
  int exactRow = row-1;
  int exactLed = led-1;

  if (exactRow%2 != 0) {
    exactLed = 8-exactLed; 
  }
  
  int returnValue = exactRow*9+exactLed;

  return returnValue;
}

void fillCompletely(CRGB color) {
  for(int x=0; x < 81; x++) {
    Mintrix.leds[x] = color;
  }
  Mintrix.show();
}

void tracePathFrom(int row, int led, CRGB color, int customDelay = 500) {
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

void blinkLED(int row, int led, CRGB color, int recursions, int customDelay = 500) {
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

void matrixLights(CRGB colorOne, CRGB colorTwo, int recursions = 10, int customDelay = 500) {
  bool currentState = true;
  
  for(int x=0; x < recursions; x++) {
    Mintrix.clear();
    Mintrix.show();
    CRGB currentColor = CRGB::Black;

    if (currentState) {
      currentColor = colorOne;
    } else {
      currentColor = colorTwo;
    }
    
    for(int y=0; y < 81; y++) {
      bool currentIntegerState = (y%2)==0;

      if (currentIntegerState == currentState) {
        Mintrix.leds[y] = currentColor;
      }
    }
    Mintrix.show();

    if (currentState) {
      currentState = false;
    } else {
      currentState = true;
    }
    delay(customDelay);
  }
}
