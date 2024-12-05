# include <Server.h>

Servo servo;
int currentAngle = 0;
int lightSensorPin = 9;

void setup() {
	servo.attach(10);
	pinMode(lightSensorPin, INPUT);
}

void loop() {
	int sensor = digitalRead(lightSensorPin);
	if (sensor == LOW) {
		if (currentAngle != 90) {
			turn();
		} else {
			currentAngle = 0;
		 turn();
		}
	}
}

void turn() {
	currentAngle++;
	servo.write(currentAngle);
}