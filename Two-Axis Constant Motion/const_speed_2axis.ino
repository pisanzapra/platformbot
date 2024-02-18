char command;
bool shouldExit = false;

// Channel A
int directionPinA = 12;
int pwmPinA = 3;
int brakePinA = 9;

// Channel B
int directionPinB = 13;
int pwmPinB = 11;
int brakePinB = 8;


void setup() {
    pinMode(directionPinA, OUTPUT);
    pinMode(pwmPinA, OUTPUT);
    pinMode(brakePinA, OUTPUT);

    pinMode(directionPinB, OUTPUT);
    pinMode(pwmPinB, OUTPUT);
    pinMode(brakePinB, OUTPUT);

    Serial.begin(9600);
    randomSeed(analogRead(0)); 
}

void loop() {
    if (Serial.available() > 0 && !shouldExit) {
        command = Serial.read();
        Serial.print("Received command: ");
        Serial.println(command);

        // Motor control operations
        switch (command) {
            case 'F':
                Serial.println("Forward command received");
                digitalWrite(brakePinA, LOW);
                digitalWrite(brakePinB, LOW);
                digitalWrite(directionPinA, HIGH);
                digitalWrite(directionPinB, HIGH);
                analogWrite(pwmPinA, X);
                analogWrite(pwmPinB, X);
                break;
            case 'R':
                Serial.println("Right command received");
                digitalWrite(brakePinA, LOW);
                digitalWrite(brakePinB, HIGH);
                digitalWrite(directionPinA, HIGH);
                digitalWrite(directionPinB, HIGH);
                analogWrite(pwmPinA, 250);
                analogWrite(pwmPinB, 250);
                break;
            case 'L':
                Serial.println("Left command received");
                digitalWrite(brakePinA, HIGH);
                digitalWrite(brakePinB, LOW);
                digitalWrite(directionPinA, HIGH);
                digitalWrite(directionPinB, HIGH);
                analogWrite(pwmPinA, 250);
                analogWrite(pwmPinB, 205);
                break;
            case 'M':
                Serial.println("Malibu command received");
                digitalWrite(brakePinA, LOW);
                digitalWrite(brakePinB, LOW);
                digitalWrite(directionPinA, LOW);
                digitalWrite(directionPinB, HIGH);
                analogWrite(pwmPinA, 250);
                analogWrite(pwmPinB, 250);
                break;
            case 'P':
                Serial.println("Quit command received");
                shouldExit = true;
                digitalWrite(brakePinA, HIGH);
                digitalWrite(brakePinB, HIGH);
                digitalWrite(directionPinA, LOW);
                digitalWrite(directionPinB, LOW);
                return;
                break;
            default:
                // Invalid command state
                break;
        }
    }
}
