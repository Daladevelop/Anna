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
  //int distance = target-countSensorA;
  //int power = (255*distance)/target;
  long percent = 100 - (100L*countSensorA) / target; 
  int power =(percent*255) / 100;
  
  if(power > 150)
    power = 150;
  if(power < 0){
    power = 0; 
    analogWrite(motorPinA, power);
    delay(1000);
    if(motorDirection == HIGH)
      motorDirection = LOW; 
    else
      motorDirection = HIGH;
    digitalWrite(directionPinA, motorDirection); 
    countSensorA = 0;   
  }
  Serial.println(power); 
  analogWrite(motorPinA, power);

}
void tick_inc_a()
{
  countSensorA++;
}

void tick_inc_b()
{
  countSensorB++;
}
