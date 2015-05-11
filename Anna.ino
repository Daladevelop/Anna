#include <PID_v1.h>
#include <Encoder.h>
#include "robot.h"
#include "joint.h"

Robot *robot;


struct robotMove{ 
  int shoulder;
  int elbow;
  int wrist;
};
robotMove moves[6];

int counter;

void setup()
{
   Serial.begin(9600);  
   Serial.println("Starting");
   robot = new Robot();
   robot->setup();
   
   //robot->moveArmloomSke(2000);
   //robot->moveArmloomSkf(0);
   moves[0].shoulder = -3296;
   moves[0].elbow = -1650;
   moves[0].wrist = 1145;
     
   moves[1].shoulder = -3296;
   moves[1].elbow = -1650;
   moves[1].wrist = -2355;
   
   moves[2].shoulder = -3296;
   moves[2].elbow = 2318;
   moves[2].wrist = 702;
   
   moves[3].shoulder = 1660;
   moves[3].elbow = -2311;
   moves[3].wrist = 702;
   
   moves[4].shoulder = 4626;
   moves[4].elbow = -78;
   moves[4].wrist = -1681;
   
   moves[5].shoulder = 0;
   moves[5].elbow = 0;
   moves[5].wrist = 0;
   counter=0;
   robot->shoulder->setSetpoint(moves[0].shoulder);
   robot->elbow->setSetpoint(moves[0].elbow);
   robot->wrist->setSetpoint(moves[0].wrist);
   robot->knee->setSetpoint(-1000);
}

void loop(){
  if(robot->inPosition())
  {
    robotMove todo = moves[counter++%6];
    robot->shoulder->setSetpoint(todo.shoulder);
    robot->elbow->setSetpoint(todo.elbow);
    robot->wrist->setSetpoint(todo.wrist);
  } 
  //Serial.print("shoulder: ");
  //Serial.print(robot->shoulder->getPosition());
  //Serial.print(" elbow: ");
  //Serial.print(robot->elbow->getPosition());
  //Serial.print(" wrist: ");
  //Serial.print(robot->wrist->getPosition());
  //Serial.println();
  //Serial.println();
  //Serial.println(robot->shoulder->getPosition());
  //Serial.println(robot->inPosition());
 //Serial.println(robot->knee->getPosition());
  robot->operate(); 
}
