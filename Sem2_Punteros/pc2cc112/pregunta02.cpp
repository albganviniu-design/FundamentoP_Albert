#include <iostream>
using namespace std;

// Complete la funcion de busqueda
int* buscar(
    int* inicio,                 // Estos dos primeros parametros
    int* fin,                    // delimitan el rango de busqueda a [inicio, fin)
    bool (*equivale)(int, int),  // equivale es una funcion que determina cuando dos enteros se condideran equivalentes
    int clave                    // clave es el valor a buscar segun el criterio indicado
) {
    // Complete aqui
    for (int *p = inicio; p < fin; ++p)
    {
        if (equivale(*p, clave))
        {
            return p;
        }
    }
    return nullptr;
}

// Implemente aqui los Criterios de equivalencia
// y si es necesario algunas funciones adicionales para reproducir el ejemplo de salida

bool igual(int a, int b)
{
    return a == b;
}

bool mismaParidad(int a, int b)
{
    if (a < 0)
    {
        a = -a;
    }

    if (b < 0)
    {
        b = -b;
    }
    
    return (a % 2) == (b % 2);
}

bool DivideA(int a, int b)
{
    if (a == 0)
    {
        return false;
    }
    return b % a == 0;
}

int cantidadDigitos(int x) //Funcion que añadi para ayudarme con los digitos
{
    if (x < 0)
    {
        x = -x;
    }
    
    if (x == 0)
    {
        return 1;
    }

    int c = 0;
    while (x > 0)
    {
        x /= 10;
        c = c + 1;
    }
    return c;
}

bool mismaCantidadDigitos(int a, int b)
{
    return cantidadDigitos(a) == cantidadDigitos(b);
}

bool MismoResiduoMod5(int a, int b)
{
    return a % 5 == b % 5;
}

int main() {
    int A[] = { -1, 21, 2, -2, 8, 13, 25 };
    int* inicio = A;
    int* fin = A + 7;

    int clave = 13;

    // Imprima el arreglo
    cout << endl << "Arreglo: ";

    for (int i = 0; i < 7; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl << endl;

    // Llame a la funcion buscar para cada criterio implementado

    int *res;

    res = buscar(inicio, fin, igual, clave);
    cout << "Igualdad exacta: ";
    if (res)
    {
        cout << "encontrado valor: " << *res << " pos: " << res << endl;
    }

    res = buscar(inicio, fin, mismaParidad, clave);
    cout << "Misma paridad: ";
    if (res)
    {
        cout << "encontrado valor: " << *res << " pos: " << res << endl;
    }

    res = buscar(inicio, fin, DivideA, clave);
    cout << "Divide a: ";
    if (res)
    {
        cout << "encontrado valor: " << *res << " pos: " << res << endl;
    }

    res = buscar(inicio, fin, mismaCantidadDigitos, clave);
    cout << "Misma cantidad de digitos: ";
    if (res)
    {
        cout << "encontrado valor: " << *res << " pos: " << res << endl;
    }

    res = buscar(inicio, fin, MismoResiduoMod5, clave);
    cout << "Mismo residuo modulo 5: ";
    if (res)
    {
        cout << "encontrado valor: " << *res << " pos: " << res << endl;
    }

    return 0;
}
