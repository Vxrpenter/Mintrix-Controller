void displayFrame(CRGB picture[9][9]) {
  Mintrix.clear();
  for (int i = 0; i < 9; i++) {
    for (int x = 0; x < 9; x++) {
      int currentPixel = calculateProgramLedPosition(i, x);
      Mintrix.leds[currentPixel] = picture[i][x];
    }
  }
  Mintrix.show();
  delay(1000);
}
