#include <iostream> // hace una asignacion
using namespace std;

int main()
{

    int filas = 3, columnas = 4;

    int **M = new int *[filas];
    for (int i = 0; i < filas; i++)
    {
        M[i] = new int[columnas]; // M[i] <> *(M + i)
    }

    // FORMA CORRECTA DE LIBERAR
    for (int i = 0; i < filas; i++)
    {
        delete[] M[i];
    }
    delete[] M;

    return 0;
}
// en total 5 asignaciones 3 en el for una en el **M y una mas en la libreria