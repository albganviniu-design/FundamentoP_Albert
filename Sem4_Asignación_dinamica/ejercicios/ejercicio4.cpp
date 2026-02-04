#include<iostream>
#include<climits> // INT_MAX
using namespace std;

int costoMinimo(int arr[], int n, int pos)
{
    // Caso base
    if (pos == n)
    {
        return 0;
    }

    // Caso recursivo
    int min = INT_MAX;
    int producto = 1;

    for (int i = pos; i < n; i++)
    {
        producto *= arr[i];

        // Hacer las llamadas resursivas

        
    }
    


    
}


// Graficar el arbol de llamadas recursivas
// para [1, 2, 3]
int main()
{

    return 0;
}

/*
Dado un arreglo unidimensional A de n (máximo 15) números enteros positivos. Se desea dividir el arreglo en segmentos contiguos, cumpliendo las siguientes condiciones:

Cada segmento debe contener al menos un elemento.

El valor de un segmento se define como el producto de todos sus elementos.

El costo total de una segmentación es la suma de los valores de todos los segmentos.

Implementar una función recursiva para determinar el costo mínimo posible que se puede obtener al segmentar el arreglo.
*/