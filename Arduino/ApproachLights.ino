const int ledPins[] = {5, 6, 7, 8, 9, 10, 11, 12};
const int numLedPins = 8;
int currentLED = 0;
#define BUTTON 2


void setup() {
  // Erst mal alle LED'S initialisieren
  for (int i = 0; i < numLedPins; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  // Dann den Button initialisieren
  pinMode(BUTTON, INPUT_PULLUP);

  // Alle LED's ausschalten
  for (int i = 0; i < numLedPins; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
}



int i = 0;
void loop() {
  // Variante 1
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
  }

  // Variante 2
  /*if (digitalRead(BUTTON) == HIGH) {
    digitalWrite(ledPins[currentLED], LOW);
    delay(2);
    digitalWrite(ledPins[currentLED], HIGH);
    delay(60); // delay kann keine long int
    delayMicroseconds(5);
    currentLED++;
  }
  
  if (currentLED >= numLedPins) {
    currentLED = 0;
  }*/
  
}
