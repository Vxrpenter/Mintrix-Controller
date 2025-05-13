void displayFrame(CRGB picture[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int x = 0; x < 9; x++) {
      int currentPixel = calculateProgramLedPosition(i, x);
      Mintrix.leds[currentPixel] = picture[i][x];
    }
  }
  Mintrix.show();
  delay(1000);
}

void displayPicture(PixelArtType pixelArt) {
  switch(pixelArt) {
    case GLUMANDA:
      displayFrame(glumanda);
      break;
      
    case POKEBALL:
      displayFrame(pokeball);
      break;
      
    case PIKACHU:
      displayFrame(pikachu);
      break;
      
    case BLANK:
      displayFrame(blank);
      break;
  }
}
