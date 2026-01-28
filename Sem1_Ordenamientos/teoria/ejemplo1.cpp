#include<iostream>
using namespace std;

void burbuja(int arr[], int n)
{
    for(int i = 0; i < n-1; ++i)
    {
        for (int j = 0; j < n-1-i; ++j)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j + 1]);
            }
            
        }
        
    }
}

int main()
{
    int numeros[] = {5, 3, 8, 4, 2};
    int n = 5;

    burbuja(numeros, n);

    cout << "Arreglo ordenado: ";
    for (int i = 0; i < n; ++i)
    {
        cout << numeros[i] << " ";
    }
    
    return 0;
}