#include <Mintrix.h>
#include "ESP8266WebServer.h"
#include "ESP8266WiFi.h"

// Included Classes
#include "WebHandler.h"
#include "Enums.h"
#include "PixelArt.h"
//#include "Numbers.h"
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

  // Starting web and wifi stuff
  Mintrix.staticWiFi("MintrixController");
  Mintrix.startWeb();
  Mintrix.setWebPage(testPage);
}

void loop() {
  Mintrix.handleWeb();
  displayPicture(GLUMANDA);
}
