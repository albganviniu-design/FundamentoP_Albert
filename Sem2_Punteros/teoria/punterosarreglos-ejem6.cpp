#include <iostream>
using namespace std;

//void imprimir(int arr[], int n);

/*
Ejercicio 1: Completar la siguiente funcion 
usando exclusivamente punteros para manipular el arreglo
*/

void duplicarArreglo(int *ptr, int n)
{
    for (int i=0; i<n; i++) 
    {
        cout << (*(ptr+i))*2 << " ";
    }
    cout << endl;
}

int main() 
{

    int arr[5] = {1,2,3,4,5};
    int* p = arr; // arr decae a puntero al primer elemento

    for (int i=0; i<5; i++) 
    {
        cout << *(p+i) << " ";
    }
    cout << endl << endl;

    duplicarArreglo(p, 5);


    return 0;
}