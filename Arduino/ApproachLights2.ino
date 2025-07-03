// ********************************************************************************
// RTS SumSem 2025
// Exercise: ApproachLights 2
// Name: Sebastian Aybar
// Matr.Number: 1273441
// ********************************************************************************

const int ledPins[] = {5, 6, 7, 8};
const int maxLedPins = 4;
int numLedPins = 4;

int currentLED = 0;

const int configModeButton = 2;
const int runModeButton = 3;
const int potentiometerPin = A0;

// Variablen für Modi
int currentMode = 0; // 0 kein Mode, 1 configMode, 2 runMode

bool lastConfigModeButtonState = HIGH;
bool lastRunModeButtonState = HIGH;

void setup() {
  Serial.begin(9600);
  
  // Erst mal alle LED'S initialisieren
  for (int i = 0; i < maxLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  // Die Buttons für die Mode's
  pinMode(configModeButton, INPUT_PULLUP);
  pinMode(runModeButton, INPUT_PULLUP);

  // Alle LED's ausschalten
  for (int i = 0; i < maxLedPins; i++) {
    digitalWrite(ledPins[i], HIGH);
  }

  // Anfnags maxLedPins initialisieren falls wir als erstes den RunMode laufen lassen
  int potValue = analogRead(potentiometerPin);
  numLedPins = map(potValue, 0, 1023, 1, maxLedPins);
  numLedPins = constrain(numLedPins, 1, maxLedPins);
  Serial.print("Initiale Anzahl aktiver LEDs (Setup): ");
  Serial.println(numLedPins);
}

void loop() {

  bool configModeButtonState = digitalRead(configModeButton);
  bool runModeButtonState = digitalRead(runModeButton);
  
  if (lastConfigModeButtonState == HIGH && configModeButtonState == LOW) {
    currentMode = 1;
    Serial.println("Config Mode aktiviert...");
  }

  if (lastRunModeButtonState == HIGH && runModeButtonState == LOW) {
    currentMode = 2;
    currentLED = 0;
    // Die LED's die noch aus dem configMode leuchten ausschalten
    for (int i = 0; i < maxLedPins; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
    Serial.println("Run Mode aktiviert...");
  }

  if (currentMode == 1) {
    Serial.println("Logik für config Mode...");
    int potValue = analogRead(potentiometerPin);
    numLedPins = map(potValue, 0, 1023, 1, maxLedPins+1);
    // numLedPins = constrain(numLedPins, 1, maxLedPins);

    Serial.print("Potentiometerwert: ");
    Serial.print(potValue);
    Serial.print(" => Anzahl aktiver LEDs: ");
    Serial.println(numLedPins);

    for (int i = 0; i < maxLedPins; i++) {
      if (i < numLedPins) {
        digitalWrite(ledPins[i], LOW);
      } else {
        digitalWrite(ledPins[i], HIGH);
      }
    }

    // delay(200);
  }

  
  if (currentMode == 2) {
    Serial.println("Logik für run Mode...");
    digitalWrite(ledPins[currentLED], LOW);
    delay(2);
    digitalWrite(ledPins[currentLED], HIGH);
    delay(60);
    delayMicroseconds(5);
    
    currentLED++;
    if (currentLED >= numLedPins) {
      currentLED = 0;
    }
  }

  lastConfigModeButtonState = configModeButtonState;
  lastRunModeButtonState = runModeButtonState;

}




