
#define PIN_LED1 12
#define PIN_LED2 13
#define PIN_LED3 8
#define PIN_LED4 7
char data;





void setup() {
  // put your setup code here, to run once:
 
pinMode(PIN_LED1,OUTPUT);
pinMode(PIN_LED2,OUTPUT);
pinMode(PIN_LED3,OUTPUT);
pinMode(PIN_LED4,OUTPUT);

digitalWrite(PIN_LED1,LOW);
digitalWrite(PIN_LED2,LOW);
digitalWrite(PIN_LED3,LOW);
digitalWrite(PIN_LED4,LOW);
Serial.begin(9600);
   
}

void loop() {
  // put your main code here, to run repeatedly:
 data=Serial.write("0");
 //li bch yaakraha l qt 
}
