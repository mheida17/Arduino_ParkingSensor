// Matthew Heida
// Hardware
// Proximity Sensor: HC-SR04
// Arduino Pro Mini 328 - 5V/16MHz

#define trigPin 13
#define echoPin 12
#define LED_far 11
#define LED_med 10
#define LED_stp 9
long duration, distance, timeElapsed;
int previousState;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_far, OUTPUT);
  pinMode(LED_med, OUTPUT);
  pinMode(LED_stp, OUTPUT);
  previousState = 0;
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;
  if (distance < 30) {
    if (previousState == 1) {
      timeElapsed += 1;
    } else { 
      timeElapsed = 1;
    }
    previousState = 1;
    if (timeElapsed < 1000) {
      digitalWrite(LED_stp, HIGH);
      digitalWrite(LED_med, LOW);
      digitalWrite(LED_far, LOW);
    } else if (timeElapsed == 1000) {
      digitalWrite(LED_stp, LOW);
      digitalWrite(LED_med, LOW);
      digitalWrite(LED_far, LOW);
    }
  } else if ((distance > 30) && (distance < 60)) {
    if (previousState == 2) {
      timeElapsed += 1;
    } else { 
      timeElapsed = 1;
    }
    previousState = 2;
    if (timeElapsed < 1000) {
      digitalWrite(LED_stp, LOW);
      digitalWrite(LED_med, HIGH);
      digitalWrite(LED_far, LOW);
    } else if (timeElapsed == 1000) {
      digitalWrite(LED_stp, LOW);
      digitalWrite(LED_med, LOW);
      digitalWrite(LED_far, LOW);
    }
  } else {
    if (previousState == 3) {
      timeElapsed += 1;
    } else { 
      timeElapsed = 1;
    }
    previousState = 3;
    if (timeElapsed < 1000) {
      digitalWrite(LED_stp, LOW);
      digitalWrite(LED_med, LOW);
      digitalWrite(LED_far, HIGH);
    } else if (timeElapsed == 1000) {
      digitalWrite(LED_stp, LOW);
      digitalWrite(LED_med, LOW);
      digitalWrite(LED_far, LOW);
    }
  }
  delay(500);
}
