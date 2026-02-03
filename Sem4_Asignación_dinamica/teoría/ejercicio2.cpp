/*
Utilizando una matriz dinámica de tamaño n x m, implementar funciones para

2.1 Reservar memoria dinámica para una matriz

2.2. Llenar con valores aleatorios

2.3. Detectar que filas NO SON VÁLIDAS (Una fila es válida si la suma de sus elementos es par) Detectar que columnas NO SON VALIDAD (Una columna es válida si el máximo elemento de la columna es positivo)

2.4. Construir una nueva matriz dinámica que elimine todas las filas y columnas inválidas
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int ** matrizDinamica(int n, int m)
{
    int** M = new int*[n];
    for (int i = 0; i < n; i++)
    {
        M[i] = new int[m]; // M[i] <> *(M + i)
    }

    return M;
}


void llenarAleatorio(int **M, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            M[i][j] = rand() % 21 - 10; // valores entre -10 y 10
        }
    }
}


bool filaValida(int **M, int fila, int m)
{
    int suma = 0;
    for (int j = 0; j < m; j++)
    {
        suma += M[fila][j];
    }
    return (suma % 2 == 0);
}


bool columnaValida(int **M, int col, int n)
{
    int max = M[0][col];
    for (int i = 1; i < n; i++)
    {
        if (M[i][col] > max)
            max = M[i][col];
    }
    return (max > 0);
}


int **construirMatrizValida(int **M, int n, int m, int &nNuevo, int &mNuevo)
{
    bool *filasOK = new bool[n];
    bool *colsOK = new bool[m];

    nNuevo = 0;
    mNuevo = 0;

    // Detectar filas válidas
    for (int i = 0; i < n; i++)
    {
        filasOK[i] = filaValida(M, i, m);
        if (filasOK[i])
            nNuevo++;
    }

    // Detectar columnas válidas
    for (int j = 0; j < m; j++)
    {
        colsOK[j] = columnaValida(M, j, n);
        if (colsOK[j])
            mNuevo++;
    }

    // Reservar nueva matriz
    int **nueva = matrizDinamica(nNuevo, mNuevo);

    // Copiar datos válidos
    int ii = 0;
    for (int i = 0; i < n; i++)
    {
        if (!filasOK[i])
            continue;

        int jj = 0;
        for (int j = 0; j < m; j++)
        {
            if (colsOK[j])
            {
                nueva[ii][jj] = M[i][j];
                jj++;
            }
        }
        ii++;
    }

    delete[] filasOK;
    delete[] colsOK;

    return nueva;
}

void imprimirMatriz(int **M, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

void liberarMatriz(int **M, int n)
{
    for (int i = 0; i < n; i++)
        delete[] M[i];
    delete[] M;
}

int main()
{
    srand(time(nullptr));

    int n = 4, m = 5;
    int **M = matrizDinamica(n, m);

    llenarAleatorio(M, n, m);

    cout << "Matriz original:\n";
    imprimirMatriz(M, n, m);

    int nNuevo, mNuevo;
    int **M2 = construirMatrizValida(M, n, m, nNuevo, mNuevo);

    cout << "\nMatriz filtrada (válida):\n";
    if (nNuevo > 0 && mNuevo > 0)
        imprimirMatriz(M2, nNuevo, mNuevo);
    else
        cout << "No hay filas o columnas válidas." << endl;

    liberarMatriz(M, n);
    liberarMatriz(M2, nNuevo);

    return 0;
}