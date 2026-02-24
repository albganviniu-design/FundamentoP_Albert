#include <iostream>
using namespace std;


void imprimir(int arr[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void seleccion(int arr[], int n) {
    for(int i = 0; i < n -1; ++i) {
        int indMin = i;
        for(int j = i + 1; j < n; ++j) {
            if(arr[j] < arr[indMin]) {
                indMin = j; 
            }
        }

        swap(arr[i],arr[indMin]);
    }
}

int main(){
    int arr[] = {2,3,5,4,3,6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nArreglo original: " << endl;
    imprimir(arr,n);

    seleccion(arr,n);

    cout << "\nArreglo ordenado" << endl;
    imprimir(arr,n);


    return 0;
}