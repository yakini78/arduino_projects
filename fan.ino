const int relayPin = 7; // Connect relay signal pin to Arduino digital pin 7

void setup() {
  pinMode(relayPin, OUTPUT); // Set the relay pin as an output
}

void loop() {
  // Turn the fan on for 5 seconds
  digitalWrite(relayPin, HIGH); // Send HIGH signal to the relay to turn it on (or LOW depending on your relay module)
  delay(5000);

  // Turn the fan off for 5 seconds
  digitalWrite(relayPin, LOW); // Send LOW signal to the relay to turn it off (or HIGH)
  delay(5000);
}
