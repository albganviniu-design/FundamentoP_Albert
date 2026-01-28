/*
Dado una lista de nombres
const char* nombres[][20] = {
    "Leslye",
    "Americo",
    "Xingbeck",
    "William",
    "Julio",
    "Darwin",
    "Kevin"
};

1.  ordenar la lista en orden alfabetica ascendente
2.  No usar[]
    use aritmetica de punteros
*/
#include <iostream>
#include <cstring>
using namespace std;

void ordenar(const char **nombres, int n)
{
    const char *temp;

    for (const char **i = nombres; i < nombres + n - 1; ++i)
    {
        for (const char **j = i + 1; j < nombres + n; ++j)
        {
            if (strcmp(*i, *j) > 0)
            {
                temp = *i;
                *i = *j;
                *j = temp;
            }
        }
    }
}


void imprimir(const char **nombres, int n)
{
    for (const char **i = nombres; i < nombres + n; ++i)
    {
        cout << *i << endl;
    }
}

int main()
{
    const char *nombres[] = {
        "Leslye",
        "Americo",
        "Xingbeck",
        "William",
        "Julio",
        "Darwin",
        "Kevin"};

    int n = sizeof(nombres) / sizeof(nombres[0]);

    cout << "Arreglo original:" << endl;
    imprimir(nombres, n);

    ordenar(nombres, n);

    cout << "\nArreglo ordenado ascendentemente:" << endl;
    imprimir(nombres, n);

    return 0;
}
