#include<Mintrix.h>
#include "DisplayProtocols.h"
#include "PictureDisplayProtocols.h"

//
// Loop and Setup Methods
//

void setup() {
  Serial.begin(9600);
  Mintrix.clear();
  Mintrix.show();
}

void loop() {
  matrixLights(CRGB::Blue, CRGB::Red);
}
