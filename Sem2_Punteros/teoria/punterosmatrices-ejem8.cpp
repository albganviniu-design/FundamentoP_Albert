#include <iostream>
using namespace std;

const int FILA = 3;
const int COLUMNA = 4;

// A[i] = *(A+i)

// M[i][j] = M[i] + j = *(*(M + i) + j)

void leerMatriz(int (*A)[COLUMNA])
{

}

void mostrarMatriz(const int (*A)[COLUMNA])
{
    
}

/*
Un elemento a_ij es pico si es mayor que sus vecinos

1   2   3   4
5   6   7   8
9   10  11  12

*/

int contarPicos(const int (*A)[COLUMNA])
{

}

void mostrarPicos(const int (*A)[COLUMNA])
{

}

int main() 
{

    int mat[2][3] = {{1,2,3},{4,5,6}};
    int (*p)[3] = mat; // puntero a fila

    for(int i=0;i<2;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << *(*(p+i)+j) << " ";
        }
    }
    cout << endl;

    return 0;
}