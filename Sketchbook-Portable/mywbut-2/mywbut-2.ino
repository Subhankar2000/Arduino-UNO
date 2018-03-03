void setup() {
   // put your setup code here, to run once:
    Serial.begin(9600) ;
}

void loop() {
  // put your main code here, to run repeatedly:
  int a = analogRead(A0) ;
  Serial.print("Value at A0 : ") ;
  Serial.print(a) ;
  Serial.println() ;
  delay( 2000 ) ;
  
}
