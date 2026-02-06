#include <iostream>
using namespace std;

const int N = 4;

// M[i] <> *(M + i)      M[i][j] <> *(*(M + i) + j)

bool esFilaDominanteEstricta(int (*M)[N], int fila)
{
    bool estricta = false;

    for (int col = 0; col < N; col++)
    {
        int valor = *(*(M + fila) + col);

        for (int f = 0; f < N; f++)
        {
            if (f != fila)
            {
                int otro = *(*(M + f) + col);

                if (valor < otro)
                    return false;

                if (valor > otro)
                    estricta = true;
            }
        }
    }

    return estricta;
}

bool esFilaFuertementeDominante(int (*M)[N], int fila)
{
    // Debe ser dominante estricta
    if (!esFilaDominanteEstricta(M, fila))
    {
        return false;
    }

    int sumaFila = 0;
    for (int col = 0; col < N; col++)
    {
        sumaFila += *(*(M + fila) + col);
    }

    // Comparar con la suma de las demás filas
    for (int f = 0; f < N; f++)
    {
        if (f != fila)
        {
            int sumaOtra = 0;
            for (int col = 0; col < N; col++)
            {
                sumaOtra += *(*(M + f) + col);
            }

            if (sumaFila <= sumaOtra)
                return false;
        }
    }

    return true;
}

int main()
{
    int M[N][N] = {
        {2, 3, 1, 4},
        {1, 2, 3, 2},
        {5, 6, 7, 8},
        {0, 1, 2, 1}};

    cout << "Fila" << "\tDominante Estricta" << "\tFuertemente Dominante"<< endl;
    cout << "--------------------------------------------------------------" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << i << "\t";

        if (esFilaDominanteEstricta(M,i))
        {
            cout << "SI";
        }
        else
        {
            cout << "NO";
        }

        cout << "\t\t\t";

        if (esFilaFuertementeDominante(M, i))
        {
            cout << "SI";
        }
        else
        {
            cout << "NO";
        }
        cout << endl;
    }

    return 0;
}

