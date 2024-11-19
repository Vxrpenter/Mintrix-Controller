#include <Servo.h>

Servo doorControl;

int attachPin = 10;
int redControl = 9;
int yellowControl = 8;
int greenControl = 7;

int leds[] = {redControl, yellowControl, greenControl};

int lightDetectOutput = 0;

int trigger = 1000;
int timeOpen = 10000;
int closeDelay = 4000;
boolean doorState = false;

void setup() {
  Serial.begin(9600);
  Serial.print("Door Control Attaching to Pin: ");
  Serial.println(attachPin);
  doorControl.attach(attachPin);
  doorControl.write(0);

  for (int led : leds) {
    pinMode(led, OUTPUT);
    Serial.print("Set pinmode of led: ");
    Serial.print(led);
    Serial.println(" to Output");
  }
  
  Serial.print("Attaching light-detect-output: ");
  Serial.println(lightDetectOutput);

  Serial.print("Trigger for light-detect: ");
  Serial.println(trigger);

  Serial.print("Time door is open: ");
  Serial.println(timeOpen);

  Serial.print("Delay after closing door: ");
  Serial.println(closeDelay);

  Serial.print("Initial door-state: ");
  if (doorState) {
    Serial.println("true");
  } else {
    Serial.println("false");
  }
}

void loop() {
  delay(1000);
  doorControl.write(90);
  delay(1000);
  doorControl.write(0);
  if (analogRead(lightDetectOutput) >= trigger && doorState == false) {
    cycleDoor();
  }
  
}

void cycleDoor() {

  Serial.println("Door State has changed to true (open)");
  doorControl.write(90);
  doorState = true;
  delay(timeOpen);
  doorControl.write(-90);
  Serial.print("Delaying doorClose by: ");
  Serial.println(closeDelay);
  delay(closeDelay);
  Serial.println("Door State has changed to false (closed)");
  doorState = false;
}

void database() {
  
}
