#include <PID_v1.h>
#include <Encoder.h>
#include "robot.h"
#include "joint.h"

Robot *robot;
void setup()
{
   Serial.begin(9600);  
   Serial.println("Starting");
   robot = new Robot();
   robot->setup();
   //robot->moveShoulder(2000);
   //robot->moveElbow(-1500);
   //robot->moveWrist(1500);
   robot->moveArmloomSke(2000);
   robot->moveArmloomSkf(0);
}

void loop(){
  //Serial.println("hej hej");
  Serial.println(robot->getArmloomSkfPosition());
  robot->operate();
}
