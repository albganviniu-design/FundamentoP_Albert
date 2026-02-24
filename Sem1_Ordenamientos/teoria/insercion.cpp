#include <iostream>
using namespace std;


void insercion(int arr[], int n) {
    for (int i = 1; i < n ; ++i) {
        int temp = arr[i];
        int j = i -1;

        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;

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

    insercion(arr,n);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);


    return 0;
}