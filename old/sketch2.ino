# include <Servo.h>

Servo servo;
int lightSensor1 = 9;
int lightSensor2 = 10;

void setup() {
	servo.attach(10);
	pinMode(lightSensor1, INPUT);
	pinMode(lightSensor2, INPUT);
}

void loop() {
	turn();
}

void turn() {
	int light2 = digitalRead(lightSensor2);
	int light1 = digitalRead(lightSensor1);
	
	if (light1 == LOW) {
		servo.write(90);
	}

	if (light2 == LOW) {
		servo.write(-90);
	}

	if (light1 == LOW && light2 == LOW) {
		// Do nothing or later print out value
	}
}
