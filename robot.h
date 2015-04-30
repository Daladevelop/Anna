#define PIN_SHOULDER_ROTARY1		1
#define PIN_SHOULDER_ROTARY2		2
#define PIN_SHOULDER_POWER			3
#define PIN_SHOULDER_DIRECTION		4

#define PIN_ELBOW_ROTARY1			1
#define PIN_ELBOW_ROTARY2			2
#define PIN_ELBOW_POWER				3
#define PIN_ELBOW_DIRECTION			4

#ifndef ROBOT_H
#define ROBOT_H

#include <joint.h>

class Robot {
public:
	void setup();
	void moveShoulder(int position);
	void moveElbow(int position);
private:
	Joint *shoulder;
	Joint *elbow;
}

#endif