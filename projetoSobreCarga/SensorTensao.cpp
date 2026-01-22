#include "SensorTensao.h"

void SensorTensao::iniciar(int pino, float limite) {
  pinoLed = pino;
  limiteT = limite;
  pinMode(pinoLed, OUTPUT);
  digitalWrite(pinoLed, LOW); // Começa desligado
}

float SensorTensao::lerValor() {
  // Simula tensão
  float valor = 170.0 + (rand() % 200) / 10.0;
  
  // Simula surtos
  if (random(0, 100) > 80) valor = 220.0; // Pico alto

  return valor;
}

void SensorTensao::verificarAlerta(float tensaoAtual) {
  // Se a tensão for maior que o limite (ex: 130V), acende o LED
  if (tensaoAtual > limiteT) {
    digitalWrite(pinoLed, HIGH);
  } else {
    digitalWrite(pinoLed, LOW);
  }
}