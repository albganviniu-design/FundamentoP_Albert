#include <iostream>
using namespace std;

int costoMaximo(int arr[], int n, int pos)
{
    // Caso base
    if (pos == n)
    {
        return 0;
    }

    int producto = arr[pos];
    int maximo = producto + costoMaximo(arr, n, pos + 1);

    for (int i = pos + 1; i < n; i++)
    {
        producto = producto * arr[i];
        int costoRestante = costoMaximo(arr, n, i + 1);

        if (producto + costoRestante > maximo)
        {
            maximo = producto + costoRestante;
        }
    }

    return maximo;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;

    cout << "\nArreglo: {";
    for (int i = 0; i < n-1; i++)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[4] << "}" << endl;
    
    cout << "\nCosto maximo: " << costoMaximo(arr, n, 0) << endl;

    return 0;
}
