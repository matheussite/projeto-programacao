#include "AnaliseDados.h"

AnaliseDados::AnaliseDados() {
  indice = 0;
  for (int i = 0; i < 10; i++) historico[i] = 0.0;
}

void AnaliseDados::registrarLeitura(float valor) {
  historico[indice] = valor;
  indice++;
  if (indice >= 10) indice = 0;
}

float AnaliseDados::calcularMedia() {
  float soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += historico[i];
  }
  return soma / 10.0;
}

// --- ALGORITMO DE ORDENAÇÃO (Bubble Sort) ---
void AnaliseDados::exibirRelatorioOrdenado() {
  // 1. Copia o array
  float copia[10];
  for(int i=0; i<10; i++) copia[i] = historico[i];

  // 2. Ordena (Bubble Sort)
  for (int i = 0; i < 10 - 1; i++) {
    for (int j = 0; j < 10 - i - 1; j++) {
      if (copia[j] < copia[j + 1]) { // Decrescente
        float temp = copia[j];
        copia[j] = copia[j + 1];
        copia[j + 1] = temp;
      }
    }
  }
  Serial.print(">> MÉDIA GERAL: ");
  Serial.print(calcularMedia());
  Serial.println(" V");
  Serial.println("=======================================\n");
}
