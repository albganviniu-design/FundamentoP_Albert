#ifndef VEHICULOS_H
#define VEHICULOS_H

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// definicion de la clase base (ABSTRACTA)
class Vehiculo
{
protected:
    // miembros de datos
    string placa;
    string marca;
    int anio;
    double precioVenta;

public:
    // Funciones miembro
    // Constructores
    Vehiculo(); // Constructor por defecto
    Vehiculo(string p, string m, int a, double pv);

    // Destructor
    virtual ~Vehiculo(); // virtual para polimorfismo

    // Metodo virtual para polimorfismo
    virtual void mostrarInformacion() const;

    // Convertimos la clase base a una clase abstracta
    virtual double calcularPrecioFinal() const = 0; // método abstracto/virtual puro

    // Para guardar y cargar en archivo binario
    virtual void guardar(ofstream &out) const = 0;
    virtual void cargar(ifstream &in) = 0;

    // Para identificar tipo al reconstruir
    virtual int getTipo() const = 0;
};

class Automovil : public Vehiculo
{
private:
    int numeroPuertas;

public:
    // Funciones miembro
    // Constructores
    Automovil(); // Constructor por defecto
    Automovil(string p, string m, int a, double pv, int np);

    // Destructor
    ~Automovil();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) override;

    int getTipo() const override;
};

class Camion : public Vehiculo
{
private:
    double capacidad;

public:
    // Funciones miembro
    // Constructores
    Camion(); // Constructor por defecto
    Camion(string p, string m, int a, double pv, double cp);

    // Destructor
    ~Camion();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) override;

    int getTipo() const override;
};

class Motocicleta : public Vehiculo
{
private:
    double potencia;

public:
    // Funciones miembro
    // Constructores
    Motocicleta(); // Constructor por defecto
    Motocicleta(string p, string m, int a, double pv, double pt);

    // Destructor
    ~Motocicleta();

    // Sobreescritura de metodo virtual
    void mostrarInformacion() const override;

    // Polimorfismo: precio final
    double calcularPrecioFinal() const override;

    void guardar(ofstream &out) const override;
    void cargar(ifstream &in) override;

    int getTipo() const override;
};

#endif