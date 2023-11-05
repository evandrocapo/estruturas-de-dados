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

void radixsort(ChaveValor arr[], int tam, ChaveValor output[], int count[]) {
	// Get maximum element
	int max = getMax(arr, tam);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		countingSort(arr, tam, place, output, count);
}

void shellsort(ChaveValor arr[], int n){
	int i, j, h;
	ChaveValor aux;
	for (h = 1; h < n; h = 3 * h + 1); /* calcula o h inicial. */
	while (h > 0) {
		h = (h - 1) / 3; /* atualiza o valor de h. */
		for (i = h; i < n; i++) {
			aux = arr[i];
			j = i;
			/* efetua comparações entre elementos com distância h: */
			while (arr[j - h] .chave < aux.chave) {
				arr[j] = arr[j - h];
				j -= h;
				if (j < h) break;
			}
			arr[j] = aux;
		}
	}
}

void mergeaux(ChaveValor arr[], ChaveValor c[], int i, int m, int f) {
	int z, iv = i, ic = m + 1;
	for (z = i; z <= f; z++) {
		c[z] = arr[z];
	}
	z = i;

	while (iv <= m && ic <= f) {
		if (c[iv].chave >= c[ic].chave) {
			arr[z++] = c[iv++];
		}
		else {
			arr[z++] = c[ic++];
		}
	}

	while (iv <= m) {
		arr[z++] = c[iv++];
	}

	while (ic <= f) {
		arr[z++] = c[ic++];
	}
}

void mergesortaux(ChaveValor arr[], ChaveValor c[], int i, int f) {
	if (i < f) {
		int m = (i + f) / 2;
		mergesortaux(arr, c, i, m);
		mergesortaux(arr, c, m+1, f);
		mergeaux(arr, c, i, m, f);
	}
}

void mergesort(ChaveValor arr[], int n, ChaveValor output[]) {
	mergesortaux(arr, output, 0, n - 1);
}

void preencherVetor(ChaveValor arr[], int tam, int seed) {
	srand(seed);
	for (int i = 0; i < tam; i++) {
		arr[i].chave = rand() % 100;
		arr[i].valor = rand() % 100;
	}
}

