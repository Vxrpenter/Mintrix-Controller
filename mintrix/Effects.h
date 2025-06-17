void tracePathFrom(int row, int led, CRGB color, int customDelay = 500) {
  Mintrix.clear();
  int exactLed = calculateUserLedPosition(row, led);
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
  Mintrix.clear();
  int exactLed = calculateUserLedPosition(row, led);
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
  Mintrix.clear();
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
