#include<iostream>
using namespace std;

const int NFILAS = 9;
const int NCOLS = 9;

void imprimir(int ** A)
{
    for (int i = 0; i < NFILAS; ++i)
    {
        for (int j = 0; j < NCOLS; ++j)
        {
            cout << *(*A + i* NCOLS + j) << " ";
        }
        cout << endl;
    }
    
}

// Completar las funciones

void generar(int **A);


void actualizar(int **A, int fil, int col);

int main()
{
    int M[NFILAS][NCOLS]; // (*p)[NCOLS]

    int *p = &M[0][0];

    int **A = &p;

    return 0;
}