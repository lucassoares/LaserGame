#include <Servo.h>

Servo myServos[4]; //3 4 5 6
const int botaoReset = 2;
const int sensorLdr = A0;
const int sensorLdr1 = A1;
const int sensorLdr2 = A2;
const int sensorLdr3 = A3;
int sensorValue = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;
int sensorValue4 = 0;
int btnVal = 0;

int primeiroAlvo = 0;
int segundoAlvo = 0;
int terceiroAlvo = 0;
int quartoAlvo = 0;


void setup(){
  Serial.begin(9600);
  randomSeed(analogRead(0));
  for(int i = 0; i < 4; i++){
    myServos[i].attach(i+3);
    myServos[i].write(180);
  }
  Zerar();
  GerarAlvosAleatorios();
  Serial.println(primeiroAlvo);
  Serial.println(segundoAlvo);
  Serial.println(terceiroAlvo);
  Serial.println(quartoAlvo);
}

void loop(){
  sensorValue = analogRead(sensorLdr);
  sensorValue2 = analogRead(sensorLdr1);
  sensorValue3 = analogRead(sensorLdr2);
  sensorValue4 = analogRead(sensorLdr3);
  ProcurarTiros();
  btnVal = digitalRead(botaoReset);
  //GerarAlvosAleatorios();

  if(btnVal == HIGH){
    //Zerar();
    GerarAlvosAleatorios();  
  }
}

void Zerar(){
  for(int i = 0; i < 4; i++){
    myServos[i].write(0);
  }
}

bool DetectarTiro(int valueSensor, Servo servo, Servo servo2){
  if(valueSensor >= 300){
    servo.write(180);
    servo2.write(0);
    return true;
  }
  else{
    return false;
  }
}

void ProcurarTiros(){
   if(DetectarTiro(sensorValue, myServos[primeiroAlvo], myServos[segundoAlvo])){
    Serial.println("Entrou no primeiro if");
  }
   if(DetectarTiro(sensorValue2, myServos[segundoAlvo], myServos[terceiroAlvo])){
    Serial.println("Entrou no segundo if");
  }
   if(DetectarTiro(sensorValue3, myServos[terceiroAlvo], myServos[quartoAlvo])){
    Serial.println("Entrou no terceiro if");
  }
   if(DetectarTiro(sensorValue4, myServos[quartoAlvo], myServos[primeiroAlvo])){
    Serial.println("Entrou no quarto if");
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
