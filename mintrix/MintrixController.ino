#include <Mintrix.h>
#include "ESP8266WebServer.h"
#include "ESP8266WiFi.h"

// Manifest Includes
#include "pictures/manifest.h"
#include "animations/manifest.h"

// Included Classes
#include "WebHandler.h"
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

  // Starting web and wifi stuff
  Mintrix.staticWiFi("MintrixController");
  Mintrix.startWeb();
  Mintrix.setWebPage(testPage);
}

void loop() {
  Mintrix.handleWeb();
  displayAnimation(2, 2, animation);
}
