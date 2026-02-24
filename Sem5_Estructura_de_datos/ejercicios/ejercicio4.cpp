#include <iostream>
#include <cmath>
using namespace std;

struct Polinomio
{
    int grado;
    float *coef;
};

// Leer polinomio
void leerPolinomio(Polinomio &p)
{
    cin >> p.grado;

    p.coef = new float[p.grado + 1];

    for (int i = 0; i <= p.grado; i++)
    {
        cout << "Ingrese el coeficiente de x^" << p.grado - i << ": ";
        cin >> p.coef[i];
    }
}

// Mostrar
void mostrarPolinomio(const Polinomio &p)
{
    for (int i = 0; i <= p.grado; i++)
    {
        if (p.grado - i == 0)
        {
            cout << p.coef[i];  // término independiente
        } 
        else
        {
            cout << p.coef[i] << "x^" << p.grado - i;
        }

        if (i != p.grado)
            cout << " + ";
    }
    cout << endl;
}


// Suma
Polinomio sumar(const Polinomio &a, const Polinomio &b)
{
    Polinomio r;
    r.grado = max(a.grado, b.grado);
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

    return r;
}

// Producto
Polinomio multiplicar(const Polinomio &a, const Polinomio &b)
{
    Polinomio r;
    r.grado = a.grado + b.grado;
    r.coef = new float[r.grado + 1];

    for (int i = 0; i <= r.grado; i++)
    {
        r.coef[i] = 0;
    }

    for (int i = 0; i <= a.grado; i++)
    {
        for (int j = 0; j <= b.grado; j++)
        {
            r.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return r;
}

// Evaluar
float evaluar(const Polinomio &p, float x)
{
    float res = 0;
    for (int i = 0; i <= p.grado; i++)
    {
        res += p.coef[i] * pow(x, p.grado - i);
    }
    return res;
}

// Liberar memoria
void liberar(Polinomio &p)
{
    delete[] p.coef;
    p.coef = nullptr;
}

int main()
{
    Polinomio p1, p2;

    cout << "Ingrese el grado del primer polinomio: ";
    leerPolinomio(p1);

    cout << endl;

    cout << "Ingrese el grado del segundo polinomio: ";
    leerPolinomio(p2);

    cout << "\nPrimer polinomio: ";
    mostrarPolinomio(p1);

    cout << "Segundo polinomio: ";
    mostrarPolinomio(p2);

    Polinomio suma = sumar(p1, p2);
    cout << "La suma de los polinomios es: ";
    mostrarPolinomio(suma);

    Polinomio prod = multiplicar(p1, p2);
    cout << "El producto de los polinomios es: ";
    mostrarPolinomio(prod);

    float x;
    
    cout << "\nIngrese el valor de x para evaluar el primer polinomio: ";
    cin >> x;

    cout << "El primer polinomio evaluado en x = " << x << " es: " << evaluar(p1, x) << endl;

    // liberar memoria
    liberar(p1);
    liberar(p2);
    liberar(suma);
    liberar(prod);

    return 0;
}
