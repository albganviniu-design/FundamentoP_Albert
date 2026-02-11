#include<iostream>
#include<cmath>
using namespace std;

struct Punto
{
    float x;
    float y;
    float z;
};

void leerPunto(Punto &p)
{
    cout << "X: ";
    cin >> p.x;
    cout << "Y: ";
    cin >> p.y;
    cout << "Z: ";
    cin >> p.z;
}

float calcularDistancia(Punto &p, Punto &s)
{
    float n,m,o, K, M;

    n = p.x - s.x;
    m = p.y - s.y;
    o = p.z - s.z;

    K = pow(n,2) + pow(m,2) + pow(o,2);
    
    M = sqrt(K);

    return M;
}


int main()
{
    Punto P, S;

    cout << "Ingrese las coordenadas del primer punto:" << endl;
    leerPunto(P);

    cout << "Ingrese las coordenadas del segundo punto:" << endl;
    leerPunto(S);

    cout << "La distancia entre los dos puntos es: " << calcularDistancia(P, S) << endl;

    return 0;
}