#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TAM 100000 //Alterar junto com tamanho do vetor gerado.

void bubble_sort(int colecao[], int tamanho);
void insert_sort(int colecao[], int tamanho);
void merge_sort(int colecao[], int inicio, int fim);
void intercala(int colecao[], int inicio, int fim, int meio);
void quicksort(int x[], int lb, int ub);
void partition(int x[], int lb, int ub, int *j);
void selection_sort(int colecao[], int tamanho);



int comp_quick = 0; 
int trocas_quick = 0; 

int comp_merge = 0; 
int trocas_merge = 0;


// BUBBLE SORT

void bubble_sort(int colecao[], int tamanho){
	clock_t t;
    t = clock(); //armazena tempo

    //double cpu_time_used;  
	int i, j, elemento_auxiliar;
	int trocou = true;
	int comp = 0;
	int trocas = 0;

	for(i=0; i < tamanho && trocou; i++){
		trocou = false;
		//printf("%6d", colecao[i]);
		for(j=0; j < tamanho-(1+i); j++){
			//printf("%6d", colecao[i]);
			comp++;
			if(colecao[j] > colecao[j+1]){
				//printf("%6d", colecao[i]);
				elemento_auxiliar = colecao[j];
				colecao[j] = colecao[j+1];
				colecao[j+1] = elemento_auxiliar;
				trocou = true;
				trocas++;
			}
		}		
	}
	
		
		t = clock() - t; //tempo final - tempo inicial

        printf("\n############## BUBBLE SORT ##############\n");
        printf("Tempo de execucao Bubble Sort: %lf  ms\n", ((double)t)/((CLOCKS_PER_SEC/1000)));
        printf("Quantidade de Comparacoes - Bubble Sort: %d\n", comp);
        printf("Quantidade de Trocas - Bubble Sort: %d\n\n", trocas);
        printf("\n\n");
		
}


// INSERTION SORT
void insert_sort(int colecao[], int tamanho) {
  clock_t t;
  t = clock();
  int i, j, elemento_auxiliar;
  int comp = 0;
  int trocas = 0;

  for(i = 1; i < tamanho; i++) {
    elemento_auxiliar = colecao[i];
    j = i - 1;
    while(j >= 0 && colecao[j] > elemento_auxiliar) {
      comp++;
      colecao[j+1] = colecao[j];
      j--;
      trocas++;
    }
    colecao[j+1] = elemento_auxiliar;
    if(j >= 0){
      comp++;
    } 
  }

 
  t = clock() - t;
  printf("############## INSERTION SORT ##############\n");
  printf("Tempo de execucao Insertion Sort: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
  printf("Quantidade de Comparacoes - Insertion Sort: %d\n", comp);
  printf("Quantidade de Trocas - Insertion Sort: %d\n\n", trocas);
  printf("\n\n");
}

// MERGE SORT
void merge_sort(int colecao[], int inicio, int fim) {
  static clock_t t; 
  if (inicio == 0 && fim != 0) { 
    t = clock();
  }

  if (inicio < fim) {
    int meio = (inicio + fim) / 2;
    merge_sort(colecao, inicio, meio);
    merge_sort(colecao, meio + 1, fim);
    intercala(colecao, inicio, fim, meio);
  }

  if (inicio == 0 && fim == TAM-1) { 
   
    t = clock() - t;
    printf("Tempo de execucao Merge Sort: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));
    printf("\n\n");
  }
}

void intercala(int colecao[], int inicio, int fim, int meio) {
  int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
  int tamanho = fim - inicio + 1;
  int arquivo_aux[tamanho];


  inicio_arquivo1 = inicio;
  inicio_arquivo2 = meio + 1;
  pos_livre = 0;

  while (inicio_arquivo1 <= meio && inicio_arquivo2 <= fim) {
    comp_merge++;
    if (colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]) {
      arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
      inicio_arquivo1++;
    } else {
      arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
      inicio_arquivo2++;
      trocas_merge++; 
    }
    pos_livre++;
  }

  while (inicio_arquivo1 <= meio) {
    arquivo_aux[pos_livre++] = colecao[inicio_arquivo1++];
  }

  while (inicio_arquivo2 <= fim) {
    arquivo_aux[pos_livre++] = colecao[inicio_arquivo2++];
  }

  for (i = 0; i < tamanho; i++) {
    colecao[inicio + i] = arquivo_aux[i];
  }

   if (inicio == 0 && fim == TAM-1) { 
    printf("############## MERGE SORT ##############\n");
    printf("Quantidade de Comparacoes - Merge Sort: %d\n", comp_merge);
    printf("Quantidade de Trocas - Merge Sort: %d\n", trocas_merge);
  }
  
}


// QUICK SORT
void quicksort(int x[], int lb, int ub) {
  clock_t t; 
  t = clock(); 
  

  int j = -1;
  if (lb >= ub) {
    return;
  }

  partition(x, lb, ub, &j);
  quicksort(x, lb, j - 1);
  quicksort(x, j + 1, ub);

   if (lb == 0 && ub == TAM - 1) { // Final

      t = clock() - t;
      //printf("Executando Quick Sort: lb = %d, ub = %d\n", lb, ub); 
      printf("############## QUICK SORT ##############\n");
      printf("Tempo de execucao Quick Sort: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
      printf("Quantidade de Comparacoes - Quick Sort: %d\n", comp_quick);
      printf("Quantidade de Trocas - Quick Sort: %d\n\n", trocas_quick);
    }
}

void partition(int x[], int lb, int ub, int *j) {
  int a, down, up, temp;
  a = x[lb];
  up = ub;
  down = lb;

  while (down < up) {
    while (x[down] <= a && down < ub) {
      down++;
      comp_quick++; 
    }
    while (x[up] > a) {
      up--;
      comp_quick++; 
    }
    if (down < up) {
      temp = x[down];
      x[down] = x[up];
      x[up] = temp;
      trocas_quick++; 
    }
  }
  x[lb] = x[up];
  x[up] = a;
  *j = up;
}



// SELECTION SORT
void selection_sort(int colecao[], int tamanho) {
  clock_t t;
  t = clock();
  
  int i, j, pos_menor, elemento_auxiliar;
  int comp = 0;
  int trocas = 0;

  for(i = 0; i < tamanho; i++) {
    pos_menor = i;
    for(j = i + 1; j < tamanho; j++) {
      comp++;
      if(colecao[j] < colecao[pos_menor]) {
        pos_menor = j;
      }
    }
    if (pos_menor != i) {
      elemento_auxiliar = colecao[i];
      colecao[i] = colecao[pos_menor];
      colecao[pos_menor] = elemento_auxiliar;
      trocas++;
    }
  }

  t = clock() - t;
  printf("############## SELECTION SORT ##############\n");
  printf("Tempo de execucao Selection Sort: %lf ms\n", ((double)t) / (CLOCKS_PER_SEC / 1000));
  printf("Quantidade de Comparacoes - Selection Sort: %d\n", comp);
  printf("Quantidade de Trocas - Selection Sort: %d\n\n", trocas);
  printf("\n\n");
}