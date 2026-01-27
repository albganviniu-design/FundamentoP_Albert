#include <iostream>
using namespace std;

int main()
{
    char nombre[10]; // cadena;

    int edad;

    cout << "Ingrese su edad: ";
    cin >> edad;

    //LImpiar buffer o sino ignora lo del nombre ya que lee vacio
    cin.ignore();

    cout << "Ingrese su nombre:" << endl;
    //cin >> nombre; // ERROR
    cin.getline(nombre, 10);

    cout << edad << endl;
    cout << nombre << endl; // con el gintline solo lee los primeros 9 caracteres

    // El código puede detener el programa sin avisar

    return 0;
}