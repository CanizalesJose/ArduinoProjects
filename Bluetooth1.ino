#include <SoftwareSerial.h>
SoftwareSerial miBT(10, 11);

int R = 3;
int G = 4;
char recibido = 0;

int trigger = 12;
int echo = 13;
long tTime = 0;
float distancia = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println("Serial establecido...");
  miBT.begin(38400);
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);

  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if (miBT.available()){      //Lee BT y envia a Arduino
    recibido = miBT.read();

    if (recibido == 'R'){
      digitalWrite(R, !digitalRead(R));
    }

    if (recibido == 'G'){
      digitalWrite(G, !digitalRead(G));
    }
  }
*/
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);

  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);

  tTime = pulseIn(echo, HIGH);

  distancia = (tTime * 0.0343) / 2;

  delay(1000);
  digitalWrite(trigger, LOW);

  if (Serial.available()){    //Lee Arduino y envía a BT
    miBT.print(distancia);
    miBT.println(" cm");
    Serial.print(distancia);
    Serial.println(" cm");
  }

}
