#include <SoftwareSerial.h>
SoftwareSerial BT(10, 11);

void setup(){
  Serial.Begin(9600);
  BT.begin(38400);
}

void loop(){
  //Devuelve verdadero cuando hay datos disponibles desde el módulo
  //Unicamente se entra en la sentencia cuando hay datos disponibles desde el módulo
  if (BT.available()){
    // BT.read() lee el dato que se encuentra en el modulo
    Serial.write(BT.read());
  }

  //Proceso inverso al anterior
  //Detecta cuando hay información en el monitor serial y lo puedes denviar al módulo
  if (Serial.available()){
    //Serial.read() es el dato dentro del monitor serial
    BT.write(Serial.read());

  }
}