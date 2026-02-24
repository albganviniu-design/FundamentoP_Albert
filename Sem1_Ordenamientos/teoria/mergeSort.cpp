#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) {
    // tamaÃ±os de los subarreglos
    int n1 = m - l + 1;
    int n2 =  r - m;
    
    // Arreglos auxiares
    int L[100], R[100];

    // Copiamos datos del subarreglo izquierdo
    for(int i = 0; i < n1; ++i) {
        L[i] = arr[l + i];
    }

    // Copiamos datos del subarreglo derecho
    for(int j = 0; j < n2; ++j) {
        R[j] = arr[m + 1 + j];
    } 

    int i = 0, j = 0, k = l;

    while (i <n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Colocando los elementos restantes de L
    while(i <n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Colocando los elementos restantes de R
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}


void mergeSort(int arr[], int l, int r) {
    
    // Caso base: arreglos de tamanio 1

    if(l < r){ 
        int m = (l + r)/2;

        // ordeno la primera mitad
        mergeSort(arr,l,m);


        //ordeno la segunda mitad
        mergeSort(arr, m+1, r);

        merge(arr, l, m ,r);
    }
}

void imprimir(int arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    int arr[] = {2,3,5,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArreglo original: " << endl;
    imprimir(arr,n);

    mergeSort(arr,0, n-1);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);


    return 0;
}