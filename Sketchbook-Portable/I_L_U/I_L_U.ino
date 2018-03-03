/*
  Display "I", "Heart", "U" on a 8 by 8 LED matrix
  Dan McCreary, Feb. 14th, 2014
*/

// You can get an red LED matrix for under $5
// Here is a sample: http://www.amazon.com/Common-Anode-Diameter-Display-Matrix/dp/B00EZBZF5K/ref=pd_sim_sbs_e_1
// we are not using pins 0 and 1 and 13
// Connect pins 1-8 (bottom edge) and pins 9-16 (top edge) on the LED matrix
// to the Arduino digital outputpins 2-12 and Analog pins A0 to A3 as outputs
// remember to use a 220 Ohm resistor between the positive rows and the Arduino

byte rows[8] = { A5, A4, A3, A2, A1, A0 , 2, 3}; // these pins light up each row
byte cols[8] = {4, 5, 6, 7, 8, 9, 10, 11}; // these pins light up each column
int onTime = 1; // Time to keep the LED ON.  1 ms delay on - larger and we get flicker

// a funtion to turn on the pixel at row and col
void draw(int row, int col) {
  // make all the columns high except our row
  for (int i = 0; i <= 7; i++)
    if (i != row)
      digitalWrite(cols[i], HIGH);
  digitalWrite(rows[col], HIGH);
  delay(onTime);
  
  // make all the columns low again except our row
  for (int i = 0; i <= 7; i++)
    if (i != row)
      digitalWrite(cols[i], LOW);
  digitalWrite(rows[col], LOW);
}

// the setup routine runs once when you press reset:
void setup() {
  // initialize all the pin as an outputs
  for (int i = 2; i <= 18; i++)
    pinMode(i, OUTPUT);
}

// the main loop that keeps repeating
void loop() {
  
   // draw the letter "I"
   // the counter of 100 will determine how long the letter "I" is on
   for (int i = 0; i <= 100; i++)
   {
     // top horizontal row
     draw(1, 6);
     draw(2, 6);
     draw(3, 6);
     draw(4, 6);
     draw(5, 6);
     // vertical center column
     draw(3, 6);
     draw(3, 5);
     draw(3, 4);
     draw(3, 3);
     draw(3, 2);
     draw(3, 1);
     // bottom horizontal row 
     draw(1, 0);
     draw(2, 0);
     draw(3, 0);
     draw(4, 0);
     draw(5, 0);
   };
  
  // draw the heart
  for (int i = 0; i <= 100; i++)
     {
     // left heart
     draw(3, 5);
     draw(2, 6);
     draw(1, 6);
     draw(1, 6);
     draw(0, 5);
     draw(0, 4);
     draw(0, 3);
     draw(1, 2);
     draw(2, 1);
     draw(3, 0);
     // right heart
     draw(4, 5);
     draw(5, 6);
     draw(6, 6);
     draw(7, 5);
     draw(7, 4);
     draw(7, 3);
     draw(6, 2);
     draw(5, 1);
     draw(4, 0);
     };
     
     // draw the letter "U"
     for (int i = 0; i <= 100; i++)
     {
         // Left vertical edge
         draw(2, 6);
         draw(2, 5);
         draw(2, 4);
         draw(2, 3);
         draw(2, 2);
         draw(2, 1);
         // bottom edge
         draw(2, 0);
         draw(3, 0);
         draw(4, 0);
         draw(5, 0);
         // right edge
         draw(5, 1);
         draw(5, 2);
         draw(5, 3);
         draw(5, 4);
         draw(5, 5);
         draw(5, 6);
     };
}
