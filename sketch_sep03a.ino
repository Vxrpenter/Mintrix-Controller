boolean daytime = true; //Akutelle Tageszeit als Variable

int pins[] = {11, 9, 7}; //Pins die für pinmode gesetztw werdenMüssen
int red = 11; //Port für die Farbe rot
int yellow = 9; //Port für die Farbe gelb
int green = 7; //Port für die Farbe grün

void setup() {
  Serial.begin(9600); //Wichtig für den Serial Monitor
  Serial.println("Initializing pins to OUTPUT (Will be printent out below):");
  for(int i=0; i <= 2; i++) {
    pinMode(pins[i], OUTPUT); //Setzt den jeweiligen Pin auf OUTPUT
    Serial.println(pins[i]);
  }
  Serial.println("All pins have been initialized");
}

void nightTrafficLight() {
  digitalWrite(yellow, HIGH); //LED an auf port von Gelb
  delay(100);  // Warte 100ms
  digitalWrite(yellow,LOW); //LED aus auf port von Gelb
  delay(100);  // Warte 100msGelb
}

void dayTrafficLight() {
  digitalWrite(green, HIGH); //LED an auf port von Grün
  delay(500);  // Warte 500ms
  digitalWrite(green, LOW); //LED an auf port von Grün
  digitalWrite(green,HIGH); //LED aus auf port von Grün
  delay(500);  // Warte 500ms
  digitalWrite(yellow, LOW); //LED an auf port von Gelb
  digitalWrite(yellow,HIGH); //LED aus auf port von Gelb
  delay(500); // Warte 500ms
  digitalWrite(red, LOW); //LED an auf port von Rot
  digitalWrite(red,HIGH); //LED aus auf port von Rot
  delay(500);// Warte 500ms
}


void loop() {
  if(daytime) {
    dayTrafficLight();
  }
  else if(daytime == false) {
    nightTrafficLight();
  }
}
