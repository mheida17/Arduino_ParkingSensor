// Matthew Heida
// Hardware
// Proximity Sensor: HC-SR04
// Arduino Pro Mini 328 - 5V/16MHz

#define trigPin 4
#define echoPin 3
#define LED_GREEN 7
#define LED_YELLOW 8
#define LED_RED 9
#define RED 2
#define YELLOW 1
#define GREEN 0
#define TWO_MINUTES 60
#define QUARTER_SECOND 250
#define HALF_SECOND 500
#define FULL_SECOND 1000

long duration, distance, timeElapsed;
int previousState, currentState;

void setup() {
  /** Setup all GPIO pins */
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  testLED();
}

void loop() {
  /** Sense distance using HC-SR04 using provided algorithm */
  distance = senseDistance();

  /** Set state based on distance away from sensor */
  currentState = checkState();

  /** If the state has changed, increment the timer that controls LED poweroff */
  timeElapsed = (currentState == previousState) ? (timeElapsed+1) : 0;

  /** Loop to determine if the LED's should be powered off */
  if (timeElapsed < TWO_MINUTES) {
    setLEDOn(currentState);
    delay(500);
  } else if (timeElapsed >= TWO_MINUTES) {
    setLEDOff();
  }
  
  previousState = currentState;
  delay(QUARTER_SECOND);
}

long senseDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58;

  return distance;
}

int checkState(){
  if (distance < 30) {
    currentState = RED;
  }else if (distance < 60) {
    currentState = YELLOW;
  }else {
    currentState = GREEN;
  }

  return currentState;
}

void setLEDOn(int currentState){
  switch (currentState) {
    case RED:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, LOW);
      break;
    case YELLOW:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, LOW);
      break;
    case GREEN:
      digitalWrite(LED_RED, LOW);
      digitalWrite(LED_YELLOW, LOW);
      digitalWrite(LED_GREEN, HIGH);
      break;
    default:
      digitalWrite(LED_RED, HIGH);
      digitalWrite(LED_YELLOW, HIGH);
      digitalWrite(LED_GREEN, HIGH);
  }
}

void setLEDOff(){
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

void testLED(){
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
  delay(FULL_SECOND);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, HIGH);
  digitalWrite(LED_GREEN, LOW);
  delay(FULL_SECOND);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, HIGH);
  delay(FULL_SECOND);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_YELLOW, LOW);
  digitalWrite(LED_GREEN, LOW);
}

  
