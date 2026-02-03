#include <iostream>
using namespace std;

bool existePar(const char *texto, int k)
{
    int numeros[100]; // estatico
    int *pn = numeros;

    const char *p = texto;
    int valor = 0;
    bool leyendo = false;

    while (*p != '\0') // separo los numeros en numeros[100]
    {
        if (*p >= '0' && *p <= '9')
        {
            valor = valor * 10 + (*p - '0');
            leyendo = true;
        }
        else
        {
            if (leyendo)
            {
                *pn = valor;
                pn++;
                valor = 0;
                leyendo = false;
            }
        }
        p++;
    }

    if (leyendo) // por si quedo el ultimo
    {
        *pn = valor;
        pn++;;
    }

    int cantidad = pn - numeros;
    int i = 0, j = cantidad - 1;

    while (i < j) // comparo todas las sumas si es igual a k para devolver verdadero o falso
    {
        int suma = *(numeros + i) + *(numeros + j);

        if (suma == k)
        {
            return true;
        }
        else if (suma < k)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

    return false;
}

int main()
{
    const char *texto = "1, 2, 4, 7, 11";

    int k1 = 15;
    int k2 = 10;

    cout << "Texto: \"" << texto << "\"" << endl;

    if (existePar(texto, k1))
    {
        cout << "SI existen 2 numeros con suma " << k1 << endl;
    }
    else
    {
        cout << "NO existen 2 numeros con suma " << k1 << endl;
    }

    if (existePar(texto, k2))
    {
        cout << "SI existen 2 numeros con suma " << k2 << endl;
    }
    else
    {
        cout << "NO existen 2 numeros con suma " << k2 << endl;
    }

    return 0;
}