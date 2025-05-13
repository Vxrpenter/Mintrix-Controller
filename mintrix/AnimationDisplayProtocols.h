CRGB animation [][9][9] = {
  {
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Orange, CRGB::Orange, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Orange, CRGB::Black, CRGB::Orange, CRGB::Black, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Orange, CRGB::Orange, CRGB::Orange, CRGB::Orange, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Red}, 
    {CRGB::Black, CRGB::Black, CRGB::Yellow, CRGB::Yellow, CRGB::Yellow, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Yellow},
    {CRGB::Black, CRGB::Orange, CRGB::Yellow, CRGB::Yellow, CRGB::Orange, CRGB::Orange, CRGB::Black, CRGB::Orange, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Yellow, CRGB::Yellow, CRGB::Yellow, CRGB::Orange, CRGB::Orange, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Orange, CRGB::Black, CRGB::Black, CRGB::Black}
  },
  {
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Red, CRGB::Black}, 
    {CRGB::Black, CRGB::Red, CRGB::Red, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Red, CRGB::Red, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::White, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::White, CRGB::White, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::White, CRGB::White, CRGB::Black},
    {CRGB::Black, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::White, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}
  }
};

void displayAnimation(int frames, int framerate, CRGB animation[][9][9]) {
  for (int i = 0; i < frames; i++) {
    displayFrame(animation[i]);
    delay(framerate);
  }
}
