#include <iostream>
#include <cmath>
using namespace std;

struct Punto
{
    double x;
    double y;
};

void leerPunto(Punto* p) // permite leer las coordenadas
{
    cout << "Ingrese la coordena 'X' del punto: ";
    cin >> p->x;
    cout << "Ingrese la coordenada 'Y' del punto: ";
    cin >> p->y;
}

double distanciaOrigen(const Punto* p) // Calcula la distancia de p al origen
{
    double distancia;
    distancia = sqrt(p->x * p->x + p->y * p->y);
    return distancia;
}

Punto* masLejano(Punto* p1, Punto* p2) // retorna un puntero al punto mas alejado del origen
{
    if (distanciaOrigen(p1) > distanciaOrigen(p2))
    {
        return p1;
    }
    else
    {
        return p2;
    }
}


int main()
{
    int i;
    Punto* p1 = new Punto;
    Punto* p2 = new Punto;

    cout << "\nPUNTO 1:" << endl;

    leerPunto(p1);

    cout << "\nPUNTO 2:" << endl;

    leerPunto(p2);

    if (distanciaOrigen(p1) > distanciaOrigen(p2))
    {
        i = 1;
    }
    else
    {
        i = 2;
    }

    if (distanciaOrigen(p1) != distanciaOrigen(p2))
    {
        cout << "\nEl punto mas lejos del origen es el PUNTO " << i << " con las coordenadas: " << endl;
        cout << "X: " << masLejano(p1, p2)->x << "\t\tY: " << masLejano(p1, p2)->y << endl;
    }
    else
    {
        if (p1 == p2)
        {
            cout << "\nLos puntos que escribio son exactamente iguales, vuelva a intentarlo con puntos diferentes" << endl;
        }
        else
        {
            cout << "\nLos puntos que escribio estan exactamente a la misma distancia del origen: " << distanciaOrigen(p1) << endl;
        }
    }

    cout << endl;

    delete p1;
    delete p2;

    return 0;
}
