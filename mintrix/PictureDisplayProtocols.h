void displayPixels(CRGB picture[9][9]) {
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
      displayPixels(glumanda);
      break;
      
    case POKEBALL:
      displayPixels(pokeball);
      break;
      
    case PIKACHU:
      displayPixels(pikachu);
      break;
      
    case BLANK:
      displayPixels(blank);
      break;
  }
}
