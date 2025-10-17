const int fanPin=5;
const int ledPin=2;
void setup() {
  // put your setup code here, to run once:
pinMode(fanPin,OUTPUT);
pinMode(ledPin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite (fanPin,HIGH);
digitalWrite (ledPin,LOW);
delay(1000);
digitalWrite (fanPin,LOW);
digitalWrite (ledPin,HIGH);

}
