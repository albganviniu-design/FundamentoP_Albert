#include <iostream>
using namespace std;

/*
Colocar el pivote en su posicion correcta
y reorganiza el arreglo (menores a la izquierda, mayores a la derecha)
*/
int partition(int arr[], int low, int high) {
	// Elegimos el ultimo elemento como pivote
	int pivot = arr[high];
	// indice del menor elemento
	int i = low - 1;

	for (int j = low; j < high; j++) {
		// Si el elemento actual es menor o igual al pivote
		if (arr[j] <= pivot) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	// Colocamos el pivote en su posicion final
	swap(arr[i + 1], arr[high]);

	return i + 1;
}

/*
Implementacion recursiva de Quick Sort
*/
void quickSort(int arr[], int low, int high) {
	// Caso base: Si tamanio es 1

	if (low < high) {
		// Indice del pivote
		int pi = partition(arr, low, high);

		// Ordenar elementos antes del pivote
		quickSort(arr, low, pi - 1);

		// Ordenar elementos despues del pivote
		quickSort(arr, pi + 1, high);
	}
}

void imprimir(int arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
	int arr[] = {2,3,5,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArreglo original: " << endl;
    imprimir(arr,n);

    quickSort(arr,0, n-1);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);


	return 0;
}