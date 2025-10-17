#define WHEEL 2
#define WHEEL2 4

void setup() {
 pinMode(WHEEL,OUTPUT);
 pinMode(WHEEL2,OUTPUT);
}
void loop() {
  digitalWrite(WHEEL,HIGH);
  digitalWrite(WHEEL2,HIGH);
  delay(5000);
  digitalWrite(WHEEL,HIGH);
  digitalWrite(WHEEL2,LOW);
  delay(1000);
}
