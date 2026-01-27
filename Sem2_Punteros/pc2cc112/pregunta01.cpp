#include <iostream>
using namespace std;

// Complete la funcion que calcula la derivada de orden k de un polinomio
// Usar EXCLUSIVAMENTE punteros (NO indices)

void derivadaK(
    const double* coef, //
    int grado, int k,   //
    double* res,        //
    int& gradoRes       //
) {
    // Escriba su codigo aqui

    if (k > grado) // en caso de que el orden sea mayor
    {
        gradoRes = 0;
        *res = 0;
        return;
    }

    double temp[20];
    const double *pCoef = coef;
    double *pTemp = temp;

    for (int i = 0; i <= grado; i++)
    {
        *pTemp = *pCoef;
        pTemp++;
        pCoef++;
    }

    int gradoActual = grado;

    for (int d = 0; d < k; d++)
    {
        pTemp = temp;
        for (int i = 0; i < gradoActual; i++)
        {
            *pTemp = (*(pTemp + 1)) * (i + 1);
            pTemp++;
        }
        gradoActual--;
    }


    gradoRes = gradoActual;
    pTemp = temp;
    double *pRes = res;

    for (int i = 0; i <= gradoRes; i++)
    {
        *pRes = *pTemp;
        pRes++;
        pTemp++;
    }
}


// Complete la función auxiliar para imprimir un polinomio
void imprimirPolinomio(const double* p, int grado) 
{
    const double *ptr = p;

    for (int i = 0; i <= grado; i++)
    {
        if (*ptr != 0)
        {
            if (i > 0 && *ptr > 0)
                cout << " + ";
            if (*ptr < 0)
                cout << " - ";

            double val = (*ptr < 0) 
            ? -*ptr : *ptr;

            if (i == 0)
                cout << val;
            else if (i == 1)
                cout << val << "x";
            else
                cout << val << "x^" << i;
        }
        ptr++;
    }
    cout << endl;
}

int main() {
    // Polinomio:
    // P(x) = 2 + 3x - x^2 + 4x^3
    double coef[] = {2, 3, -1, 4};
    const int grado = 3;

    double resultado[10]; // espacio suficiente
    int gradoResultado;

    int k = 2; // derivada de orden 2

    // Llamar a su funcion derivadaK

    // Llamar la funcion imprimir para mostrar el polinomio original y  la derivada

    derivadaK(coef, grado, k, resultado, gradoResultado);

    cout << "Polinomio original: ";
    imprimirPolinomio(coef, grado);

    cout << "Derivada de orden " << k << ": ";
    imprimirPolinomio(resultado, gradoResultado);

    return 0;
}