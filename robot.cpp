#include "robot.h"

Robot::setup() {
	shoulder = new Joint(PIN_SHOULDER_ROTARY1, PIN_SHOULDER_ROTARY2, PIN_SHOULDER_POWER, PIN_SHOULDER_DIRECTION);
	elbow = new Joint(PIN_ELBOW_ROTARY1, PIN_ELBOW_ROTARY2, PIN_ELBOW_POWER, PIN_ELBOW_DIRECTION);
}
void Robot::moveShoulder(int position){
	shoulder->setSetpoint(position);
}
void Robot::moveElbow(int position) {
	elbow->setSetpoint(position);
}