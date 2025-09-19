#include <DHT.h>
#include<Servo.h>
Servo myservo;
int pos=0;
#define DHTPIN 7
#define DHTTYPE DHT11
#define FANPIN 9
#define LEDPIN 2
#define LEDPIN1 3
DHT dht(DHTPIN, DHTTYPE);

  //ultrasonic
long duration;
int distance;
const int trigpin=10;
const int echopin=11;
void setup() {
  myservo.attach(4);
  myservo.write(90);
  dht.begin();
  pinMode(FANPIN, OUTPUT);
  pinMode(LEDPIN,OUTPUT);
  pinMode(LEDPIN1,OUTPUT);
  pinMode(trigpin,OUTPUT);
  pinMode(echopin,INPUT);
  Serial.begin(9600);                                                                                                                           
}

void loop() {
  digitalWrite(trigpin,LOW);
  delay(1000);
  digitalWrite(trigpin,HIGH);
  delay(1000);
  digitalWrite(trigpin,LOW);

  duration=pulseIn(echopin,HIGH);

  distance=duration*0.034/2;

  Serial.print("Distance:");
  Serial.println(distance);
  

  float temperature = dht.readTemperature();
  Serial.print("Temperature:");
  Serial.print(temperature);
  Serial.println("c");

  if (temperature > 26){
    digitalWrite(FANPIN, HIGH);
  //  myservo.write(150);
     digitalWrite(LEDPIN,LOW);
    delay(1000);
  }
  else {
    digitalWrite(FANPIN, LOW);
   // myservo.write(50);
    digitalWrite(LEDPIN,HIGH);
  }
  delay(1000);

  if(distance<27){
digitalWrite(LEDPIN,HIGH);
digitalWrite(LEDPIN1,HIGH);
myservo.write(50);
delay(1000);

  }else {
myservo.write(150);
digitalWrite(LEDPIN, LOW);
digitalWrite(LEDPIN1,LOW);
delay(100);
}
}
