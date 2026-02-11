#include <iostream>
# include <string>
using namespace std;

struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Contacto
{
    string nombre;
    Fecha nacimiento;
};


Contacto *reservarMemoria(int n)
{
    return new Contacto[n];
}


void leerContactos(Contacto arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "\nContacto " << i + 1 << endl;

        cout << "Nombre: ";
        cin >> arr[i].nombre;

        cout << "Nacimiento (dia mes año):" << endl;
        cout << "Dia: ";
        cin >> arr[i].nacimiento.dia;
        cout << "Mes: ";
        cin >> arr[i].nacimiento.mes;
        cout << "Año: ";
        cin >> arr[i].nacimiento.anio;
    }
}


void nacidosEnUnAnioEspecifico(Contacto arr[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].nacimiento.anio == m)
        {
            cout << arr[i].nombre << endl;
        }
    }
}

int main()
{
    int N, M;

    // Pedimos la cantidad de contactos
    cout << "Ingrese la cantidad de contactos: ";
    cin >> N;

    // a) Reservar memoria dinamica para N contactos
    Contacto *c = reservarMemoria(N);

    // b) Leer los datos
    leerContactos(c, N);

    // c) Mostrar los nacidos de un año especifico
    cout << "\nElija un año: ";
    cin >> M;

    cout << "\nLos nacidos en el año " << M << " son:\n";
    nacidosEnUnAnioEspecifico(c, N, M);

    // d) Liberar memoria
    delete[] c;
    c = nullptr;

    return 0;
}