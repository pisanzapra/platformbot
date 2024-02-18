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
int X;

int getRandomPWMValue() {
    return random(100, 256); // 100 ile 255 arasında rastgele bir değer döndürür
}

void setup() {
    pinMode(directionPinA, OUTPUT);
    pinMode(pwmPinA, OUTPUT);
    pinMode(brakePinA, OUTPUT);

    pinMode(directionPinB, OUTPUT);
    pinMode(pwmPinB, OUTPUT);
    pinMode(brakePinB, OUTPUT);

    Serial.begin(9600);
    randomSeed(analogRead(0)); // Rastgele sayı üretimi için seed değerini ayarla
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
                X = getRandomPWMValue();
                analogWrite(pwmPinA, X);
                analogWrite(pwmPinB, X);
                break;

            default:
                // Invalid command state
                break;
        }
    }
}
