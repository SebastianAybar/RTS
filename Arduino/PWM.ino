// ********************************************************************************
// RTS SumSem 2025
// Exercise: PWM
// Name: Sebastian Aybar
// Matr.Number: 1273441
// ********************************************************************************

// Frage:
// Explain why both LEDs are shine in the mid position
// In der Mitte haben beide ca. 2,5V 

const int potPin = A1; // Potentiometer Schleifer
const int pwmPin = 9; // PWM Pin für beide LEDs
const int pwmIn = 2; // digitaler Input

void setup() {
  // Serial.begin(9600);
  Serial.begin(2000000);
  pinMode(pwmPin, OUTPUT);
  pinMode(pwmIn, INPUT);
}

void loop() {
  // int potValue = analogRead(potPin);           // 0 - 1023
  // int pwmValue = map(potValue, 0, 1023, 0, 255); // 0 - 255
  
  // analogWrite(pwmPin, pwmValue);              // PWM Signal ausgeben
  // Serial.print("Potentiometer: ");
  // Serial.print(potValue);
  // Serial.print("   PWM: ");
  // Serial.println(pwmValue);

  // delay(50);

  analogWrite(pwmPin, 10);  // z. B. 50 % PWM
  
  int value = digitalRead(pwmIn);  // 0 oder 1 lesen
  Serial.println(value, DEC);      // im Serial Plotter anzeigen

}
