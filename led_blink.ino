int ledPin1 = 7; //it says ledPin1 is assigned to number 7 in the arduino board.
int ledPin = 6; //it says ledPin1 is assigned to number 6 in the arduino board.
int ledPin2 = 2;
int ledPin3 = 3;
int ledPin4 = 4;
int ledPin5 = 5;
int ledPin7 = 8;
int ledPin8 = 9;
int ledPin9 = 10;
int ledPin10 = 11;
void setup() {
  pinMode(ledPin, OUTPUT); //it means ledPin is declared as an output.
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);
  pinMode(ledPin9, OUTPUT);
  pinMode(ledPin10, OUTPUT);
}

void loop() {
 digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  digitalWrite(ledPin3, HIGH);
  digitalWrite(ledPin4, HIGH);
  digitalWrite(ledPin5, HIGH);
  digitalWrite(ledPin7, HIGH);
  digitalWrite(ledPin8, HIGH);
  digitalWrite(ledPin9, HIGH);
  digitalWrite(ledPin10, HIGH);
  delay(1000);
digitalWrite(ledPin, LOW);
  digitalWrite(ledPin1,LOW );
  digitalWrite(ledPin2,LOW );
  digitalWrite(ledPin3,LOW );
  digitalWrite(ledPin4,LOW );
  digitalWrite(ledPin5,LOW );
  digitalWrite(ledPin7,LOW );
  digitalWrite(ledPin8,LOW );
  digitalWrite(ledPin9,LOW );
  digitalWrite(ledPin10,LOW );
  delay(1000);
 

















}
