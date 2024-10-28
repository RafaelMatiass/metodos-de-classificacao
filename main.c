#include "metodos.c"
#include "lib_impl.c"
#define SIZE 1000000

// Função para copiar arrays
void copiar_array(int origem[], int destino[], int tamanho) {
  for (int i = 0; i < tamanho; i++) {
    destino[i] = origem[i];
  }
}

int main() {
  int vetor[SIZE];
  int bubble[SIZE], insert[SIZE], selection[SIZE], merge[SIZE], quick[SIZE];

  // gerar_decrescente(vetor, SIZE); // gera array decrescente
   gerar_aleatorio(vetor, SIZE); // gera array aleatorio
  // gerar_crescente(vetor, SIZE); // gera array crescente

  // Copia array e aplica Bubble Sort
  copiar_array(vetor, bubble, SIZE);
  bubble_sort(bubble, SIZE);

  // Copia e aplica Insert Sort
  copiar_array(vetor, insert, SIZE);
  insert_sort(insert, SIZE);

  // Copia e aplica Selection Sort
  copiar_array(vetor, selection, SIZE);
  selection_sort(selection, SIZE);

  // Copia e aplica Merge Sort
  copiar_array(vetor, merge, SIZE);
  merge_sort(merge, 0, SIZE - 1);

  // Copia e aplica Quick Sort
  copiar_array(vetor, quick, SIZE);
  quicksort(quick, 0, SIZE - 1);

  printf("Compilei\n\n");

  return 0;
}
