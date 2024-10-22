#include "metodos.c"
#include "lib_impl.c"
#define SIZE 100

// Função para copiar arrays
void copiar_array(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int vetor[SIZE];
    int bubble[SIZE], insert[SIZE], selection[SIZE], merge[SIZE], quick[SIZE];

    
    gerar_aleatorio(vetor, SIZE); // gera array aleatório

    // array original
    printf("Array original:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6d ", vetor[i]);
    }
    printf("\n\n");

    // Copiar array e aplicar Bubble Sort
    copiar_array(vetor, bubble, SIZE);
    bubble_sort(bubble, SIZE);
    printf("Bubble Sort- Compilado");

    printf("Array original:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6d ", vetor[i]);
    }
    printf("\n\n");

    printf("Array Bubble:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6d ", bubble[i]);
    }
    printf("\n\n");

    // Copiar e aplicar Insert Sort
    //copiar_array(vetor, insert, SIZE);
    //insert_sort(insert, SIZE);

    // Copiar e aplicar Selection Sort
    copiar_array(vetor, selection, SIZE);
    selection_sort(selection, SIZE);

     printf("Array original:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6d ", vetor[i]);
    }
    printf("\n\n");

    printf("Array Selection:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%6d ", selection[i]);
    }
    printf("\n\n");

    // Copiar e aplicar Merge Sort
    //copiar_array(vetor, merge, SIZE);
    //merge_sort(merge, SIZE);

    // Copiar e aplicar Quick Sort
    //copiar_array(vetor, quick, SIZE);
    //quick_sort(quick, SIZE);

    return 0;
}
