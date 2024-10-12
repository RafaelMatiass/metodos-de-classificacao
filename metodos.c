#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// #define TAM 10

void bubble_sort(int[], int);

void bubble_sort(int colecao[], int tamanho){
	clock_t t;
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

		t = clock(); //armazena tempo
		

		t = clock() - t; //tempo final - tempo inicial

		//imprime o tempo na tela
		printf("Tempo de execucao Bubble Sort: %lf\n\n", ((double)t)/((CLOCKS_PER_SEC/1000)));

		printf("Quantidade de Comparações - Bubble Sort: %d\n\n", comp);

		printf("Quantidade de Trocas - Bubble Sort: %d\n\n", trocas);
}

// void insert_sort(int[], int);

// void insert_sort(int colecao[], int tamanho){
	
// 	int i, j, elemento_auxiliar;
// 	for(i=1; i<tamanho; i++){
// 		elemento_auxiliar = colecao[i];
		
// 		for(j = i-1; j >= 0 && colecao[j] > elemento_auxiliar; j--){
// 			colecao[j+1] = colecao[j];
// 		}
// 		colecao[j+1] = elemento_auxiliar;
// 	}
// }

// void merge(int[], int, int);
// void intercala(int[], int, int, int);

// void merge(int colecao[], int inicio, int fim){
// 	int meio;
// 	if(inicio < fim){
// 		meio = (inicio + fim) / 2;
// 		merge(colecao, inicio, meio);
// 		merge(colecao, meio+1, fim);
// 		intercala(colecao, inicio, fim, meio);
// 	}
// }

// void intercala(int colecao[], int inicio, int fim, int meio){
// 	int pos_livre, inicio_arquivo1, inicio_arquivo2, i;
// 	int arquivo_aux[TAM];
// 	inicio_arquivo1 = inicio;
// 	inicio_arquivo2 = meio + 1;
// 	pos_livre = inicio;
// 	while(inicio_arquivo1 <= meio && inicio_arquivo2 <= fim){
// 		if(colecao[inicio_arquivo1] <= colecao[inicio_arquivo2]){
// 			arquivo_aux[pos_livre] = colecao[inicio_arquivo1];
// 			inicio_arquivo1 += 1;
// 		} 
// 		else
// 		{
// 			arquivo_aux[pos_livre] = colecao[inicio_arquivo2];
// 			inicio_arquivo2 += 1;
// 		}
// 		pos_livre += 1;
// 	}
// 	for(i=inicio_arquivo1; i<= meio; i++, pos_livre++){
// 		arquivo_aux[pos_livre] = colecao[i];
// 	}
// 	for(i=inicio_arquivo2; i<= fim; i++, pos_livre++){
// 		arquivo_aux[pos_livre] = colecao[i];
// 	}
// 	for(i=inicio; i <= fim; i++){
// 		colecao[i] = arquivo_aux[i];
// 	}
// }

// void quicksort(int x[], int lb, int ub);
// void partition(int x[], int lb, int ub, int *j);

// void quicksort(int x[], int lb, int ub){

//   int j = -1;

//   if(lb >= ub)
//     return;                     

//   partition(x, lb, ub, &j);       

//   quicksort(x, lb, j-1);         

//   quicksort(x, j+1, ub);          
// }


// void partition(int x[], int lb, int ub, int *j){

//   int a, down, up, temp;

//   a = x[lb];

//   up = ub;
//   down = lb;

//   while(down < up){
//     while(x[down] <= a && down < ub){
//       down++;
//     }
//     while(x[up] > a){
//       up--;
//     }
//     if(down < up){
//       temp = x[down];
//       x[down] = x[up];
//       x[up] = temp;
//     }
//   }
//   x[lb] = x[up];
//   x[up] = a;
//   *j = up;
// }

// void selection_sort(int[], int);

// int main(int argc, char const *argv[]){
// 	int arquivo[TAM];
	
// 	carrega_vetor_aleatorio(arquivo, TAM, 3);
// 	imprime_vetor(arquivo, TAM);
// 	selection_sort(arquivo, TAM);
// 	imprime_vetor(arquivo, TAM);
	
//     return 0;
// }

// void selection_sort(int colecao[], int tamanho){
// 	int i, j, pos_menor, elemento_auxiliar;
	
// 	for(i=0; i<tamanho; i++){
// 		pos_menor = i;
// 		for(j=i+1; j<tamanho; j++){
// 			if(colecao[j] < colecao[pos_menor]){
// 				pos_menor = j;
// 			}
// 		}
// 		elemento_auxiliar = colecao[i];
// 		colecao[i] = colecao[pos_menor];
// 		colecao[pos_menor] = elemento_auxiliar;
// 	}
// }