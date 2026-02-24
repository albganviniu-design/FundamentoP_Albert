//TAREA
/*
Se tiene un arreglo de cadenas definido mediante
const char* cad[]

Implemente una funcion que cuente cuantas cadenas tienen longitud
*/

#include <iostream>
using namespace std;

int longitud(const char* p) {
    int cont = 0;
    while (p[cont] != '\0') 
    {
        cont++;
    }
    return cont;
}


int contarCadenas(const char* cad[], int n, int L) 
{
    int cont = 0;

    for (int i = 0; i < n; i++) 
    {
        if (longitud(cad[i]) == L) 
        {
            cont++;
        }
    }

    return cont;
}

int main() {
    const char* cad[] = {
        "Manzana",
        "Pera",
        "Albert",
        "Americo",
        "Libro"
    };

    int n = sizeof(cad) / sizeof(cad[0]);
    int L = 4;

    cout << "Cadenas de longitud " << L << ": "
         << contarCadenas(cad, n, L) << endl;

    return 0;
}
