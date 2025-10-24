#include <Servo.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_LEDBackpack.h>

// Motor pins
const int left_ctrl = 2;
const int left_pwm = 6;
const int right_ctrl = 4;
const int right_pwm = 5;

// Ultrasonic sensor pins
#define TRIG_PIN 12
#define ECHO_PIN 13

long distance1, distance2, distance3;

const int servopin = 10;
Servo myservo;

// Initialize 8x8 LED matrix (I2C address 0x70 is default for HT16K33)
Adafruit_8x8matrix matrix = Adafruit_8x8matrix();

// Define "!" bitmap for 8x8 matrix
const uint8_t exclamation[] = {
  0b00000000,
  0b00110000,
  0b11111100,
  0b11111100,
  0b11111100,
  0b11111100,
  0b00110000,
  0b00000000
};

void setup() {
  Serial.begin(9600);

  pinMode(left_ctrl, OUTPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_ctrl, OUTPUT);
  pinMode(right_pwm, OUTPUT);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  myservo.attach(servopin);
  myservo.write(90);
  delay(300);

  // Initialize the matrix
  matrix.begin(0x70); // default I2C address
  matrix.clear();
  matrix.writeDisplay();
}

void loop() {
  distance1 = Distance();
  Serial.print("Front Distance: ");
  Serial.println(distance1);

  avoid();
}

void avoid() {
  if ((distance1 < 10) && (distance1 != 0)) {
    Stop();
    displayExclamation();
    delay(100);

    myservo.write(180);
    delay(300);
    distance2 = Distance();
    Serial.print("Left Distance: ");
    Serial.println(distance2);

    myservo.write(0);
    delay(300);
    distance3 = Distance();
    Serial.print("Right Distance: ");
    Serial.println(distance3);

    myservo.write(90);
    delay(200);

    if (distance2 > distance3) {
      car_left();
    } else {
      car_right();
    }
  } else {
    clearDisplay();
    car_front();
  }
}

long Distance() {
  long duration, distanceCm;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH, 30000);

  if (duration == 0) {
    return 0;
  }

  distanceCm = duration * 0.034 / 2;
  return distanceCm;
}

void displayExclamation() {
  matrix.clear();
  for (uint8_t i = 0; i < 8; i++) {
    // Draw each row of the bitmap
    for (uint8_t j = 0; j < 8; j++) {
      if (exclamation[i] & (1 << j)) {
        matrix.drawPixel(j, i, LED_ON);
      }
    }
  }
  matrix.writeDisplay();
}

void clearDisplay() {
  matrix.clear();
  matrix.writeDisplay();
}

void car_front() {
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 200);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 200);
}

void car_back() {
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 200);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 200);
}

void car_left() {
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 200);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 200);
}

void car_right() {
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 200);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 200);
}

void Stop() {
  analogWrite(left_pwm, 0);
  analogWrite(right_pwm, 0);
}
