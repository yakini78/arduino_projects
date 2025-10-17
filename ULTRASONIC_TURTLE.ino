#include <Servo.h>
Servo myservo;
const int left_ctrl = 2;//define direction control pin of A motor
const int left_pwm = 6;//define PWM control pin of A motor
const int right_ctrl = 4;//define direction control pin of B motor
const int right_pwm = 5;//define PWM control pin of B motor
#define TRIG_PIN 12// set the signal input of ultrasonic sensor to D12 
#define ECHO_PIN 13//set the signal output of ultrasonic sensor to D13 
long distance1,distance2,distance3;//define three distance
const int servopin = 10;//set the pin of servo to D10 
int myangle;
int pulsewidth;
int val;

void setup() {
  Serial.begin(9600);//open serial monitor and set baud rate to 9600
  pinMode(left_ctrl,OUTPUT);//set direction control pin of A motor to OUTPUT
  pinMode(left_pwm,OUTPUT);//set PWM control pin of A motor to OUTPUT
  pinMode(right_ctrl,OUTPUT);//set direction control pin of B motor to OUTPUT
  pinMode(right_pwm,OUTPUT);//set PWM control pin of B motor to OUTPUT
 myservo.write (90);//the angle of servo is 90 degree
  delay(300);
}
 
void loop()
 {
  avoid();//run the main program
}

void avoid()
{
 

  if((distance1 < 10)&&(distance1 != 0))//if the distance is greater than 0 and less than 10  

  {
    Stop();//stop
    
    delay(100);
    myservo.write (180);//servo rotates to 180°
    delay(200);
    distance2=Distance();//measure the distance
    delay(100);
    myservo.write (0);//rotate to 0 degree
    delay(200);
    distance3=Distance();//measure the distance
    delay(100);
    if(distance2 > distance3)//compare the distance, if left distance is more than right distance
    {
      car_left();//turn left
       
      myservo.write (90);//servo rotates to 90 degree
      //delay(50);
      //show forward pattern
    }
    else//if the right distance is greater than the left
    {
      car_right();//turn right
          myservo.write (90);
      //delay(50);
        //show forward pattern
    }
  }
  else//otherwise
  {
    car_front();//go forward
   
}

void servopulse(int servopin,int myangle)//the running angle of servo
{
  for(int i=0; i<20; i++)
  {
    pulsewidth = (myangle*11)+500;
    digitalWrite(servopin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servopin,LOW);
    delay(20-pulsewidth/1000);
  }
  
}

void car_front()//car goes forward
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void car_back()//go back
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}
void car_left()//car turns left
{
  digitalWrite(left_ctrl,HIGH);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,LOW);
  analogWrite(right_pwm,200);
}
void car_right()//car turns right
{
  digitalWrite(left_ctrl,LOW);
  analogWrite(left_pwm,200);
  digitalWrite(right_ctrl,HIGH);
  analogWrite(right_pwm,200);
}

void Stop()//stop
{
   analogWrite(left_pwm,0);
  analogWrite(right_pwm,0);
}
