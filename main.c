#include "metodos.c"
#include "lib_impl.c"
#define SIZE 100000

int main() {
  int vetor[SIZE];
  int bubble[SIZE];

  gerar_aleatorio(vetor, SIZE);

  for(int i = 0; i < SIZE; i++){
    printf("%6d ", vetor[i]);
  }

  printf("\n\n");
  printf("Metodos de classificação: \n");
  // gerar_aleatorio(vetor, SIZE);
  // gerar_decrescente(vetor, SIZE);

  for(int i = 0; i < 100; i++){
    printf("%6d ", vetor[i]);
  }

  return 0;
}