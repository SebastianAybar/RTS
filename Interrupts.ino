int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;
int led7 = 11;
int led8 = 12;

volatile bool modeRunning = true; // false = idle; true = running
volatile unsigned long lastInterruptTime = 0;
unsigned long debounceTimeMax = 20; // Max. Debounce-Zeit in ms

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(2, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(2), switchMode, FALLING);
}

void loop() {
  if (modeRunning) {
    digitalWrite(led1, LOW);
    delayMicroseconds(500);
    digitalWrite(led1, HIGH);
    delay(61);

    digitalWrite(led2, LOW);
    delayMicroseconds(500);
    digitalWrite(led2, HIGH);
    delay(60);

    digitalWrite(led3, LOW);
    delayMicroseconds(500);
    digitalWrite(led3, HIGH);
    delay(61);

    digitalWrite(led4, LOW);
    delayMicroseconds(500);
    digitalWrite(led4, HIGH);
    delay(60);

    digitalWrite(led5, LOW);
    delayMicroseconds(500);
    digitalWrite(led5, HIGH);
    delay(61);

    digitalWrite(led6, LOW);
    delayMicroseconds(500);
    digitalWrite(led6, HIGH);
    delay(60);

    digitalWrite(led7, LOW);
    delayMicroseconds(500);
    digitalWrite(led7, HIGH);
    delay(61);

    digitalWrite(led8, LOW);
    delayMicroseconds(500);
    digitalWrite(led8, HIGH);
    delay(60);
  } else {
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
    digitalWrite(led6, HIGH);
    digitalWrite(led7, HIGH);
    digitalWrite(led8, LOW);
  }
}

void switchMode() {
  if (millis() - lastInterruptTime > debounceTimeMax) {
    modeRunning = !modeRunning;
    if (!modeRunning) {
      Serial.println("Idle...");
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      digitalWrite(led3, HIGH);
      digitalWrite(led4, HIGH);
      digitalWrite(led5, HIGH);
      digitalWrite(led6, HIGH);
      digitalWrite(led7, HIGH);
      digitalWrite(led8, LOW);
    } else {
      Serial.println("Running...");
    }
  }
}
