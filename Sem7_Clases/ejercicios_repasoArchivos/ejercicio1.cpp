#include <iostream>
#include <fstream>
using namespace std;

void burbuja(int arr[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    ifstream archivoEntrada1("entradas/archivo1.txt");

    ifstream archivoEntrada2("entradas/archivo2.txt");

    ofstream archivoSalida("output/nombreM.txt");

    if (!archivoEntrada1)
    {
        cout << "Error, no se pudo abrir archivo1.txt";
        return 1;
    }

    if (!archivoEntrada2)
    {
        cout << "Error, no se pudo abrir archivo2.txt";
        return 1;
    }

    if (!archivoSalida)
    {
        cout << "Error, no se pudo abrir nombreM.txt";
        return 1;
    }

    int datos1, datos2;
    int j = 0;
    int arr[100];

    while (archivoEntrada1 >> datos1)
    {
        arr[j] = datos1;
        j++;
    }

    while (archivoEntrada2 >> datos2)
    {
        arr[j] = datos2;
        j++;
    }

    burbuja(arr, j);

    for (int i = 0; i < j; i++)
    {
        archivoSalida << arr[i] << endl;
    }

    archivoEntrada1.close();
    archivoEntrada2.close();
    archivoSalida.close();

    return 0;
}