#include <iostream>
#include <string>
using namespace std;

struct Estudiante
{
    string nombre;
    float nota;
};

void leerEstudiante(Estudiante e[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese el nombre del estudiante " << i + 1 << " : ";
        getline(cin, e[i].nombre);

        cout << "Ingrese la nota del estudiante " << i + 1 << " : ";
        cin >> e[i].nota;

        cin.ignore(); // Para evitar un salto
    }
}

void mayorNota(Estudiante e[], int n)
{
    float mayor = e[0].nota;
    int c = 0;

    for (int i = 0; i < n; i++)
    {
        if (mayor <= e[i].nota)
        {
            mayor = e[i].nota;
            c = i;
        }
    }
    cout << "El estudiante con la mayor nota es: " << e[c].nombre << endl; 
    cout << "Nota: " << e[c].nota << endl;
}


int main()
{
    int n;

    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;

    cin.ignore(); // evitar salto de línea antes del primer getline

    Estudiante *e = new Estudiante[n];

    leerEstudiante(e, n);

    mayorNota(e, n);

    delete[] e;
    e = nullptr;

    return 0;
}