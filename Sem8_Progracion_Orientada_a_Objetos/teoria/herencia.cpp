#include <iostream>
using namespace std;

// Clase base
class Vehiculo
{
protected:          // para tener acceso desde clases derivadas
    int ruedas;
    string color;

public:
    // Constructor
    Vehiculo(int r, string c): ruedas(r), color(c) {}

    // Mostrar informacion
    void mostrarInfo()
    {
        cout << "Numero de ruedas del Vehiculo: " << ruedas << endl;
        cout << "Color del Vehiculo: " << color << endl;
    }

    // Destructor
    ~Vehiculo()
    {
        cout << "Destructor Vehiculo" << endl;
    }
};

// Clase derivada Coche
class Coche: public Vehiculo
{
private:
    int numeroPuertas;

public:
    // Constructor
    Coche(int r, string c, int np): Vehiculo(r, c), numeroPuertas(np) {}

    // Metodo especifico para Coche
    void mostrarCoche()
    {
        cout << "Numero de puertas del Coche: " << numeroPuertas << endl;
        cout << "Color del Coche: " << color << endl;
        cout << "Numero de ruedas del Coche: " << ruedas << endl;
    }

    ~Coche()
    {
        cout << "Destructor Coche" << endl;
    }
};

// Clase derivada Motocicleta
class Moto: public Vehiculo
{
private:
    bool conCasco;

public:
    // Constructor
    Moto(int r, string c, bool casco) : Vehiculo(r, c), conCasco(casco) {}

    // Metodo especifico para Coche
    void mostrarMoto()
    {
        cout << "Numero de ruedas de la Moto: " << ruedas << endl;
        cout << "Color de la Moto: " << color << endl;
        cout << "Tiene casco la moto: " << conCasco << endl;
    }

    ~Moto()
    {
        cout << "Destructor Moto" << endl;
    }
};

int main()
{
    // Instanciar un objeto de la clase base
    Vehiculo v1(4, "Azul");
    v1.mostrarInfo();

    Coche c1(4, "Rojo", 4);
    c1.mostrarCoche();

    Moto m1(2, "Negro", true);
    m1.mostrarMoto();

    return 0;
}