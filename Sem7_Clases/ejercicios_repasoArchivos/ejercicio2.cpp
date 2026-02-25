#include <iostream>
#include <iomanip> // Para ordenar con setw
#include <fstream>
using namespace std;

int main()
{
    ifstream archivoEntrada1("entradas/baseUNI.txt");

    if (!archivoEntrada1)
    {
        cout << "Error, no se pudo abrir baseUNI.txt";
        return 1;
    }

    string linea;

    cout << left << setw(7) << "Num"
         << setw(20) << "Apellidos"
         << setw(12) << "Nombre"
         << setw(8) << "Nota1"
         << setw(8) << "Nota2"
         << setw(10) << "Promedio" << endl;

    float maxPromedio = 0;
    string alumnoMax;
    string apellidos, nombre;
    float nota1, nota2;
    int num;

    while (getline(archivoEntrada1, linea, '.'))
    {
        num = stoi(linea);

        getline(archivoEntrada1, apellidos, ',');
        getline(archivoEntrada1, nombre, '-');

        getline(archivoEntrada1, linea, '-');
        nota1 = stof(linea);

        getline(archivoEntrada1, linea);
        nota2 = stof(linea);

        float promedio = (nota1 + nota2) / 2;

        cout << left << setw(7) << num
             << setw(20) << apellidos
             << setw(12) << nombre
             << setw(8) << nota1
             << setw(8) << nota2
             << setw(10) << fixed << setprecision(2) << promedio
             << endl;

        if (promedio > maxPromedio)
        {
            maxPromedio = promedio;
            alumnoMax = nombre + " " + apellidos;
        }
    }

    archivoEntrada1.close();

    cout << "\nEl promedio maximo: " << fixed << setprecision(2) << maxPromedio << endl;
    cout << "Alumno: " << alumnoMax << endl;

    return 0;
}