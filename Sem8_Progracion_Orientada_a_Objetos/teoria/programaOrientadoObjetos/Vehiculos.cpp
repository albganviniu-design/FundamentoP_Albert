#include "Vehiculos.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

Vehiculo::Vehiculo() // Constructor por defecto
{
    cout << "Llamando al constructor por defecto" << endl;
}

Vehiculo::Vehiculo(string p, string m, int a, double pv) : placa(p), marca(m), anio(a), precioVenta(pv)
{
    cout << "Llamando al constructor de parametro" << endl;
}

Vehiculo::~Vehiculo()
{
    cout << "Destruyendo Vehiculo" << endl;
}

void Vehiculo::mostrarInformacion() const
{
    cout << "Placa: " << placa << endl;
    cout << "Marca: " << marca << endl;
    cout << "Anio: " << anio << endl;
    cout << fixed << setprecision(2);
    cout << "Precio base: $" << precioVenta << endl;
}

// Automovil
Automovil::Automovil() {} // Constructor por defecto

Automovil::Automovil(string p, string m, int a, double pv, int np): Vehiculo(p, m, a, pv), numeroPuertas(np) {}

Automovil::~Automovil()
{
    cout << "Destruyendo Automovil" << endl;
}

void Automovil::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Numero de puertas: " << numeroPuertas << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Automovil::calcularPrecioFinal() const
{
    return precioVenta * 1.05; // precio base + 5%
}

// Metodo para identificar tipo de vehiculo
int Automovil::getTipo() const
{
    return 1; // 1 = Automovil
}

// Metodo para guardar en archivo binario
void Automovil::guardar(ofstream &out) const
{
    int tipo = getTipo();
    out.write((char *)&tipo, sizeof(tipo));

    size_t len;

    len = placa.size();
    out.write((char *)&len, sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((char *)&len, sizeof(len));
    out.write(marca.c_str(), len);

    out.write((char *)&anio, sizeof(anio));
    out.write((char *)&precioVenta, sizeof(precioVenta));
    out.write((char *)&numeroPuertas, sizeof(numeroPuertas));
}

// Metodo para cargar desde archivo binario
void Automovil::cargar(ifstream &in)
{
    size_t len;
    char buffer[100];

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char *)&anio, sizeof(anio));
    in.read((char *)&precioVenta, sizeof(precioVenta));
    in.read((char *)&numeroPuertas, sizeof(numeroPuertas));
}

// Camion
Camion::Camion() {} // Constructor por defecto

Camion::Camion(string p, string m, int a, double pv, double cp): Vehiculo(p, m, a, pv), capacidad(cp) {}

Camion::~Camion()
{
    cout << "Destruyendo Camion" << endl;
}

void Camion::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Capacidad: " << capacidad << " toneladas" << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Camion::calcularPrecioFinal() const
{
    return precioVenta * 1.12; // precio base + 12%
}

// Metodo para identificar tipo de vehiculo
int Camion::getTipo() const
{
    return 2; // 2 = Camion
}

// Metodo para guardar en archivo binario
void Camion::guardar(ofstream &out) const
{
    int tipo = getTipo();
    out.write((char *)&tipo, sizeof(tipo));

    size_t len;

    len = placa.size();
    out.write((char *)&len, sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((char *)&len, sizeof(len));
    out.write(marca.c_str(), len);

    out.write((char *)&anio, sizeof(anio));
    out.write((char *)&precioVenta, sizeof(precioVenta));
    out.write((char *)&capacidad, sizeof(capacidad));
}

// Metodo para cargar desde archivo binario
void Camion::cargar(ifstream &in)
{
    size_t len;
    char buffer[100];

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char *)&anio, sizeof(anio));
    in.read((char *)&precioVenta, sizeof(precioVenta));
    in.read((char *)&capacidad, sizeof(capacidad));
}

// Motocicleta
Motocicleta::Motocicleta() {} // Constructor por defecto

Motocicleta::Motocicleta(string p, string m, int a, double pv, double pt): Vehiculo(p, m, a, pv), potencia(pt) {}

Motocicleta::~Motocicleta()
{
    cout << "Destruyendo Motocicleta" << endl;
}

void Motocicleta::mostrarInformacion() const
{
    Vehiculo::mostrarInformacion();
    cout << "Potencia: " << potencia << " HP" << endl;
    cout << "Precio final: $" << calcularPrecioFinal() << endl;
}

double Motocicleta::calcularPrecioFinal() const
{
    return precioVenta * 1.03; // precio base + 3%
}

// Metodo para identificar tipo de vehiculo
int Motocicleta::getTipo() const
{
    return 3; // 3 = Motocicleta
}

// Metodo para guardar en archivo binario
void Motocicleta::guardar(ofstream &out) const
{
    int tipo = getTipo();
    out.write((char *)&tipo, sizeof(tipo));

    size_t len;

    len = placa.size();
    out.write((char *)&len, sizeof(len));
    out.write(placa.c_str(), len);

    len = marca.size();
    out.write((char *)&len, sizeof(len));
    out.write(marca.c_str(), len);

    out.write((char *)&anio, sizeof(anio));
    out.write((char *)&precioVenta, sizeof(precioVenta));
    out.write((char *)&potencia, sizeof(potencia));
}

// Metodo para cargar desde archivo binario
void Motocicleta::cargar(ifstream &in)
{
    size_t len;
    char buffer[100];

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    placa = buffer;

    in.read((char *)&len, sizeof(len));
    in.read(buffer, len);
    buffer[len] = '\0';
    marca = buffer;

    in.read((char *)&anio, sizeof(anio));
    in.read((char *)&precioVenta, sizeof(precioVenta));
    in.read((char *)&potencia, sizeof(potencia));
}