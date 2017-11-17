#include <Servo.h>
Servo myServos[4];

void setup() {
  Serial.begin(9600);
  myServos[0].attach(3);
  myServos[1].attach(4);
  myServos[2].attach(5);
  myServos[3].attach(6);

  myServos[0].write(30);
  myServos[1].write(90);
  myServos[2].write(90);
  myServos[3].write(90);
}

void loop() {
  Serial.print("A0 ");
  Serial.print(myServos[0].read());
  Serial.print(" A1 ");
  Serial.print(myServos[1].read());
  Serial.print(" A2 ");
  Serial.print(myServos[2].read());
  Serial.print(" A3 ");
  Serial.println(myServos[3].read());

}
