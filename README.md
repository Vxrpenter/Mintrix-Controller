<div align="center">
  <h1>Arduino Sketches</h1>
  
  This repository is just a location to save my many failed c++ sketches for the arduino. There is also some added documentation down below for some of the projects. They don't typically belong to eachother and they are sometimes broken, not practical and were just created for testing
</div>

---


# Documentation for MintrixControllerScript

### CalculateLedPosition

The first value stands for the row and the second for the led. It gives you the user's position,
meaning the one from viewing the Mintrix. This means it starts with 1 and not 0 like normal arrays,
and ends with 8 instead of 9
```c++
int main() {
  calculateUserLedPosition(1, 1)
}
```

### CalculateProgramLedPosition

The first value stands for the row and the second for the led. It gives you the programs's position,
meaning the one from viewing the Mintrix. This means it starts with 0 and ends with 9 like normal arrays.
```c++
int main() {
  calculateProgramLedPosition(0, 0)
}
```

### FillCompletely

Fills all 81 pixels with exactly one color
```c++
int main() {
  fillCompletely(CRGB::Red)
}
```

### TracePathFrom

First put row and led, following with the color and then a custom delay (default 500ms). This makes
the programm follow from the given cordinates to the end of the mintirx, restarting after reaching the end

```c++
int main() {
  tracePathFrom(1, 1, CRGB::Red, 500)
}
```

### BlinkLED

First enter row and led, then put color and recursions (default 10) ending with a custom delay (default 500ms). This makes the specified led blink until reaching the end of the delay.
```c++
int main() {
  blinkLED(1, 1, CRGB::Red, 10, 500)
}
```

### MatrixLights

First enter two colors to be displayed, then number of recursions (default 10) and at last a custom delay (default 500ms). This makes one half of the pixels blink in one color, then switing to another color.
```c++
int main() {
  matrixLights(CRGB::Red, CRGB::Green, 10, 500)
}
```

### DisplayPicture

Displays a picture from the enum you enter, choose from the PixelArtType enum: [GLUMANDA, PIKACHU, POKEBALL, BLANK]
```c++
int main() {
  displayPicture(GLUMANDA);
}
```

### DisplayPixels

Displays the pixels that have been specified in a 9x9 array, accounting for 81 pixels in total. Just create an array like the one shown below and then put it into the function to display it on the mintrix.
```c++
int main() {
  CRGB blank[9][9] = {
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}
  };
  displayPixels(blank);
}
```
