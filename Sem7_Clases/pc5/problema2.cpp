#include <iostream>
#include <fstream>
using namespace std;

struct Empleado
{
    int id;   // comienza en 1
    char nombre[30];
    double salario;
};

int main()
{
    fstream archivo("entradas/empleados.dat", ios::in | ios::out | ios::binary);

    if (!archivo)
    {
        cout << "Error al abrir empleados.dat" << endl;
        return 1;
    }

    int idBuscado;

    cout << "Ingrese ID del empleado: ";
    cin >> idBuscado;

    Empleado emp;

    archivo.seekg((idBuscado - 1) * sizeof(Empleado), ios::beg); // seekg para lectura

    if (!archivo.read((char*)&emp, sizeof(Empleado)))
    {
        cout << "Empleado no encontrado." << endl;
        archivo.close();
        return 1;
    }

    cout << "\n--- DATOS DEL EMPLEADO ---\n";
    cout << "ID: " << emp.id << endl;
    cout << "Nombre: " << emp.nombre << endl;
    cout << "Salario: " << emp.salario << endl;

    double nuevoSalario;

    cout << "\nIngrese nuevo salario: ";
    cin >> nuevoSalario;

    emp.salario = nuevoSalario;

    archivo.seekp((idBuscado - 1) * sizeof(Empleado), ios::beg); // seekp para escritura

    archivo.write((char*)&emp, sizeof(Empleado));

    cout << "\nSalario actualizado correctamente" << endl;

    archivo.close();

    return 0;
}