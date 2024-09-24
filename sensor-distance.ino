int pinsIn[] = {A0};
int sensor = 0;
int distance = 0;
int voltage = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing pins to OUTPUT and INPUT (Will be printent out below):");
  for(int i=0; i <= 2; i++) {
    pinMode(pinsIn[i], INPUT);
    Serial.println(pinsIn[i]);
    
  }
  Serial.println("All pins have been initialized");
}

void loop() {
  sensor = analogRead(A0);
  voltage = sensor * (5.0 / 1023.0);
  distance = 27.68 * pow(voltage, -1.15);
  
  Serial.print("Distance recorded (rerecord in 500ms): ");
  Serial.println(distance);
  delay(500);
}
