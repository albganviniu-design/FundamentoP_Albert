#include<iostream>
using namespace std;

bool esPico(int *A, int F, int C, int i, int j)
{
    int valor = *(A + i*C + j);
    bool mayorEstricto = false;

    // Arriba
    if (i - 1 >= 0)
    {
        int vecino = *(A + (i-1)*C + j);
        if (vecino > valor)
        {
            return false;
        }
        if (valor > vecino) 
        {
            mayorEstricto = true;
        }
    }

    // Abajo
    if (i + 1 < F)
    {
        int vecino = *(A + (i+1)*C + j);
        if (vecino > valor) 
        {
            return false;
        }
        if (valor > vecino) 
        {
            mayorEstricto = true;
        }
    }

    // Izquierda
    if (j - 1 >= 0)
    {
        int vecino = *(A + i*C + (j-1));
        if (vecino > valor) 
        {
            return false;
        }
        if (valor > vecino) 
        {
            mayorEstricto = true;
        }
    }

    // Derecha
    if (j + 1 < C)
    {
        int vecino = *(A + i*C + (j+1));
        if (vecino > valor) 
        {
            return false;
        }
        if (valor > vecino) 
        {
            mayorEstricto = true;
        }
    }

    return mayorEstricto;
}

void imprimirPicos(int *A, int F, int C)
{
    for (int i = 0; i < F; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (esPico(A, F, C, i, j))
            {
                cout << "Pico en (" << i << ", " << j << "): " << *(A + i*C + j) << endl;
            }
        }
    }
}


int main()
{
    const int F = 4;
    const int C = 5;

    int A[F][C] = {
        {3, 3, 3, 3, 3},
        {3, 4, 4, 2, 3},
        {3, 4, 5, 4, 3},
        {3, 3, 3, 3, 3}
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
    
    cout << "Elementos picos:" << endl;
    imprimirPicos(&A[0][0], F, C);

    return 0;  
}