#include <iostream>
using namespace std;

int costoMaximo(int arr[], int n, int pos, int nivel)
{
    for (int k = 0; k < nivel; k++) 
    {
        cout << "    ";
    }

    cout << "-> pos = " << pos << endl;

    // Caso base
    if (pos == n)
    {
        for (int k = 0; k < nivel; k++) cout << "    ";
        cout << "<- retorna 0 (Base)" << endl;
        return 0;
    }

    int producto = arr[pos];
    
    int maximo = producto + costoMaximo(arr, n, pos + 1, nivel + 1);

    for (int i = pos + 1; i < n; i++)
    {
        producto = producto * arr[i];
        
        int costoRestante = costoMaximo(arr, n, i + 1, nivel + 1);

        if (producto + costoRestante > maximo)
        {
            maximo = producto + costoRestante;
        }
    }

    for (int k = 0; k < nivel; k++) 
    {
        cout << "    ";
    }
    cout << "<- retorna " << maximo << " desde pos = " << pos << endl;

    return maximo;
}

int main()
{
    int arr[] = {2, 1, 3};
    int n = 3;

    cout << "\nArreglo: {2, 1, 3}" << endl;
    cout << "---------------------------------" << endl;

    int resultado = costoMaximo(arr, n, 0, 0);

    cout << "---------------------------------" << endl;
    cout << "Costo maximo: " << resultado << endl;

    return 0;
}