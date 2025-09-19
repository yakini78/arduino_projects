
#define fanPin 9

void setup() {
  
  Serial.begin(9600);


  pinMode (fanPin, OUTPUT);
}
void loop() {
 digitalWrite(fanPin, HIGH);
 delay(100);
 digitalWrite(fanPin, LOW);
 delay(100);

}
