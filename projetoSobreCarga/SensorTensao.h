#ifndef SENSORTENSAO_H
#define SENSORTENSAO_H
#include <Arduino.h>

class SensorTensao {
  private:
    int pinoLed;      // Onde o LED está conectado
    float limiteT;    // Tensão limite para acender (ex: 127V ou 220V)

  public:
    // Configura o pino e o limite de alerta
    void iniciar(int pino, float limite);
    
    float lerValor();
    
    // Liga o LED se a tensão for alta
    void verificarAlerta(float tensaoAtual); 
};

#endif