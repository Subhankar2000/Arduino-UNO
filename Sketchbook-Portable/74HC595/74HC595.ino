 int latchPin = 4; // pis connected to shift registors
int clockPin = 5;
int dataPin = 3;
int pins [8] = {6, 7, 8, 9, 10, 11, 12, 13}; // common cathode pins
byte A[8] = {   B00000000, // Letters are defined
                B00011000,// you can create your own
                B00100100,
                B01000010,
                B01111110,
                B01000010,
                B01000010,
                B00000000
            };

byte B[8] = {     B00000000,
                  B11111100,
                  B10000010,
                  B10000010,
                  B11111100,
                  B10000010,
                  B10000010,
                  B11111110
            };

byte blank[8] = { B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000,
                  B00000000
                };
byte R[8] = {  B00000000,
               B01111000,
               B01000100,
               B01000100,
               B01111000,
               B01010000,
               B01001000,
               B01000100
            };


void setup() {
  Serial.begin(9600); // Serial begin
  pinMode(latchPin, OUTPUT); // Pin configuration
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  for (int i = 0; i < 8; i++) { // for loop is used to configure common cathodes
    pinMode(pins[i], OUTPUT);
    digitalWrite(pins[i], HIGH);
  }

}

void loop() {



  for (int k = 0; k < 1000; k++) { // showing each letter for 1 second
    display_char(A);

  }

  for (int k = 0; k < 1000; k++) {
    display_char(B);

  }
  for (int k = 0; k < 1000; k++) {
    display_char(R);

  }

  // add more letters show method here






}
void display_char(byte ch[8]) { // Method do the multiplexing
  for (int j = 0; j < 8; j++) {
    digitalWrite(latchPin, LOW);
    digitalWrite(pins[j], LOW);

    shiftOut(dataPin, clockPin, LSBFIRST, ch[j]);
    digitalWrite(latchPin, HIGH);
    //delay(1);
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, LSBFIRST, B00000000); // to get rid of flicker when
    digitalWrite(latchPin, HIGH);
    digitalWrite(pins[j], HIGH);

  }


}
