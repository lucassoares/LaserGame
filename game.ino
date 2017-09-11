#include <Servo.h>
Servo myServo;
Servo myServo2;
Servo myServo3;
Servo myServo4;
const int sensorLdr = A0;
const int sensorLdr1 = A1;
const int sensorLdr2 = A2;
const int sensorLdr3 = A3;
const int botaoReset = 6;
int sensorValue = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int btnVal = 0;

void setup(){
  Serial.begin(9600);
  /*Serial.println("Iniciando o game!!");*/
  myServo.attach(2);
  myServo2.attach(3);
  myServo3.attach(4);
  myServo4.attach(5);
  pinMode(botaoReset,INPUT);
  Zerar();    
}

void loop(){
  sensorValue = analogRead(sensorLdr);
  sensorValue2 = analogRead(sensorLdr1);
  sensorValue3 = analogRead(sensorLdr2);
  sensorValue4 = analogRead(sensorLdr3);
  btnVal = digitalRead(botaoReset);

  if(btnVal == HIGH){
    Zerar();  
  }

Serial.println(sensorValue2);
  DetectarTiro(sensorValue, myServo);
  DetectarTiro(sensorValue2, myServo2);
  DetectarTiro(sensorValue3, myServo3);
  DetectarTiro(sensorValue4, myServo4);
}

void Zerar(){
  myServo.write(0);
  myServo2.write(0);
  myServo3.write(0);
  myServo4.write(0);
}

void DetectarTiro(int valueSensor, Servo servo){
  if(valueSensor >= 300){
    servo.write(180);
  }
}
