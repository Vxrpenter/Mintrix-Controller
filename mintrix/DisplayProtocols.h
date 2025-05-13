int calculateUserLedPosition(int row, int led) {
  int exactRow = row-1;
  int exactLed = led-1;

  if (exactRow%2 != 0) {
    exactLed = 8-exactLed; 
  }
  
  int returnValue = exactRow*9+exactLed;

  return returnValue;
}

int calculateProgramLedPosition(int row, int led) {
  int exactRow = row;
  int exactLed = led;

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
