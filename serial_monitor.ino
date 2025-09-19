const int ledPin = 2;
const int ledPin2 = 4;
void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  Serial.println("ledPin on");
  delay(2000);
  digitalWrite(ledPin, LOW);
  Serial.println("ledPin off");
  delay(2000);
  digitalWrite(ledPin2, HIGH);
  Serial.println("ledPin2 on");
  delay(2000);
  digitalWrite(ledPin2, LOW);
  Serial.println("ledPin off");
  delay(2000);
}
