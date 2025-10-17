int left_ctrl = 4;
int left_pwm = 6;
int right_ctrl = 2;
int right_pwm = 5;
int sensor_L = 11;
int sensor_M = 7;
int sensor_R = 8;
int L_val, M_val, R_val;

void setup() {
  Serial.begin(9600);
  pinMode(left_ctrl, OUTPUT);
  pinMode(left_pwm, OUTPUT);
  pinMode(right_ctrl, OUTPUT);
  pinMode(right_pwm, OUTPUT);
  pinMode(sensor_L, INPUT);
  pinMode(sensor_M, INPUT);
  pinMode(sensor_R, INPUT);
}
void loop() {
  
    tracking();
  }

  void tracking() {
    L_val = digitalRead(sensor_L);
    M_val = digitalRead(sensor_M);
    R_val = digitalRead(sensor_R);
    if (M_val == 1) {
      if (M_val == 1 && R_val == 0){
        left();
    }
    else if (L_val == 0 && R_val == 1) {
      right();
    }
    else {
      front();
    }
  }
  else {
    if (L_val == 1 && R_val == 0) {
      left();
    }
    else if (L_val == 0 && R_val == 1) {
      right();
      }
      else {
      Stop();
    }
  }
}
void front() {
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 100);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 100);
}
void back() {
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 155);
}
void left() {
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 155);
  digitalWrite(right_ctrl, HIGH);
  analogWrite(right_pwm, 100);
}
void right() {
  digitalWrite(left_ctrl, HIGH);
  analogWrite(left_pwm, 100);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 155);
}

void Stop() {
  digitalWrite(left_ctrl, LOW);
  analogWrite(left_pwm, 0);
  digitalWrite(right_ctrl, LOW);
  analogWrite(right_pwm, 0);

}
