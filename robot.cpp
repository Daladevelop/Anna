#include "robot.h"

void Robot::setup() {
	shoulder = new Joint(PIN_SHOULDER_ROTARY1, PIN_SHOULDER_ROTARY2, PIN_SHOULDER_POWER, PIN_SHOULDER_DIRECTION);
	elbow = new Joint(PIN_ELBOW_ROTARY1, PIN_ELBOW_ROTARY2, PIN_ELBOW_POWER, PIN_ELBOW_DIRECTION);
	armloomSkf = new Joint(PIN_ARMLOOMSKF_ROTARY1, PIN_ARMLOOMSKF_ROTARY2, PIN_ARMLOOMSKF_POWER, PIN_ARMLOOMSKF_DIRECTION);
	armloomSke = new Joint(PIN_ARMLOOMSKE_ROTARY1, PIN_ARMLOOMSKE_ROTARY2, PIN_ARMLOOMSKE_POWER, PIN_ARMLOOMSKE_DIRECTION);
	wrist = new Joint(PIN_WRIST_ROTARY1, PIN_WRIST_ROTARY2, PIN_WRIST_POWER, PIN_WRIST_DIRECTION);

    shoulder->setup();
    elbow->setup();
    wrist->setup();
    armloomSkf->setup();
    armloomSke->setup();
}
void Robot::moveShoulder(int position){
	shoulder->setSetpoint(position);
}
void Robot::moveElbow(int position) {
	elbow->setSetpoint(position);
}
void Robot::moveWrist(int position){
    wrist->setSetpoint(position);
}
void Robot::moveArmloomSke(int position){
    armloomSke->setSetpoint(position);
}
void Robot::moveArmloomSkf(int position){
    armloomSkf->setSetpoint(position);
}
int Robot::getShoulderPosition(){
    shoulder->getPosition();
}
int Robot::getArmloomSkfPosition(){
    armloomSkf->getPosition();
}
int Robot::getArmloomSkePosition(){
    armloomSke->getPosition();
}
int Robot::getElbowPosition(){
    elbow->getPosition();
}
int Robot::getWristPosition(){
    wrist->getPosition();
}
void Robot::operate(){
    shoulder->operate();
    elbow->operate();
    wrist->operate();
    armloomSkf->operate();
    armloomSke->operate();
}
