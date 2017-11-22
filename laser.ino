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

  //Seta os servos e as portas
  myServos[0].attach(3);
  myServos[1].attach(4);
  myServos[2].attach(5);
  myServos[3].attach(6);

  //Coloca todos os servos em 30 graus
  myServos[0].write(30);
  myServos[1].write(30);
  myServos[2].write(30);
  myServos[3].write(30);

  pinMode(btnPin, INPUT_PULLUP);
  randomSeed(analogRead(0));

  //Chama a função de aleatorio
  GerarAlvosAleatorios();

  //Printa a ordem dos servos no inicio
  //myServos[primeiroAlvo].write(90);
  //Serial.println(primeiroAlvo);
  //Serial.println(segundoAlvo);
  //Serial.println(terceiroAlvo);
  //Serial.println(quartoAlvo);
}
void loop(){

  //Serial.println(sensorValues[quartoAlvo]);
  //Pega os valores dos sensores LDR
  sensorValues[0] = analogRead(A0);  
  sensorValues[1] = analogRead(A1);
  sensorValues[2] = analogRead(A2);
  sensorValues[3] = analogRead(A3);

  //Verifica se o valor do sensor do primeiro alvo é maior que 300
  if(sensorValues[primeiroAlvo] >= 300 && myServos[primeiroAlvo].read() == 90){
    myServos[primeiroAlvo].write(0);
    myServos[segundoAlvo].write(90);
    //Serial.println(myServos[segundoAlvo].read());
    Serial.println("Acertou o primeiro alvo");
  }
  else if(sensorValues[segundoAlvo] >= 300 && myServos[segundoAlvo].read() == 90){
    myServos[segundoAlvo].write(0);
    myServos[terceiroAlvo].write(90);
    Serial.println("Acertou o segundo alvo");
  }
  else if(sensorValues[terceiroAlvo] >= 300 && myServos[terceiroAlvo].read() == 90){
    myServos[terceiroAlvo].write(0);
    myServos[quartoAlvo].write(90);
    Serial.println("Acertou o terceiro alvo");
  }
  else if(sensorValues[quartoAlvo] >= 300 && myServos[quartoAlvo].read() == 90) {
    myServos[quartoAlvo].write(0);
    GerarAlvosAleatorios();
    //Chama a função de aleatorio 
    Serial.println("Acertou o quarto alvo");
    
    //myServos[primeiroAlvo].write(180);
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

  //Manda o primeiro alvo levantar
  myServos[primeiroAlvo].write(90);
}
