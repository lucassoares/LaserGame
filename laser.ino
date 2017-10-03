#include <Servo.h>

Servo myServos[4];
int sensorValues[4];
const int btnPin = 2;


int primeiroAlvo = 0;
int segundoAlvo = 0;
int terceiroAlvo = 0;
int quartoAlvo = 0;


void setup(){
  Serial.begin(9600);
  myServos[0].attach(3);
  myServos[1].attach(4);
  myServos[2].attach(5);
  myServos[4].attach(6);

  myServos[0].write(0);
  myServos[1].write(0);
  myServos[2].write(0);
  myServos[3].write(0);

  pinMode(btnPin, INPUT);
  randomSeed(analogRead(0));

  GerarAlvosAleatorios();
  myServos[primeiroAlvo].write(180);
  Serial.println(primeiroAlvo);
  Serial.println(segundoAlvo);
  Serial.println(terceiroAlvo);
  Serial.println(quartoAlvo);
}
void loop(){
  sensorValues[0] = analogRead(A0);  
  sensorValues[1] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[3] = analogRead(A3);

  if(sensorValues[primeiroAlvo] >= 300 && myServos[primeiroAlvo].read() == 180){
    myServos[primeiroAlvo].write(0);
    myServos[segundoAlvo].write(180);
    Serial.println(myServos[segundoAlvo].read());
    Serial.println("Acertou o primeiro alvo");
  }
  else if(sensorValues[segundoAlvo] >= 300 && myServos[segundoAlvo].read() == 180){
    myServos[segundoAlvo].write(0);
    myServos[terceiroAlvo].write(180);
    Serial.println("Acertou o segundo alvo");
  }
  else if(sensorValues[terceiroAlvo] >= 300 && myServos[terceiroAlvo].read() == 180){
    myServos[terceiroAlvo].write(0);
    myServos[quartoAlvo].write(180);
    Serial.println("Acertou o terceiro alvo");
  }
  else if(sensorValues[quartoAlvo] >= 300 && myServos[quartoAlvo].read() == 180){
    myServos[quartoAlvo].write(0);
    Serial.println("Acertou o quarto alvo");
    GerarAlvosAleatorios();
    myServos[primeiroAlvo].write(180);
  }
}

void GerarAlvosAleatorios(){
  primeiroAlvo = random(0,4);
  segundoAlvo = random(0,4);

  while(primeiroAlvo == segundoAlvo){
    segundoAlvo = random(0,4);
  }

  terceiroAlvo = random(0,4);

  while(terceiroAlvo == segundoAlvo || terceiroAlvo == primeiroAlvo){
     terceiroAlvo = random(0,4);
  }

  quartoAlvo = random(0,4);
  while(quartoAlvo == terceiroAlvo || quartoAlvo == segundoAlvo || quartoAlvo == primeiroAlvo){
    quartoAlvo = random(0,4);
  }
  myServos[primeiroAlvo].write(0);
}
