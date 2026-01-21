#include <iostream>
using namespace std;

// a)
void imprimir(const int* inicio, const int* fin)
{
    for (const int *p = inicio; p < fin; p++)
    {
        cout << *p << " ";
    }
}

// b)
int* buscarPrimerNegativo(int* inicio, int* fin)
{
    for ( int *p = inicio; p < fin; p++)
    {
        if (*p < 0)
        {
            return p;
        }
    }
    return fin;
}

// c)     (FALTA RESOLVER ESTO ESTA MAL SE BORRA)
int* subarregloMaximoInicio(int* inicio, int* fin)
{
    int ultimasuma = 0; // acumular ultima suma
    int sumaMax = *inicio; // asumo que el primer elemento es
    int* finMaxSubarray = inicio + 1;

    for ( int *p = inicio; p < fin; p++)
    {
        ultimasuma += *p;
        if (ultimasuma > sumaMax)
        {
            sumaMax = ultimasuma;
            finMaxSubarray = p + 1;
        }
    }
    return finMaxSubarray;
}

// d)
void intercambiar(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void invertir(int* inicio, int* fin)
{
    int* l = inicio;
    int* q = fin - 1; // puntero al último elemento

    while (l < q)
    {
        intercambiar(l, q);
        l++; // avanzar desde el inicio
        q--; // retroceder desde el final
    }
}

// e)
int *maxAbsoluto(int *inicio, int *fin)
{
    if (inicio == fin) // arreglo vacío
        return nullptr;

    int* max = inicio; // puntero al elemento con mayor absoluto

    for (int *p = inicio; p < fin; ++p)
    {
        int valor_ahora = *p;

        if (valor_ahora < 0)
        {
            valor_ahora = -valor_ahora;
        }

        int valor_max = *max;

        if (valor_max < 0)
        {
            valor_max = -valor_max;
        }

        if (valor_ahora > valor_max)
        {
            max = p;
        }
    }
    return max;
}

int main() 
{
    int datos[] = {3, -2, 5, 7, -4, 10, -6, 1};

    int n = sizeof(datos)/sizeof(datos[0]);

    int* inicio = datos;
    int* fin = datos + n;

    cout << "Arreglo original: ";
    imprimir(inicio, fin);

    cout << endl << "Primer elemento negativo: " << *buscarPrimerNegativo(inicio, fin);

    int *psm = subarregloMaximoInicio(inicio, fin);

    cout << endl << "El arreglo max es: ";
    imprimir(inicio, psm);

    cout << endl << "Arreglo invertido: ";
    invertir(inicio, fin);
    imprimir(inicio, fin);

    cout << endl << "Valor de mayor magnitub(absoluto): " << *maxAbsoluto(inicio, fin) << endl;

    return 0;
}