/*
 * PIR sensor tester
 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 8, 9, 10, 11); 
int ledPin = 4;
int lcdPin = 5 ;// choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int pirState = LOW;             // we start, assuming no motion detected
int val = 0;                    // variable for reading the pin status
 
void setup() {
  lcd.begin(16, 2);
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
 
  Serial.begin(9600);
}
 
void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, HIGH);  // turn LED ON
    digitalWrite(lcdPin, HIGH);
    if (pirState == LOW) {
      lcd.clear() ;
      lcd.print("Motion detected!");
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    digitalWrite(lcdPin, HIGH);
    if (pirState == HIGH){
      lcd.clear() ;
      lcd.print("Motion ended!");
      // we have just turned of
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}
