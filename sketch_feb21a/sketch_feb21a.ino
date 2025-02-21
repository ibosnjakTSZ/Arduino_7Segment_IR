#include <IRremote.h>

IRrecv IR(12);
int ledPin6 = 6;
int ledPin5 = 5;

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;

void setup(){
  IR.enableIRIn();
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  Serial.begin(9600);

  for (int i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void segmentA(){
  if (IR.decodedIRData.decodedRawData == 0XA15EFF00) {
    digitalWrite(A, LOW);
  }
}
void segmentB(){
  if (IR.decodedIRData.decodedRawData == 0xE718FF00) {
    digitalWrite(B, LOW);
  }
}
void segmentC(){
  if (IR.decodedIRData.decodedRawData == 0xAD52FF00) {
    digitalWrite(C, LOW);
  }
}
void segmentD(){
  if (IR.decodedIRData.decodedRawData == 0xBD42FF00) {
    digitalWrite(D, LOW);
  }
}
void segmentE(){
  if (IR.decodedIRData.decodedRawData == 0xA55AFF00) {
    digitalWrite(E, LOW);
  }
}
void segmentF(){
  if (IR.decodedIRData.decodedRawData == 0XF30CFF00) {
    digitalWrite(F, LOW);
  }
}
void segmentG(){
  if (IR.decodedIRData.decodedRawData == 0xE31CFF00) {
    digitalWrite(G, LOW);
  }
}
void isprazni(){
  if (IR.decodedIRData.decodedRawData == 0xF708FF00) {
    digitalWrite(A, HIGH);
    digitalWrite(B, HIGH);
    digitalWrite(C, HIGH);
    digitalWrite(D, HIGH);
    digitalWrite(E, HIGH);
    digitalWrite(F, HIGH);
    digitalWrite(G, HIGH);
  }
}

void loop(){
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX);
    
    segmentA();
    segmentB();
    segmentC();
    segmentD();
    segmentE();
    segmentF();
    segmentF();
    segmentG();
    isprazni();

    IR.resume();
  }
}