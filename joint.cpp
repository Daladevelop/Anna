#include "joint.h"

Joint::Joint(int pin_rotary_1, int pin_rotary_2, int pin_power, int pin_direction)
{
	pinRotary1 = pin_rotary_1;
	pinRotary2 = pin_rotary_2;
	pinDirection = pin_direction;
	pinPower = pin_power;
}

void Joint::setup()
{
	pinMode(pinRotary1, INPUT_PULLUP);
	pinMode(pinRotary2, INPUT_PULLUP);
	pinMode(pinDirection, OUTPUT);
	pinMode(pinPower, OUTPUT);
	encoder = new Encoder(pinRotary1, pinRotary2);
	input = 0;
	output = 0;
	setpoint = 0;
	pid = new PID(&input, &output, &setpoint, 1, 0.05, 0.1, DIRECT);
	encoder->write(0);
	pid->SetMode(AUTOMATIC);
	currentDirection = -100;
}
int Joint::getPosition()
{
	return input;
}
void Joint::operate()
{
	input = encoder->read();
	pid->Compute();
	int direction = output > 127 ? LOW : HIGH;
	if (currentDirection != direction) {
		currentDirection = direction;
		digitalWrite(pinDirection, direction);
	}
	analogWrite(pinPower, abs(output - 127));
}
void Joint::setSetpoint(int _setpoint){
	setpoint = _setpoint;
}
