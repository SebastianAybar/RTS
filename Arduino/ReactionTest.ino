
const int BUTTON1 = 2;
const int BUTTON2 = 3;

void setup() {
    // Initialisiere serielle Verbindung
  Serial.begin(9600);
  // Abfragen ob Serial available

  // Dann den Button initialisieren
  pinMode(BUTTON1, INPUT_PULLUP);
  pinMode(BUTTON2, INPUT_PULLUP);


  Serial.println("Hello");
}  



void loop() {
  // Warte, bis Button 1 gedrückt wird
  Serial.println("Press Button 1 to start.");
  while (digitalRead(BUTTON1) == HIGH) {
    // Warten
  }
  // Zeitstempel
  unsigned long time_1 = micros();

  // Warte, bis Button 2 gedrückt wird
  Serial.println("Press Button 2 to start.");
  while (digitalRead(BUTTON1) == HIGH) {
    // Warten
  }
  // Zeitstempel
  unsigned long time_2 = micros();

  // Berechne Differenz
  unsigned long diffMicros = time_2 - time_1;
  float diffSeconds = diffMicros / 1000000.0;

    // Gib Ergebnisse aus
  Serial.print("time1: ");
  Serial.print(time_1);
  Serial.println(" microseconds");

  Serial.print("time2: ");
  Serial.print(time_2);
  Serial.println(" microseconds");

  Serial.print("Difference: ");
  Serial.print(diffMicros);
  Serial.println(" microseconds");

  Serial.print("Difference: ");
  Serial.print(diffSeconds, 6); // 6 Nachkommastellen
  Serial.println(" seconds");

  // Warten, damit loop nicht direkt nochmal loslegt
  while (true) {
    // Halte Programm an
  }
}
