#include "Vehiculos.h"
#include <iostream>
#include <fstream>

using namespace std;

const int MAX = 100;

void registrarVehiculo(Vehiculo *lista[], int &cantidad);
void mostrarVehiculos(Vehiculo *lista[], int cantidad);
void guardarEnArchivo(Vehiculo *lista[], int cantidad);
void cargarDesdeArchivo(Vehiculo *lista[], int &cantidad);

int main()
{
    Vehiculo *vehiculos[MAX]; // arreglo de punteros
    int cantidad = 0;
    int opcion;

    do
    {
        cout << "\n===== SISTEMA DE VEHICULOS =====\n";
        cout << "1. Registrar vehiculo\n";
        cout << "2. Mostrar vehiculos\n";
        cout << "3. Guardar en archivo\n";
        cout << "4. Cargar desde archivo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarVehiculo(vehiculos, cantidad);
            break;
        case 2:
            mostrarVehiculos(vehiculos, cantidad);
            break;
        case 3:
            guardarEnArchivo(vehiculos, cantidad);
            break;
        case 4:
            cargarDesdeArchivo(vehiculos, cantidad);
            break;
        case 0:
            cout << "Saliendo del sistema...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    // Liberar memoria
    for (int i = 0; i < cantidad; i++)
        delete vehiculos[i];

    return 0;
}

void registrarVehiculo(Vehiculo *lista[], int &cantidad)
{
    if (cantidad >= MAX)
    {
        cout << "Limite de vehiculos alcanzado.\n";
        return;
    }

    int tipo;
    string placa, marca;
    int anio;
    double precio;

    cout << "\nTipo de vehiculo:\n";
    cout << "1. Automovil\n";
    cout << "2. Camion\n";
    cout << "3. Motocicleta\n";
    cout << "Seleccione: ";
    cin >> tipo;

    cout << "Placa: ";
    cin >> placa;

    cout << "Marca: ";
    cin >> marca;

    cout << "Anio: ";
    cin >> anio;

    cout << "Precio base: ";
    cin >> precio;

    if (tipo == 1)
    {
        int puertas;
        cout << "Numero de puertas: ";
        cin >> puertas;

        lista[cantidad] = new Automovil(placa, marca, anio, precio, puertas);
        cantidad++;
    }
    else if (tipo == 2)
    {
        double capacidad;
        cout << "Capacidad (toneladas): ";
        cin >> capacidad;

        lista[cantidad] = new Camion(placa, marca, anio, precio, capacidad);
        cantidad++;
    }
    else if (tipo == 3)
    {
        double potencia;
        cout << "Potencia (HP): ";
        cin >> potencia;

        lista[cantidad] = new Motocicleta(placa, marca, anio, precio, potencia);
        cantidad++;
    }
    else
    {
        cout << "Tipo invalido.\n";
    }
}

void mostrarVehiculos(Vehiculo *lista[], int cantidad)
{
    if (cantidad == 0)
    {
        cout << "No hay vehiculos registrados.\n";
        return;
    }

    cout << "\n===== LISTA DE VEHICULOS =====\n";

    for (int i = 0; i < cantidad; i++)
    {
        lista[i]->mostrarInformacion(); // POLIMORFISMO DINAMICO
        cout << "---------------------------\n";
    }
}

void guardarEnArchivo(Vehiculo *lista[], int cantidad)
{
    ofstream archivo("vehiculos.dat", ios::binary);

    if (!archivo)
    {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    for (int i = 0; i < cantidad; i++)
    {
        lista[i]->guardar(archivo); // POLIMORFISMO
    }

    archivo.close();
    cout << "Vehiculos guardados correctamente.\n";
}

void cargarDesdeArchivo(Vehiculo *lista[], int &cantidad)
{
    ifstream archivo("vehiculos.dat", ios::binary);

    if (!archivo)
    {
        cout << "No existe archivo para cargar.\n";
        return;
    }

    // Limpiar lista actual
    for (int i = 0; i < cantidad; i++)
        delete lista[i];

    cantidad = 0;

    while (archivo.peek() != EOF && cantidad < MAX)
    {
        int tipo;
        archivo.read((char *)&tipo, sizeof(tipo));

        Vehiculo *v = nullptr;

        if (tipo == 1)
            v = new Automovil();
        else if (tipo == 2)
            v = new Camion();
        else if (tipo == 3)
            v = new Motocicleta();

        if (v != nullptr)
        {
            v->cargar(archivo);
            lista[cantidad] = v;
            cantidad++;
        }
    }

    archivo.close();
    cout << "Vehiculos cargados correctamente.\n";
}