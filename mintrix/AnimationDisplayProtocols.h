void displayAnimation(int frames, int framerate, CRGB animation[][9][9]) {
  Mintrix.clear();
  for (int i = 0; i < frames; i++) {
    displayFrame(animation[i]);
    delay(framerate);
  }
}
