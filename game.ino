#include <Servo.h>
Servo myServo;
Servo myServo2;
const int sensorLdr = A0;
const int sensorLdr1 = A1;
int sensorValue = 0;
int sensorValue2 = 0;

void setup(){
	Serial.begin(9600);
	Serial.println("Iniciando o game!!");
	myServo.attach(9);
	myServo2.attach(8);  
	myServo.write(0);
	myServo2.write(0);    
}

void loop(){
	sensorValue = analogRead(sensorLdr);
	sensorValue2 = analogRead(sensorLdr1);

	if(sensorValue >= 800){
		Serial.println("Acertou o primeiro!!");
		myServo.write(180);  
	}
	else{
		myServo.write(0);
	}

	if(sensorValue2 >= 800){
		Serial.println("Acertou o segundo!!");
		myServo2.write(180);  
	}
	else{
		myServo2.write(0);
	}
}