boolean daytime = true;

int pins[] = {11, 9, 7, 5, 4};
int red = 11;
int yellow = 9;
int green = 7;

int red_foot = 4;
int green_foot = 5;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing pins to OUTPUT (Will be printent out below):");
  for(int i=0; i <= 4; i++) {
    pinMode(pins[i], OUTPUT);
    Serial.println(pins[i]);
  }
  Serial.println("All pins have been initialized");
}

void nightTrafficLight() {
  digitalWrite(yellow, HIGH);
  delay(100);  // Warte 100ms
  digitalWrite(yellow,LOW);
  delay(100);
}

void dayTrafficLight() {
  digitalWrite(green_foot, LOW);
  digitalWrite(green_foot, HIGH);
  digitalWrite(red, HIGH);
  delay(10000);
  digitalWrite(red, LOW);
  digitalWrite(green_foot, LOW);
  digitalWrite(red_foot, HIGH);
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(yellow, LOW);
  digitalWrite(green, HIGH);
  delay(5000);
  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  delay(1000);
  digitalWrite(yellow, LOW);
}

void loop() {
  if(daytime) {
    dayTrafficLight();
  }
  else if(daytime == false) {
    nightTrafficLight();
  }
}
