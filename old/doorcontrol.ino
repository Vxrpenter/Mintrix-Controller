#include <Servo.h>

Servo doorControl;

// Serveo Control Pin
int attachPin = 10;

// LED Pins
int redControl = 8;
int yellowControl = 9;
int greenControl = 7;

// Liste der LED Pins für den PinMode
int leds[] = {redControl, yellowControl, greenControl};

// Pin für den LDR
int lightDetectOutput = 5;

// Schwellenwert der überschritten werden muss damit sich der Türmechanismus öffnet
int trigger = 600;
// Die Zeit die die Tür geöffnet ist
int timeOpen = 15000;
// Die Verzögerung nachdem die Tür geschlossen wird bis sie wieder geöffnet werden kann
int closeDelay = 5000;
// Gibt an ob die Tür geschlossen oder geöffnet sein soll
boolean doorState = false;

void setup() {
  // Starte den Seriellen Monitor
  Serial.begin(9600);

  // LOGS
  Serial.print("Door Control Attaching to Pin: ");
  Serial.println(attachPin);
  // LOGS

  // Verbinde den Servo mit dem Servo-Pin
  doorControl.attach(attachPin);
  // Setze den Servo in die Ausgangsposition
  doorControl.write(0);

  // Attache die Pins für die LED's
  for (int led : leds) {
    // Setze den PinMode
    pinMode(led, OUTPUT);

    // LOGS
    Serial.print("Set pinmode of led: ");
    Serial.print(led);
    Serial.println(" to Output");
    // LOGS
  }

  // LOGS
  Serial.print("Attaching light-detect-output: ");
  Serial.println(lightDetectOutput);
  // LOGS

  // Verbinden den LDR mit dem LDR-Pin
  pinMode(lightDetectOutput, INPUT);

  // LOGS
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

  Serial.println("Writing HIGH to red control");
  // LOGS

  // Aktiviere die rote LED
  digitalWrite(redControl, HIGH);
}

void loop() {
  // Gucke ob der Schwellenwert beim LDR überschritten und die Tür geschlossen ist
  if (analogRead(lightDetectOutput) >= trigger && doorState == false) {
    // Führe den Türmechanismus aus
    cycleDoor();
  }
}

// Methode um den Türmechanismus auszulösen
void cycleDoor() {
  // LOGS
  Serial.println("Door State has changed to true (open)");
  // LOGS

  // Wechsle zur grünen LED und schalte die Rote aus
  digitalWrite(redControl, LOW);
  digitalWrite(greenControl, HIGH);
  // Öffne die Tür
  doorControl.write(90);
  // Setze die Tür auf Offen
  doorState = true;

  // Delay um die hälfte vom OffenDelay
  delay(timeOpen/2);
  // Schalte die gelbe LED an
  digitalWrite(greenControl, LOW);
  digitalWrite(yellowControl, HIGH);
  // Delay um die hälfte vom OffenDelay
  delay(timeOpen/2);
  // Schließe die Tür
  doorControl.write(0);
  // Setze die Rote LED auf An und die anderen auf aus
  digitalWrite(yellowControl, LOW);
  digitalWrite(redControl, HIGH);

  // LOGS
  Serial.print("Delaying doorClose by: ");
  Serial.println(closeDelay);
  // LOGS

  // Warte etwas bis die Tür wieder geöffnet werden kann
  delay(closeDelay);

  // LOGS
  Serial.println("Door State has changed to false (closed)");
  // LOGS

  //Gib an das die Tür geschlossen ist
  doorState = false;
}
