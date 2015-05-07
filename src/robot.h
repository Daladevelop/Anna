#ifndef ROBOT_H
#define ROBOT_H

#define PIN_SHOULDER_ROTARY1		22
#define PIN_SHOULDER_ROTARY2		23
#define PIN_SHOULDER_POWER			3
#define PIN_SHOULDER_DIRECTION		2
#define PIN_ELBOW_ROTARY1			24
#define PIN_ELBOW_ROTARY2			25
#define PIN_ELBOW_POWER				10
#define PIN_ELBOW_DIRECTION			8
#define PIN_ARMLOOMSKF_ROTARY1		26
#define PIN_ARMLOOMSKF_ROTARY2		27
#define PIN_ARMLOOMSKF_POWER		5
#define PIN_ARMLOOMSKF_DIRECTION	4
#define PIN_ARMLOOMSKE_ROTARY1		28
#define PIN_ARMLOOMSKE_ROTARY2		29
#define PIN_ARMLOOMSKE_POWER		9
#define PIN_ARMLOOMSKE_DIRECTION	12
#define PIN_WRIST_ROTARY1			30
#define PIN_WRIST_ROTARY2			31
#define PIN_WRIST_POWER				6
#define PIN_WRIST_DIRECTION			7

#include <joint.h>

class Robot {
public:
	void setup();
	void moveShoulder(int position);
	void moveElbow(int position);
private:
	Joint *shoulder;
	Joint *elbow;
	Joint *armloomSkf;
	Joint *armloomSke;
	Joint *wrist;
}

#endif