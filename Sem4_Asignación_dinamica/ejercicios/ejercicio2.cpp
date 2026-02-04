#include<iostream>
using namespace std;

const int N = 5;

bool esFilaDominante(int (*M)[N], int fila);

int contarColumnasCriticas(int (*M)[N]);

bool esMatrizEscalonada(int (*M)[N]);

int valorNucleo(int (*M)[N]);

int main()
{
    int M[N][N] = {
        {6, 0, 7, 8, 9},
        {15, 0, 0, 5, 6},
        {0, 0, 0, 0, 4},
        {1, 2, 3, 4 ,5},
        {9, 8, 7, 6, 5}
    };

    if (esMatrizEscalonada(M))
    {
        cout << "Es escalonada" << endl;
    }
    else
    {
        cout << "No es escalonada" << endl;
    }

    cout << contarColumnasCriticas(M) << endl;

    return 0;
}


// Una matriz es escalonada si, para cada fila, la posición del primer elemento no nulo aparece en una columna 
// estrictamente mayor que la del primer elemento no nulo de la fila anterior.
bool esMatrizEscalonada(int (*M)[N])
{
    int posAnterior = -1;

    for (int i = 0; i < N; i++)
    {
        int *fila = *(M + i);
        int posActual = -1;

        // Buscar primer elemento distinto de cero en la fila actual
        for (int j = 0; j < N; j++)
        {
            if (*(fila + j) != 0)
            {
                posActual = j;
                break;
            }
        }

        // Si la fila tiene algún número distinto de cero
        if (posActual != -1)
        {
            if (posActual <= posAnterior)
            {
                return false; // No es escalonada
            }
            posAnterior = posActual; // Actualizamos para la siguiente fila
        }
    }

    return true; // Todas las filas cumplen la condición
}


// Una columna se considera crítica si la suma de sus elementos es mayor que la suma de cualquier fila de la matriz.
// La función debe retornar la cantidad total de columnas críticas.
int contarColumnasCriticas(int (*M)[N])
{
    int cont = 0;
    
    for (int j = 0; j < N; j++)
    {
        int  sumaCol = 0;

        for (int i = 0; i < N; i++)
        {
            sumaCol += *(*(M + i)+j);
        }

        bool esCritica = true;

        for (int i = 0; i < N; i++)
        {
            int sumFila = 0;
            int *fila = *(M + i);

            for (int k = 0; k < N; k++)
            {
                sumFila += *(fila + k);
            }

            if (sumaCol <= sumFila)
            {
                esCritica = false;
            }
        }

        if (esCritica)
        {
            cont++;
        }
    }
    return cont;
}

// M[i][j] <> *(*(M + i) + j)

// M[i] <> *(M + i)

/*
Utilice aritmética de punteros e implemente las siguientes funciones:

bool esFilaDominante(int (*M)[N], int fila);

Una fila se considera dominante si cada uno de sus elementos es estrictamente mayor que el elemento 
correspondiente de todas las demás filas en la misma columna.

int contarColumnasCriticas(int (*M)[N]);

Una columna se considera crítica si la suma de sus elementos es mayor que la suma de cualquier fila de la matriz.

La función debe retornar la cantidad total de columnas críticas.

bool esMatrizEscalonada(int (*M)[N]);

Una matriz es escalonada si, para cada fila, la posición del primer elemento no nulo aparece en una columna 
estrictamente mayor que la del primer elemento no nulo de la fila anterior.

int valorNucleo(int (*M)[N]);

El núcleo de la matriz es un elemento que cumple simultáneamente:

Es el máximo de su fila

Es el mínimo de su columna

La función debe retornar el valor del núcleo. Si no existe ningún elemento que cumpla ambas condiciones, retornar -1.
*/