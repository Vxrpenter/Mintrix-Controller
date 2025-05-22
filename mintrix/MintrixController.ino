#include <Mintrix.h>

// Manifest Includes
#include "pictures/manifest.h"
#include "animations/manifest.h"

// Included Classes
#include "Enums.h"
#include "Utility.h"
#include "DisplayProtocols.h"
#include "Effects.h"
#include "PictureDisplayProtocols.h"
#include "AnimationDisplayProtocols.h"
//
// Loop and Setup Methods
//

void setup() {
  Serial.begin(9600);
  Mintrix.clear();
  Mintrix.show();
}

void loop() {
  displayAnimation(2, 2, animation);
}
