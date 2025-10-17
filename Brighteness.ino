int led = 3;y
int led2 = 4;
int led3 = 5;
int led4 = 6;
int brighteness = 0;
int fadeAmount = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(led, brighteness);
  delay(0);
  analogWrite(led2, brighteness);
  delay(0);
  analogWrite(led3, brighteness);
  delay(0);
  analogWrite(led4, brighteness);
  delay(0);
  brighteness = brighteness + fadeAmount;
  if (brighteness == 0 || brighteness == 255) {
    fadeAmount = -fadeAmount;

  }
  delay(0);
}

