void displayPicture() {
  for (int i = 0; i < 9; i++) {
    for (int x = 0; x < 9; x++) {
      int currentPixel = calculateProgramLedPosition(i, x);
      Mintrix.leds[currentPixel] = pikachu[i][x];
    }
  }
  Mintrix.show();
  delay(1000);
}
