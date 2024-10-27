#include "lib.h"

void gerar_crescente(int arr[], int size){
  srand(time(NULL));

  arr[0] = rand() % 100;
  for (int i = 1; i < size; i++){
    arr[i] = arr[i - 1] + (rand() % 9);
  }
}

void gerar_aleatorio(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    arr[i] = rand() % size;
  }
}

void gerar_decrescente(int arr[], int size){
  arr[0] = 1000000;//INT_MAX
  for (int i = 1; i < size; i++){
    arr[i] = arr[i - 1] - 1;
  }
}