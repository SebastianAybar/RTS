// ********************************************************************************
// RTS SumSem 2024
// Exercise: Execution Times
// Name: Sebastian Aybar
// ********************************************************************************

int S1 = 2;
int S2 = 3;

void setup() {
Serial.begin(9600);

pinMode(S1, INPUT_PULLUP);
pinMode(S2, INPUT_PULLUP);

// Initial message
Serial.println("Hello, this is a reaction test of your name");
}

void loop() {
// Wartet, bis Button 1 gedrueckt wird
while (digitalRead(S1) == HIGH) {
}

// Misst die Zeit, wann S1 gedrückt wird
unsigned long time1 = micros();

// Wartet, bis Button 2 gedrueckt wird
while (digitalRead(S2) == HIGH) {
}

// Misst die Zeit, wann S2 gedrückt wird
unsigned long time2 = micros();

Serial.print("\nTime1: ");
Serial.print(time1);
Serial.println(" microseconds");

Serial.print("Time2: ");
Serial.print(time2);
Serial.println(" microseconds");

// Schritt 8
unsigned long timeDifference = time2 - time1;
Serial.print("\nTime difference: ");
Serial.print(timeDifference);
Serial.println(" microseconds");

// Schritt 9
float timeDifferenceSeconds = timeDifference / 1000000.0;
Serial.print("Time difference in seconds: ");
Serial.print(timeDifferenceSeconds, 6);
Serial.println(" seconds");

delay(1000);
}
