#include <iostream>
#include <cmath>
using namespace std;

struct Polinomio
{
    int grado;
    float *coef;
};

// Mostrar
void mostrarPolinomio(const Polinomio &p)
{
    for (int i = 0; i <= p.grado; i++)
    {
        if (p.grado - i == 0)
        {
            cout << p.coef[i];
        }
        else
        {
            if (p.coef[i] == 0) // Para que cuando el coef es 0 no imprima nada
            {
                cout << "";
            }
            else
            {
                cout << p.coef[i] << "x^" << p.grado - i;
                if (i != p.grado)
                {
                    cout << " + ";
                }
            }
        }
    }
}

// Suma
Polinomio sumarTresPolinomios(const Polinomio &a, const Polinomio &b, const Polinomio &c)
{
    Polinomio r;
    r.grado = max(a.grado, max(b.grado, c.grado));
    r.coef = new float[r.grado + 1];

    for (int i = 0; i <= r.grado; i++)
    {
        r.coef[i] = 0;
    }

    for (int i = 0; i <= a.grado; i++)
    {
        r.coef[r.grado - a.grado + i] += a.coef[i];
    }

    for (int i = 0; i <= b.grado; i++)
    {
        r.coef[r.grado - b.grado + i] += b.coef[i];
    }

    for (int i = 0; i <= c.grado; i++)
    {
        r.coef[r.grado - c.grado + i] += c.coef[i];
    }

    return r;
}


// Producto
Polinomio multiplicarTresPolinomios(const Polinomio &a, const Polinomio &b, const Polinomio &c)
{
    // Primero: a * b
    Polinomio temp;
    temp.grado = a.grado + b.grado;
    temp.coef = new float[temp.grado + 1];

    for (int i = 0; i <= temp.grado; i++)
    {
        temp.coef[i] = 0;
    }

    for (int i = 0; i <= a.grado; i++)
    {
        for (int j = 0; j <= b.grado; j++)
        {
            temp.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    // Segundo: (a*b) * c
    Polinomio r;
    r.grado = temp.grado + c.grado;
    r.coef = new float[r.grado + 1];

    for (int i = 0; i <= r.grado; i++)
        r.coef[i] = 0;

    for (int i = 0; i <= temp.grado; i++)
        for (int j = 0; j <= c.grado; j++)
            r.coef[i + j] += temp.coef[i] * c.coef[j];

    // liberar temporal
    delete[] temp.coef;

    return r;
}


// Liberar memoria
void liberar(Polinomio &p)
{
    delete[] p.coef;
    p.coef = nullptr;
}

int main()
{
    Polinomio p1, p2, p3;

    p1.grado = 2;
    p1.coef = new float[p1.grado + 1];
    p1.coef[0] = 1;
    p1.coef[1] = 0;
    p1.coef[2] = 3;

    p2.grado = 1;
    p2.coef = new float[p2.grado + 1];
    p2.coef[0] = -4;
    p2.coef[1] = 5;

    p3.grado = 2;
    p3.coef = new float[p3.grado + 1];
    p3.coef[0] = 3;
    p3.coef[1] = 0;
    p3.coef[2] = 1;

    cout << "Polinomio 1: ";
    mostrarPolinomio(p1);

    cout << "\nPolinomio 2: ";
    mostrarPolinomio(p2);

    cout << "\nPolinomio 3: ";
    mostrarPolinomio(p3);

    cout << endl;

    //Sumamos y multiplicamos los 3 polinomios

    Polinomio suma = sumarTresPolinomios(p1, p2, p3);
    cout << "\nLa suma de los tres polinomios es: ";
    mostrarPolinomio(suma);

    cout << endl;

    Polinomio prod = multiplicarTresPolinomios(p1, p2, p3);
    cout << "\nEl producto de los tres polinomios es: ";
    mostrarPolinomio(prod);

    cout << endl;

    // liberar memoria
    liberar(p1);
    liberar(p2);
    liberar(p3);
    liberar(suma);
    liberar(prod);

    return 0;
}
