// ********************************************************************************
// RTS SumSem 2025
// Exercise: Interrupt
// Name: Sebastian Aybar
// Matr.Number: 1273441
// ********************************************************************************


const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
const int numLedPins = 8;
int currentLED = 0;
#define BUTTON 2

// Neue Variablen für Toggle-Funktion
volatile bool runningMode = false;
volatile bool modeChanged = false;

volatile unsigned long lastInterruptTime = 0;
const unsigned long debounceDelay = 200; // 200ms Entprellzeit

//Interrupt Service Routine mit Entprellung
void buttonPressed() {
  unsigned long currentTime = millis();
  
  //Nur Toggle wenn genug Zeit seit dem letzten Interrupt vergangen ist
  if (currentTime - lastInterruptTime > debounceDelay) {
    //Mode ändern
    runningMode = !runningMode;
    modeChanged = true;
    //Zeitstempel aktualisieren
    lastInterruptTime = currentTime;
  }
}

void setup() {
  // Erst mal alle LED'S initialisieren
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Dann den Button initialisieren
  pinMode(BUTTON, INPUT_PULLUP);

  // Interrupt
  attachInterrupt(digitalPinToInterrupt(BUTTON), buttonPressed, FALLING);

  // Alle LED's ausschalten
  for (int i = 0; i < numLedPins; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}



int i = 0;
void loop() {
  // Variante 1
  /*
  while(digitalRead(BUTTON) == HIGH) {
    digitalWrite(ledPins[i], LOW);
    delay(2);
    digitalWrite(ledPins[i], HIGH);
    delay(60); // delay kann keine long int
    delayMicroseconds(5); // wir hauen noch die 0,5 Millisekunden dran
    if (i >= numLedPins) {
      i = 0;
    } else {
      i++;
    }
  }*/

  // Variante 2 (Interrupt implementiert mit Button press)
  /*
  if (digitalRead(BUTTON) == HIGH) {
    // damit die äußeren LED'S direkt nach dem loslassen ausgehen
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[numLedPins-1], HIGH);

    // Rechnung
    digitalWrite(ledPins[currentLED], LOW);
    delay(2);
    digitalWrite(ledPins[currentLED], HIGH);
    delay(60); // delay kann keine long int
    delayMicroseconds(5);
    currentLED++;
  } else {
      for (i = 0; i < numLedPins; i++) {
        if (i == 0 || i == numLedPins-1) {
          digitalWrite(ledPins[i], LOW);
        } else {
          digitalWrite(ledPins[i], HIGH);
        }
      }
      currentLED = 0;
  }
  
  if (currentLED >= numLedPins) {
    currentLED = 0;
  }*/

  //Variante 3 (Interrupt implementiert mit Button toggle)

  // Prüfen ob der Modus geändert wurde
  if (modeChanged) {
    modeChanged = false;  // Mode zurücksetzen
    
    if (!runningMode) {
      // Wenn gestoppt, alle LEDs ausschalten außer den äußeren
      for (int i = 0; i < numLedPins; i++) {
        if (i == 0 || i == numLedPins-1) {
          digitalWrite(ledPins[i], LOW);  // Äußere LEDs an
        } else {
          digitalWrite(ledPins[i], HIGH); // Innere LEDs aus
        }
      }
      currentLED = 0;  // Position zurücksetzen
    }
  }

  // Hauptlogik nur ausführen wenn runningMode aktiv ist
  if (runningMode) {
    // Damit die äußeren LEDs direkt nach dem Start ausgehen
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[numLedPins-1], HIGH);

    // Laufende LED-Animation
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
}
  

