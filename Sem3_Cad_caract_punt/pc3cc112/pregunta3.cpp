#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 9;

void intercambiar(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void generarFila(int* fila)
{
    for (int i = 0; i < N; i++)
    {
        *(fila + i) = i + 1;
    }

    for (int i = N - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        intercambiar(fila + i, fila + j);
    }
}

void imprimirMatriz(int matriz[][N])
{
    for (int i = 0; i < N; i++)
    {
        int* fila = *(matriz + i);
        for (int j = 0; j < N; j++)
        {
            cout << *(fila + j) << " ";
        }
        cout << endl;
    }
}

void rotarDerecha(int* fila)
{
    int ultimo = *(fila + N - 1);

    for (int i = N - 1; i > 0; i--)
    {
        *(fila + i) = *(fila + i - 1);
    }

    *fila = ultimo;
}

void alinearValor(int matriz[][N], int valor, int col)
{
    for (int i = 0; i < N; i++)
    {
        int* fila = *(matriz + i);

        int pos = 0;
        while (*(fila + pos) != valor)
        {
            pos++;
        }

        while (pos != col)
        {
            rotarDerecha(fila);
            pos = (pos + 1) % N;
        }
    }
}

int main()
{
    srand(time(NULL));

    int matriz[N][N];

    for (int i = 0; i < N; i++)
    {
        generarFila(*(matriz + i));
    }

    cout << "Matriz inicial:\n";
    imprimirMatriz(matriz);

    int fi, co;
    cout << "\nFila inicial (1-9): ";
    cin >> fi;
    cout << "Columna inicial (1-9): ";
    cin >> co;

    fi--; 
    co--;

    int valor = *(*(matriz + fi) + co);

    cout << "\nValor seleccionado: " << valor << endl;

    alinearValor(matriz, valor, co);

    cout << "\nMatriz final:\n";
    imprimirMatriz(matriz);

    return 0;
}
