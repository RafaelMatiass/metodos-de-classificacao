#include "metodos.c"
#include "lib_impl.c"
#define SIZE 100

int main() {
  int vetor[SIZE];

  gerar_aleatorio(vetor, SIZE);

  for(int i = 0; i < SIZE; i++){
    printf("%6d ", vetor[i]);
  }

  printf("\n\n");
   printf("Metodos de classificação: \n");
  // gerar_aleatorio(vetor, SIZE);
  // gerar_decrescente(vetor, SIZE);
  bubble_sort(vetor, SIZE);

  for(int i = 0; i < 100; i++){
    printf("%6d ", vetor[i]);
  }

  return 0;
}