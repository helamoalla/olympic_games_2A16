#include <Servo.h>
char data;
Servo myservo;      // création de l'objet myservo 
 
int val_M;            // Variable contenant la valeur courante du potentiomètre 
int servo_pin = 9;  // Pin auquel le servo est relié

//le temps que nous donnons au capteur pour calibrer (10-60 secondes selon la fiche technique)
int calibrationTime = 10;

int ledPin = 12;    
int ledPin1 = 8; 
int inputPin = 2;               // Pin détecteur en OUT   / PS: Vcc sur pin 5V et GND sur GND
int pirState = LOW;             // nous commençons, en supposant qu'aucun mouvement n'a été détecté
int val = 0;                    // variable pour lire l'état des broches

void setup() {
  myservo.attach(servo_pin);
  pinMode(ledPin, OUTPUT);      // déclarer la LED comme sortie
  pinMode(ledPin1, OUTPUT); 
  pinMode(inputPin, INPUT);     // déclarer le capteur comme entrée
  Serial.begin(9600);
  myservo.attach(9);
  //myservo.write(11);
  val_M = 100; //position ouverte
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin1, LOW);
  Serial.print("Calibrage du détecteur ");
  for(int i = 0; i < calibrationTime; i++){
    Serial.print(".");
   delay(500);
  }
  Serial.print("\n");
}

void loop(){
 
  myservo.write(11); //attribution l'angle du servo-moteur
  val = digitalRead(inputPin);  // lire la valeur d'entrée
  //Serial.println(val);
  if (Serial.available()){
    
  if (val == HIGH) { // vérifier si l'entrée est haute
      data=Serial.write("0");
    digitalWrite(ledPin, HIGH);// turn  LED ON
    // val_M = 100; //position ouverte 
    //delay(10);
    if (pirState == LOW) {
      Serial.println("Aucune détection");
      //enregistrement de l'état
      //pirState = HIGH;
       data=Serial.read();
    if(data=='1')
    {
      digitalWrite(ledPin,LOW);
      delay(5);
      digitalWrite(ledPin1, HIGH);
       // delay(7000);//alumer led pendant 5secondes
      myservo.write(90);
      delay(2000);
       myservo.write(11);
    
      digitalWrite(ledPin1, LOW);
    }
   } 
  }
  else
  {
    data=Serial.write("1");
    digitalWrite(ledPin, LOW);
  }
  

}
}
