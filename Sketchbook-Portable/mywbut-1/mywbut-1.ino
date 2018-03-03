// Declaration to be done outside ( if needed )


void setup() {
  // put your setup code here, to run once:
  pinMode ( 13, OUTPUT ) ;
  // initialize pins 

}

void loop() {
//   put your main code here, to run repeatedly:
  digitalWrite ( 13 , HIGH ) ;
  delay(50) ;
  digitalWrite( 13 , LOW  ) ;
  delay ( 100 ) ;
  
}
