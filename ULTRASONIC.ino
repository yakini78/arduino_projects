// Define the pins for the ultrasonic sensor
const int trigPin = 9; // Trigger pin connected to digital pin 9
const int echoPin = 10; // Echo pin connected to digital pin 10

// Variables to store duration and distance
long duration; // Variable to store the duration of the sound pulse
int distanceCm; // Variable to store the calculated distance in centimeters

void setup() {
  // Initialize serial communication for outputting distance values
  Serial.begin(9600);

  // Set the trigger pin as an output
  pinMode(trigPin, OUTPUT);
  // Set the echo pin as an input
  pinMode(echoPin, INPUT);
}

void loop() {
  // Clear the trigPin by setting it LOW for a short period
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Set the trigPin HIGH for 10 microseconds to send a pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse on the echoPin
  // pulseIn() returns the length of the pulse in microseconds
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  // Speed of sound in air is approximately 0.034 cm/microsecond
  // The sound travels to the object and back, so divide by 2
  distanceCm = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distanceCm);
  Serial.println(" cm");

  // Add a small delay between readings
  delay(100);
}
