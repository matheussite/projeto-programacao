#include <Arduino.h>
#include "SensorTensao.h"
#include "AnaliseDados.h"

SensorTensao    sensor;
AnaliseDados    analista;

unsigned long tempoEnvio = 0;
unsigned long tempoRelatorio = 0;

// Defina o pino do LED aqui
#define PINO_LED 12 
#define LIMITE_ALERTA 200.0 

void setup() {
  Serial.begin(115200);
  
  // --- INICIA O LED ---
  sensor.iniciar(PINO_LED, LIMITE_ALERTA);
  Serial.println("--- Sistema Iniciado ---");
}

void loop() {
  // A cada 2 segundos, lê e atualiza
  if (millis() - tempoEnvio > 2000) {
    tempoEnvio = millis();

    float leitura = sensor.lerValor();
    
    // 1. O LED reage imediatamente
    sensor.verificarAlerta(leitura);

    // 2. Guarda o dado no histórico
    analista.registrarLeitura(leitura);

    // 3. Calcula a média AGORA (Tempo Real)
    float mediaTempoReal = analista.calcularMedia();

    // 4. Mostra tudo na mesma linha
    Serial.print("Leitura: ");
    Serial.print(leitura);
    Serial.print(" V  |  Média: ");
    Serial.print(mediaTempoReal);
    Serial.println(" V");
  }

  // A cada 10 segundos, gera o relatório completo organizado
  if (millis() - tempoRelatorio > 10000) {
    tempoRelatorio = millis();
    analista.exibirRelatorioOrdenado();
  }
}