#include<iostream>
using namespace std;

int sumaSubmatriz(int *A, int C,
                  int i1, int j1, int i2, int j2)
{
    int suma = 0;

    for (int i = i1; i <= i2; i++)
    {
        for (int j = j1; j <= j2; j++)
        {
            suma += *(A + i*C + j);
        }
    }

    return suma;
}


void submatrizSumaMaxima(int *A, int F, int C)
{
    int maxSuma = *(A); // primer elemento
    int best_i1 = 0, best_j1 = 0;
    int best_i2 = 0, best_j2 = 0;

    for (int i1 = 0; i1 < F; i1++)
    {
        for (int j1 = 0; j1 < C; j1++)
        {
            for (int i2 = i1; i2 < F; i2++)
            {
                for (int j2 = j1; j2 < C; j2++)
                {
                    int suma = sumaSubmatriz(A, C, i1, j1, i2, j2);

                    if (suma > maxSuma)
                    {
                        maxSuma = suma;
                        best_i1 = i1;
                        best_j1 = j1;
                        best_i2 = i2;
                        best_j2 = j2;
                    }
                }
            }
        }
    }

    cout << "Submatriz de suma maxima:" << endl;
    cout << "Esquina superior izquierda: ("
         << best_i1 << ", " << best_j1 << ")" << endl;
    cout << "Esquina inferior derecha: ("
         << best_i2 << ", " << best_j2 << ")" << endl;
    cout << "Suma maxima: " << maxSuma << endl;
}


int main()
{

    const int F = 4;
    const int C = 5;

    int A[F][C] = {
        {-2,  1, -3,  4, -1},
        { 2,  3, -2,  1, -5},
        {-1,  4,  2, -3,  2},
        { 1, -2,  3,  4, -1}
    };

    cout << "Matriz:" << endl;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << "  " << A[i][j] << "\t";
        }
        cout << endl;
    }

    submatrizSumaMaxima(&A[0][0], F, C);

    return 0;
}