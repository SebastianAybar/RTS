// ********************************************************************************
// RTS SumSem 2024
// Exercise: Execution Times
// Name: Sebastian Aybar
// ********************************************************************************


const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
const int numLedPins = 8;
const int BUTTON = 2;

volatile bool runningMode = true;  // Startet im Running-Modus
int currentLED = 0;

void setup() {
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  pinMode(BUTTON, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(BUTTON), toggleMode, FALLING);

  // Startzustand: alle LEDs aus
  for (int i = 0; i < numLedPins; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

void loop() {
  if (runningMode) {
    digitalWrite(ledPins[currentLED], LOW);
    delay(2);
    digitalWrite(ledPins[currentLED], HIGH);
    delay(60);
    delayMicroseconds(500);

    currentLED++;
    if (currentLED >= numLedPins) {
      currentLED = 0;
    }
  } else {
    // Idle-Modus: nur erste und letzte LED an
    for (int i = 0; i < numLedPins; i++) {
      if (i == 0 || i == numLedPins - 1) {
        digitalWrite(ledPins[i], LOW); // LED an
      } else {
        digitalWrite(ledPins[i], HIGH); // LED aus
      }
    }
    delay(100); // Kleines Delay um Strom/CPU zu sparen
  }
}

void toggleMode() {
  runningMode = !runningMode;
  currentLED = 0; // Beim Wechsel auf running von vorn starten
}
