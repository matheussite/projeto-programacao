#ifndef ANALISEDADOS_H
#define ANALISEDADOS_H
#include <Arduino.h>

class AnaliseDados {
  private:
    // Requisito: Array Puro Encapsulado
    float historico[10]; 
    int indice;

  public:
    AnaliseDados();
    void registrarLeitura(float valor);
    float calcularMedia();
    void exibirRelatorioOrdenado(); // Requisito: Bubble Sort
};

#endif