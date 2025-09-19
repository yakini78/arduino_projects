#include <Servo.h>
long duration;
int distance;
#define LEDPIN 9
#define WHEEL 2
#define WHEEL2 4

Servo myservo;
int pos=0;
const int trigPin=12;
const int echoPin=13;
void setup() {
myservo.attach(10);
myservo.write(90);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(WHEEL,OUTPUT);
pinMode(WHEEL2,OUTPUT);
pinMode(LEDPIN,OUTPUT);
}

void loop() {
digitalWrite(WHEEL,HIGH);
digitalWrite(WHEEL2,HIGH);
digitalWrite(LEDPIN,HIGH);
delay(2000);
digitalWrite(WHEEL,LOW);
digitalWrite(WHEEL2,HIGH);
delay(700);
digitalWrite(WHEEL,HIGH);
digitalWrite(WHEEL2,HIGH);
delay(2000);
digitalWrite(WHEEL,LOW);
digitalWrite(WHEEL2,HIGH);
delay(500);
digitalWrite(WHEEL,HIGH);
digitalWrite(WHEEL,HIGH);
delay(1000);
digitalWrite(WHEEL,LOW);
digitalWrite(WHEEL2,LOW);
delay(5000);
digitalWrite(LEDPIN,LOW);
myservo.write(90); 
myservo.write(150);
 myservo.write(150);
 delay(1000);

  myservo.write(90);
  delay(1000);

  myservo.write(20);
  delay(1000);

  myservo.write(90);
  delay(1000);

  myservo.write(50);
  delay(1000);

  myservo.write(90);
delay(1000);
}
