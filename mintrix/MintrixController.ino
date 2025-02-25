#include<Mintrix.h>
#include "PixelArt.h"
#include "Utility.h"
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
  displayPicture();
}
