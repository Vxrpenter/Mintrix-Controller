<div align="center">
  <h1>Mintrix Controller</h1>
  
  A template for easy displaying of pictures, animations, effects etc. for the mintrix arduino libary. It is used for LED Matrixes, specifically for 9x9 ones (81 Pixels)
</div>

---
## Usage

Pull the git repo onto your drive. After pulling, navigate into the `./mintrix` directory and begin using it in the `loop()` method:

```sh
git pull https://github.com/Vxrpenter/Mintrix-Controller
```

## Methods

### [CalculateLedPosition](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L1)

The first value stands for the row and the second for the led. It gives you the user's position,
meaning the one from viewing the Mintrix. This means it starts with 1 and not 0 like normal arrays,
and ends with 8 instead of 9
```c++
int main() {
  calculateUserLedPosition(1, 1)
}
```

### [CalculateProgramLedPosition](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L14)

The first value stands for the row and the second for the led. It gives you the programs's position,
meaning the one from viewing the Mintrix. This means it starts with 0 and ends with 9 like normal arrays.
```c++
int main() {
  calculateProgramLedPosition(0, 0)
}
```

### [FillCompletely](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L27)

Fills all 81 pixels with exactly one color
```c++
int main() {
  fillCompletely(CRGB::Red)
}
```

### [TracePathFrom](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L34)

First put row and led, following with the color and then a custom delay (default 500ms). This makes
the programm follow from the given cordinates to the end of the mintirx, restarting after reaching the end

```c++
int main() {
  tracePathFrom(1, 1, CRGB::Red, 500)
}
```

### [BlinkLED](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L46)

First enter row and led, then put color and recursions (default 10) ending with a custom delay (default 500ms). This makes the specified led blink until reaching the end of the delay.
```c++
int main() {
  blinkLED(1, 1, CRGB::Red, 10, 500)
}
```

### [MatrixLights](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/DisplayProtocols.h#L58)

First enter two colors to be displayed, then number of recursions (default 10) and at last a custom delay (default 500ms). This makes one half of the pixels blink in one color, then switing to another color.
```c++
int main() {
  matrixLights(CRGB::Red, CRGB::Green, 10, 500)
}
```

### [DisplayFrame](https://github.com/Vxrpenter/Arduino-Sketch-Saves/blob/main/mintrix/PictureDisplayProtocols.h#L1)

Displays a picture from the picture you enter, choose from the pictures in the `./picture` directory
```c++
int main() {
  displayFrame(glumanda);
}
```

### [DisplayAnimation](https://github.com/Vxrpenter/Mintrix-Controller/blob/main/mintrix/AnimationDisplayProtocols.h#L1)

Displays a series of frames from the animation you enter, choose from the animations in the `./animation` directory
```c++
int main() {
  displayAnimation(pokeballToGlumandaFrames, 1, pokeballToGlumanda)
}
```

## Create a Picture

For creating a picture, first navigate to `./pictures` and duplicate the `template.h`. You should now uncomment everything making it look something like this. Make sure to edit the blank pixels to your prefered colors.

```c++
/CRGB templatePicture[9][9] = {
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
```

Now add the name of your `.h` class to the `manifest.h`:

```c++
#include "template.h"
```

## Create an Animation

For creating an animation, first navigate to `./animations` and duplicate the `template.h`. You should now uncomment everything making it look something like this. Make sure to edit the blank pixels to your prefered colors, add new desired frames and change the framecount on top to the correct number.

```c++
int templateAmimationFrames= 2;

CRGB templateAmimation[][9][9] = {
  {
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}
  },
  {
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}, 
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black},
    {CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black, CRGB::Black}
  }
};
```

Now add the name of your `.h` class to the `manifest.h`:

```c++
#include "template.h"
```
