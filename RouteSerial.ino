/*
  Radioenge Equipamentos de Telecomunicação
  
  Script para rotear a serial COM do Arduino para a serial de comandos.
  Usado para a comunicação entre o computador e o EndDevice através do Arduino.
  Ambas interfaces operando a 9600 bps.
  Válido para Arduino Uno.
*/
#include <SoftwareSerial.h>

SoftwareSerial radioSerialComandos(7, 6, false);  // Commands Serial
//SoftwareSerial radioSerialComandos(8, 9, false);  // Transparent Serial

void setup() {
  Serial.begin(9600);
  radioSerialComandos.begin(9600);
}

void loop() {
  while (radioSerialComandos.available() > 0) {
    Serial.write(radioSerialComandos.read());
  }
  
  while (Serial.available() > 0) {
    radioSerialComandos.write(Serial.read());
  }
}
