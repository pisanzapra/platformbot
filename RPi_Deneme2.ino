int directionPin1 = 12;
int pwmPin1 = 3;
int brakePin1 = 9;

int directionPin2 = 13;
int pwmPin2 = 11;
int brakePin2 = 8;

bool directionState1;
bool directionState2;

void setup() {
  pinMode(directionPin1, OUTPUT);
  pinMode(pwmPin1, OUTPUT);
  pinMode(brakePin1, OUTPUT);

  pinMode(directionPin2, OUTPUT);
  pinMode(pwmPin2, OUTPUT);
  pinMode(brakePin2, OUTPUT);
}

void loop() {
  // Motor 1
  directionState1 = !directionState1;

  if (directionState1 == false) {
    digitalWrite(directionPin1, LOW);
  } else {
    digitalWrite(directionPin1, HIGH);
  }

  digitalWrite(brakePin1, LOW);
  analogWrite(pwmPin1, 140);
  delay(2000);
  digitalWrite(brakePin1, HIGH);
  analogWrite(pwmPin1, 0);
  delay(2000);

  // Motor 2
  directionState2 = !directionState2;

  if (directionState2 == false) {
    digitalWrite(directionPin2, LOW);
  } else {
    digitalWrite(directionPin2, HIGH);
  }

  digitalWrite(brakePin2, LOW);
  analogWrite(pwmPin2, 140);
  delay(2000);
  digitalWrite(brakePin2, HIGH);
  analogWrite(pwmPin2, 0);
  delay(2000);
}
