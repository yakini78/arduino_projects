#include <Wire.h>
<#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h>

// --- Objects & Pin Definitions ---
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT11);
Servo myservo;

#define FANPIN 9
#define LEDPIN 2
#define LEDPIN1 3
#define TRIGPIN 10
#define ECHOPIN 11

// --- Variables ---
long duration;
int distance;
float temperature;

void setup() {
  // Initialize components
  lcd.init();
  lcd.backlight();
  dht.begin();
  myservo.attach(4);
  myservo.write(90);
  
  pinMode(FANPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN1, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // --- Read Distance ---
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * 0.034 / 2;

  // --- Read Temperature ---
  temperature = dht.readTemperature();

  // --- Fan Control based on Temp ---
  String fanStatus = "OFF";
  if (temperature > 26) {
    digitalWrite(FANPIN, HIGH);
    digitalWrite(LEDPIN, LOW);
    fanStatus = "ON ";
  } else {
    digitalWrite(FANPIN, LOW);
    digitalWrite(LEDPIN, HIGH);
    fanStatus = "OFF";
  }

  // --- Intruder Detection ---
  if (distance < 27) {
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    myservo.write(50);
  } else {
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
    myservo.write(150);
  }

  // --- LCD Display ---
  #include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <Servo.h>

// --- Objects & Pin Definitions ---
LiquidCrystal_I2C lcd(0x27, 16, 2);
DHT dht(7, DHT11);
Servo myservo;

#define FANPIN 9
#define LEDPIN 2
#define LEDPIN1 3
#define TRIGPIN 10
#define ECHOPIN 11

// --- Variables ---
long duration;
int distance;
float temperature;

void setup() {
  // Initialize components
  lcd.init();
  lcd.backlight();
  dht.begin();
  myservo.attach(4);
  myservo.write(90);
  
  pinMode(FANPIN, OUTPUT);
  pinMode(LEDPIN, OUTPUT);
  pinMode(LEDPIN1, OUTPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // --- Read Distance ---
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = duration * 0.034 / 2;

  // --- Read Temperature ---
  temperature = dht.readTemperature();

  // --- Fan Control based on Temp ---
  String fanStatus = "OFF";
  if (temperature > 26) {
    digitalWrite(FANPIN, HIGH);
    digitalWrite(LEDPIN, LOW);
    fanStatus = "ON ";
  } else {
    digitalWrite(FANPIN, LOW);
    digitalWrite(LEDPIN, HIGH);
    fanStatus = "OFF";
  }

  // --- Intruder Detection ---
  if (distance < 27) {
    digitalWrite(LEDPIN, HIGH);
    digitalWrite(LEDPIN1, HIGH);
    myservo.write(50);
  } else {
    digitalWrite(LEDPIN, LOW);
    digitalWrite(LEDPIN1, LOW);
    myservo.write(150);
  }

  // --- LCD Display ---
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp:");
  lcd.print(temperature, 1); // one decimal place
  lcd.print("C");

  lcd.setCursor(0, 1);
  if (distance < 27) {
    lcd.print("Intruder Detected");
  } else {
    lcd.print("Fan:");
    lcd.print(fanStatus);
  }

  // --- Serial Output for Debugging ---
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C, Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Fan: ");
  Serial.println(fanStatus);

  delay(2000); // Wait before next update
}

  lcd.setCursor(0, 1);
  if (distance < 27) {
    lcd.print("Intruder Detected");
  } else {
    lcd.print("Fan:");
    lcd.print(fanStatus);
  }

  // --- Serial Output for Debugging ---
  Serial.print("Temp: ");
  Serial.print(temperature);
  Serial.print(" C, Distance: ");
  Serial.print(distance);
  Serial.print(" cm, Fan: ");
  Serial.println(fanStatus);

  delay(2000); // Wait before next update
}
