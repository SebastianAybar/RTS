// ********************************************************************************
// RTS SumSem 2025
// Exercise: ApproachLights 2
// Name: Sebastian Aybar
// Matr.Number: 1273441
// ********************************************************************************

const int ledPins[] = {5, 6, 7, 8, 9};
const int numLedPins = 5;
int currentLED = 0;

const int configModeButton = 1;
const int runModeButton = 2;

// Variablen für Modi
int currentMode = 0; // 0 kein Mode, 1 configMode, 2 runMode

// Button-Entprellung
bool lastConfigButtonState = HIGH;
bool lastRunButtonState = HIGH;
unsigned long lastConfigDebounceTime = 0;
unsigned long lastRunDebounceTime = 0;
const unsigned long debounceDelay = 500;

void setup() {
  Serial.begin(9600);
  
  // Erst mal alle LED'S initialisieren
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Die Buttons für die Mode's
  pinMode(configModeButton, INPUT_PULLUP);
  pinMode(runModeButton, INPUT_PULLUP);

  // Alle LED's ausschalten
  for (int i = 0; i < numLedPins; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}

void loop() {

  
  // checkButtons();
  // checkButtonsTest();
  checkButtonsNew();

  if (currentMode == 1) {
    // Config Mode
    Serial.println("currentMode = 1");
    
  } else if (currentMode == 2) {
    // digitalWrite(ledPins[currentLED], LOW);
    // delay(2);
    // digitalWrite(ledPins[currentLED], HIGH);
    // delay(60);
    // delayMicroseconds(5);
    
    // currentLED++;
    // if (currentLED >= numLedPins) {
    //   currentLED = 0;
    // }
    Serial.println("currentMode = 2");
    
  }
}

void checkButtons() {

  unsigned long currentTime = millis();
  // Config Button prüfen
  bool configButtonReadingState = digitalRead(configModeButton);
  // Wenn der config Button sich eine längere Zeit nicht ändert, laufen wir hier auch nicht rein
  // und lastConfigDebounceTime liegt immer weiter in der Vergangenheit.
  // Das müssen wir hier tun, da wir nur auf einen State reagieren wollen, der stabil geblieben ist
  if (configButtonReadingState != lastConfigButtonState) { 
    lastConfigDebounceTime = currentTime;
  }
  // Wenn die lastConfigDebounceTime stabil geblieben ist (weit genug in der Vergangenheit ist)
  if ((currentTime - lastConfigDebounceTime) > debounceDelay) {
    if (configButtonReadingState == LOW && lastConfigButtonState == HIGH) {
      currentMode = 1;
      Serial.println("Config Mode aktiviert");
      // lastRunButtonState = HIGH;
    }
    if (configButtonReadingState == HIGH && lastConfigButtonState == LOW) {
      currentMode = 0;
      Serial.println("Config Mode deaktiviert");
    }
  }

  lastConfigButtonState = configButtonReadingState;
  
  // Run Button prüfen
  bool runButtonReadingState = digitalRead(runModeButton);
  if (runButtonReadingState != lastRunButtonState) {
    lastRunDebounceTime = currentTime;
  }
  
  if ((currentTime - lastRunDebounceTime) > debounceDelay) {
    if (runButtonReadingState == LOW && lastRunButtonState == HIGH) {
      currentMode = 2;
      Serial.println("Run Mode aktiviert");
      // lastConfigButtonState = HIGH;
    }
    if (runButtonReadingState == HIGH && lastRunButtonState == LOW) {
      currentMode = 0;
      Serial.println("Run Mode deaktiviert");
    }
  }
  lastRunButtonState = runButtonReadingState;
}

void checkButtonsTest() {
  if (digitalRead(configModeButton) == LOW) {  // Direkte Abfrage
    currentMode = 1;
    Serial.println("Config Mode (RAW) aktiviert!");
  }
  if (digitalRead(runModeButton) == LOW) {
    currentMode = 2;
    Serial.println("Run Mode (RAW) aktiviert!");
  }
}

void checkButtonsNew() {
  static unsigned long lastDebounceTime = 0;
  const unsigned long debounceDelay = 200;  // 50 ms testen

  // Config Button
  if (digitalRead(configModeButton) == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      currentMode = 1;
      Serial.println("Config Mode aktiviert!");
    }
    lastDebounceTime = millis();
  }

  // Run Button
  if (digitalRead(runModeButton) == LOW) {
    if (millis() - lastDebounceTime > debounceDelay) {
      currentMode = 2;
      Serial.println("Run Mode aktiviert!");
    }
    lastDebounceTime = millis();
  }
}




