#include <iostream>
#include <cmath>
using namespace std;

struct Termino
{
    double coeficiente;
    int exponente;
};

struct Polinomio
{
    Termino *terminos; // Puntero dinámico a arreglo de Termino
    int cantidad;      // Cantidad de términos
};

void crearPolinomio(Polinomio &p, int n)
{
    p.cantidad = n;
    p.terminos = new Termino[n];
}

void leerPolinomio(Polinomio &p)
{
    cout << "Ingrese los grados y exponentes" << endl;

    for (int i = 0; i < p.cantidad; i++)
    {
        cout << "Coeficiente " << i + 1 << ": ";
        cin >> p.terminos[i].coeficiente;
        cout << "Exponente " << i + 1 << ": ";
        cin >> p.terminos[i].exponente;
    }
    
}

void mostrarPolinomio(const Polinomio &p)
{
    for (int i = 0; i < p.cantidad; i++)
    {
        cout << p.terminos[i].coeficiente << "x^" << p.terminos[i].exponente;

        if (i < p.cantidad - 1)
        {
            cout << " + ";
        }
    }
    cout << endl;
}

double evaluarPolinomio(const Polinomio &p, double x)
{
    double resultadoEvaluar = 0;

    for (int i = 0; i < p.cantidad; i++)
    {
        resultadoEvaluar += p.terminos[i].coeficiente * pow(x, p.terminos[i].exponente);
    }
    return resultadoEvaluar;
}

void derivarPolinomio(const Polinomio &p, Polinomio &der)
{
    crearPolinomio(der, p.cantidad);

    for (int i = 0; i < p.cantidad; i++)
    {
        der.terminos[i].coeficiente = p.terminos[i].coeficiente * p.terminos[i].exponente;
        der.terminos[i].exponente = p.terminos[i].exponente - 1;
    }
}

void sumaPolinomios(Polinomio &p1, Polinomio &p2, Polinomio &resultado)
{
    crearPolinomio(resultado, p1.cantidad + p2.cantidad);
    int k = 0;

    for (int i = 0; i < p1.cantidad; i++)
    {
        resultado.terminos[k] = p1.terminos[i]; // Copiamos
        k++;
    }

    for (int i = 0; i < p2.cantidad; i++)
    {
        bool encontrado = false;

        for (int j = 0; j < k; j++)
        {
            if (resultado.terminos[j].exponente == p2.terminos[i].exponente)
            {
                resultado.terminos[j].coeficiente += p2.terminos[i].coeficiente;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            resultado.terminos[k] = p2.terminos[i];
            k++;
        }
    }

    resultado.cantidad = k;
}

void liberarPolinomio(Polinomio &p)
{
    delete[] p.terminos;
    p.terminos = nullptr;
}

int main()
{
    Polinomio p1, der1, resultado;
    int n1;

    cout << "Ingrese la cantidad de terminos: ";
    cin >> n1;

    crearPolinomio(p1, n1);
    leerPolinomio(p1);

    cout << "Polinomio: ";
    mostrarPolinomio(p1);

    derivarPolinomio(p1, der1);

    cout << "Derivada: ";
    mostrarPolinomio(der1);

    sumaPolinomios(p1, der1, resultado);

    cout << "Suma del polinomio con su derivada: ";
    mostrarPolinomio(resultado);

    liberarPolinomio(p1);
    liberarPolinomio(der1);
    liberarPolinomio(resultado);

    return 0;
}