/* My Own LCD 2x16 */
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 8, 9, 10, 11);

void setup() {
  lcd.begin(16, 2);
  lcd.print("- Good Morning -");
  lcd.setCursor(0,1);
  lcd.print("This is Subhankar Karmakar");
  delay(2);
}

void loop() {
  for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(2);
  }
  
for (int positionCounter = 0; positionCounter < 20; positionCounter++) {
    
    lcd.scrollDisplayLeft(); 
    
    delay(2);
  }
  
  
  delay(100);

}

