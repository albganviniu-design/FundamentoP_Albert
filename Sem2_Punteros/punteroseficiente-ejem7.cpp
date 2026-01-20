#include <iostream>
using namespace std;

// Pasar gran vector por puntero evita copiarlo
// En este caso no se copia, pues los Arreglos DECAEN A PUNTEROS 
void imprimir(int* arr, int n) // <> (int arr[], int n)
{
    for(int i=0;i<n;i++)
    cout << arr[i] << " ";
    cout << endl;
}

int main() 
{

    int v[1000] = {0};
    imprimir(v, 1000);

    return 0;
}