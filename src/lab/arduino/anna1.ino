#define input1 2
#define input2 3
#define directionPinA 4
#define motorPinA 5


volatile int countSensorA = 0;
volatile int countSensorB = 0;

int motorDirection = 0; 
int counter = 0;
int target = 2000;
int outOfBonds = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(input1, INPUT_PULLUP);
  pinMode(input2, INPUT_PULLUP);
  pinMode(directionPinA, OUTPUT);
  pinMode(motorPinA, OUTPUT); 
  
  motorDirection = HIGH;
  digitalWrite(directionPinA, motorDirection); 
  
  Serial.begin(9600);
  analogWrite(motorPinA, 250);   
  attachInterrupt(0, tick_inc_a, CHANGE);
  attachInterrupt(1, tick_inc_b, CHANGE);
  
  Serial.println("DUDE!");
}

void loop() {
  int distance = target-countSensorA;
  
  if(distance <= 1500 && distance > 250)
  {
      analogWrite(motorPinA, 80);  
    
  }
  else if( distance <= 850 && distance > 100)
  {
     analogWrite(motorPinA, 50); 
    
  }
  
  else if( distance <= 100 && distance > 5){
    analogWrite(motorPinA, 15);
  }
  else if(distance <= 5)
  {
    Serial.println("OUT OF BOUNDS!"); 
    if(!outOfBonds)
    {  if(motorDirection == HIGH)
         motorDirection = LOW;
        else
          motorDirection = HIGH; 
       
        analogWrite(motorPinA, 255);
        digitalWrite(directionPinA,motorDirection);       
        countSensorA = 0; 
        outOfBonds = 1; 
     }
  }
  if(distance > 10 && countSensorA > 100)
    outOfBonds = 0; 
    

  /*counter = counter + motorDirection * countSensorA;
  countSensorA = 0;
  Serial.println(counter); 
  if(counter > 2000 && motorDirection == 1){
    analogWrite(directionPinA,LOW);
    analogWrite(motorPinA, 255);
    delay(300);
    analogWrite(motorPinA, 0);
    Serial.println("CHanging");
    delay(2000); 
    counter = counter + motorDirection * countSensorA;
    countSensorA = 0;
    motorDirection = -1;
    analogWrite(motorPinA, 255);
  }
  if(motorDirection == -1 && counter<200){
    analogWrite(directionPinA, HIGH);
    analogWrite(motorPinA, 255);
    delay(300);
    analogWrite(motorPinA, 0);
    motorDirection = 2;
    Serial.println("I AM DONE!"); 
   }
  Serial.print("Tack! ");
  Serial.print(countSensorB);
  Serial.print("Tick! ");
  Serial.println(countSensorA);*/
}

void tick_inc_a()
{
  countSensorA++;
}

void tick_inc_b()
{
  countSensorB++;
}
