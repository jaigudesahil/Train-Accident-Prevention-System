// Define pins for the LED and buzzer
const int ledPin[] = {A0, A1, A2, A3, A4, A5};
const int buzzerPin = A5;

// Define pins for the ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

// Define variables
long duration;
int distance;

void setup() {
  // Set the LED and buzzer pins as output
  for(int i=0; i<6; i++){
    pinMode(ledPin[i], OUTPUT);
  }
  pinMode(buzzerPin, OUTPUT);

  // Set the ultrasonic sensor pins as input
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Initialize Serial communication
  Serial.begin(9600);
}

void loop() {
  // Send a pulse to the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the distance from the sensor
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  // If the distance is less than 50cm, blink the LED and sound the buzzer
  if(distance < 50) {
    for(int i=0; i<6; i++){
      digitalWrite(ledPin[i], HIGH);
    }
    digitalWrite(buzzerPin, HIGH);
    delay(500);
    digitalWrite(buzzerPin, LOW);
    delay(500);
    for(int i=0; i<6; i++){
      digitalWrite(ledPin[i], LOW);
    }
    delay(500);
  } else {
    for(int i=0; i<6; i++){
      digitalWrite(ledPin[i], LOW);
    }
  }

  // Print the distance to the Serial monitor
  Serial.print("Distance: 15");
  Serial.print(distance);
  Serial.println("15 cm");

  // Wait for a moment before measuring again
  delay(100);
}
