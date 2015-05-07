#ifndef JOINT_H
#define JOINT_H

#include <Encoder.h>
#include <PID_v1.h>

class Joint {
public:
	Joint(int pin_rotary_1, int pin_rotary_2, int pin_direction, int pin_power);
	void setup();
	void operate();
	void setSetpoint(int _setpoint);
	int getPosition();
	bool inPosition();
	void relax();
private:
	bool relaxing;
	void isInPosition(int currenPosition);
	int pinRotary1;
	int pinRotary2;
	int pinDirection;
	int pinPower;
	int currentDirection;
	int inPositionCounter;
	bool inPosition;
	double input;
	double output;
	double setpoint;
	Encoder *encoder;
	PID *pid;
};


#endif
