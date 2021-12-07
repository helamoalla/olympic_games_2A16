#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>
char data;
Servo servoMoteur; 
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int LEDS=10;
int capteur=7 ;


int detection = HIGH ;

// the loop function runs over and over again forever

void setup()
{
    // initialize digital pin LED_BUILTIN as an output.
    servoMoteur.attach(2);
  
  pinMode(LEDS, OUTPUT);
 // pinMode(LEDS1, OUTPUT);
  digitalWrite(LEDS,LOW) ;
  //digitalWrite(LEDS1,LOW) ;
  pinMode(capteur, INPUT);
  lcd.begin();                      // initialize the lcd 
  lcd.backlight();
  Serial.begin(9600);
 lcd.print("porte fermer") ;
}

void loop()
{ 
  
  detection=digitalRead(capteur) ;
  if(detection == LOW) { Serial.write("1");}
  if(Serial.available())
  while(Serial.available()>0)
  if(Serial.read()=='o'){
    lcd.clear();
    lcd.print("porte ouverte ");
    delay(800);
    servoMoteur.write(0);
    delay(3000);
    servoMoteur.write(90);
    delay(3000);
     lcd.clear(); 
    lcd.print("porte fermer");
    lcd.clear();
    lcd.print("Spectacle commence");
    delay(1000);
    digitalWrite(LEDS,HIGH) ;
    delay(500);
     digitalWrite(LEDS,LOW) ;
      delay(500);
      digitalWrite(LEDS,HIGH) ;
    delay(500);
     digitalWrite(LEDS,LOW) ;
      
      lcd.clear(); 
    lcd.print("porte fermer");
    }
 
 
 
}
