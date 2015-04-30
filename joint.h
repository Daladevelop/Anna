#ifndef JOINT_H
#define JOINT_H
//#include "../Encoder/Encoder.h"
#include <Encoder.h>
#include <PID_v1.h>

class Joint {
public:
	Joint(int pin_rotary_1, int pin_rotary_2, int pin_direction, int pin_power);
	void setup();
	void operate();
	void setSetPoint(int _setpoint);
private:
	int pinRotary1;
	int pinRotary2;
	int pinDirection;
	int pinPower;
	int currentDirection;
	double input;
	double output;
	double setpoint;
	Encoder *encoder;
	PID *pid;
};


#endif
