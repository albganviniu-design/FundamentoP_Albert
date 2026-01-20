#include<iostream>
using namespace std;

void seleccion(int arr[], int n)
{
    for(int i = 0; i < n - 1; ++i)
    {
        int indMin = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[indMin])
            {
                indMin = j;
            }
            
        }
        swap(arr[i], arr[indMin]);
    }
}

int main()
{
    int numeros[] = {5, 3, 8, 4, 2};
    int n = 5;

    seleccion(numeros, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; ++i)
    {
        cout << numeros[i] << " ";
    }

    return 0;
}