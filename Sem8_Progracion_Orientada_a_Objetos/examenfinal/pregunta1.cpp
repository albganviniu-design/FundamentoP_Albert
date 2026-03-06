#include <iostream>
using namespace std;

int **crearMatriz(int n, int m) // Reserva memoria dinamica para una matriz de enteros de tamaño n x m
{
    int **M = new int *[n]; // reservando memoria para las filas

    for (int i = 0; i < n; i++)
    {
        M[i] = new int[m]; // reservando memoria para las columnas
    }

    return M;
}

void llenarMatriz(int **M, int n, int m) // Llena la matriz con el siguiente patron: M[i][j] = (i + 1) * (j + 1)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M[i][j] = (i + 1) * (j + 1);
        }
    }
}

int *sumaFilas(int **M, int n, int m) // Reserva dinamicamente un vector de tamaño n y almacena la suma de cada fila
{
    int *suma = new int[n];

    for (int i = 0; i < n; i++)
    {
        suma[i] = 0;
        for (int j = 0; j < m; j++)
        {
            suma[i] += M[i][j];
        }
    }

    return suma;
}

void liberarMatriz(int **M, int n) // Libera correctamente toda la memoria resrvada para la matriz
{
    for (int i = 0; i < n; i++)
    {
        delete[] M[i];
    }

    delete[] M;
}

int main()
{
    int n, m;

    cout << "Ingrese el numero de filas: ";
    cin >> n;

    cout << "Ingrese el numero de columnas: ";
    cin >> m;

    int **matriz = crearMatriz(n, m);

    llenarMatriz(matriz, n, m);

    cout << "\nMatriz:\n";
    for (int i = 0; i < n; i++) // mostramos la matriz
    {
        for (int j = 0; j < m; j++)
        {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    int *sumas = sumaFilas(matriz, n, m);

    cout << "\nSuma de cada fila:\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Fila " << i + 1 << ": " << sumas[i] << endl;
    }

    delete[] sumas;
    liberarMatriz(matriz, n);

    return 0;
}