#include "ordenacao.h";
#include <stdio.h>;
#include <stdlib.h>;

void bubblesort(ChaveValor arr[], int tam) {
	for (int i = 0; i < tam; i++) {
		for (int j = 0; j < tam-1; j++) {
			if (arr[j].chave < arr[j + 1].chave) {
				ChaveValor aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

void insertionsort(ChaveValor arr[], int tam) {
	for (int i = 1; i < tam; i++) {
		for (int j = i; j > 0; j--) {
			if (arr[j - 1].chave < arr[j].chave) {
				ChaveValor aux = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = aux;
			}
		}
	}
}

// Function to get the largest element from an array
int getMax(ChaveValor arr[], int n) {
	int max = arr[0].chave;
	for (int i = 1; i < n; i++)
		if (arr[i].chave > max)
			max = arr[i].chave;
	return max;
}

// Using counting sort to sort the elements in the basis of significant places
void countingSort(ChaveValor arr[], int tam, int place, ChaveValor output[], int count[]) {
	int max = (arr[0].chave / place) % 10;

	for (int i = 1; i < tam; i++) {
		if (((arr[i].chave / place) % 10) > max)
			max = arr[i].chave;
	}

	for (int i = 0; i < max; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < tam; i++) {
		count[9 - ((arr[i].chave / place) % 10)]++; // 9 - pos
	}
		
	// Calculate cumulative count
	for (int i = 1; i < 10; i++) {
		count[i] += count[i - 1];
	}

	// Place the elements in sorted order
	for (int i = tam - 1; i >= 0; i--) {
		output[count[9 - (arr[i].chave / place) % 10] - 1] = arr[i]; // 9 - pos
		count[9 - (arr[i].chave / place) % 10]--; // 9 - pos
	}

	for (int i = 0; i < tam; i++)
		arr[i] = output[i];
}

//output e count devem ser [tam + 1]
void radixsort(ChaveValor arr[], int tam, ChaveValor output[], int count[]) {
	// Get maximum element
	int max = getMax(arr, tam);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(arr, tam, place, output, count);
}

void preencherVetor(ChaveValor arr[], int tam, int seed) {
	srand(seed);
	for (int i = 0; i < tam; i++) {
		arr[i].chave = rand() % 100;
		arr[i].valor = rand() % 100;
	}
}

