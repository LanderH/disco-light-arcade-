const int button1Pin = A0;
const int button2Pin = A1;
const int button3Pin = A2;
const int redPin = 14;
const int greenPin = 15;
const int bluePin = 16;

void setup() {
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  if (digitalRead(button1Pin) == HIGH) {
    // Modus 1: Wisselen tussen de drie RGB-kleuren
    digitalWrite(redPin, HIGH);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    delay(1000); // Wacht 1 seconde
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
    digitalWrite(bluePin, LOW);
    delay(1000); // Wacht 1 seconde
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, HIGH);
    delay(1000); // Wacht 1 seconde
  } else if (digitalRead(button2Pin) == HIGH) {
    // Modus 2: Flikkeren tussen de drie RGB-kleuren
    for (int i = 0; i < 5; i++) {
      digitalWrite(redPin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, LOW);
      delay(100); // Wacht 100 ms
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      delay(100); // Wacht 100 ms
      digitalWrite(redPin, LOW);
      digitalWrite(greenPin, LOW);
      digitalWrite(bluePin, HIGH);
      delay(100); // Wacht 100 ms
    }
  } else if (digitalRead(button3Pin) == HIGH) {
    // Modus 3: Alle kleuren
    for (int i = 0; i <= 255; i++) {
      analogWrite(redPin, i);
      analogWrite(greenPin, i);
      analogWrite(bluePin, i);
      delay(10); // Wacht 10 ms
    }
    for (int i = 255; i >= 0; i--) {
      analogWrite(redPin, i);
      analogWrite(greenPin, i);
      analogWrite(bluePin, i);
      delay(10); // Wacht 10 ms
    }
  }
}
