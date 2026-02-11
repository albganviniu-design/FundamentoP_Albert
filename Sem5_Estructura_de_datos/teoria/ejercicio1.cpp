#include <iostream>
using namespace std;

struct Estudiante
{
    int codigo;
    float promedio;
};

int main()
{
    int N;

    // a) Solicitar la cantidad de estudiantes
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> N;

    // b) Reservar memoria dinámicamente
    Estudiante *e = new Estudiante[N];

    // c) Leer los datos
    for (int i = 0; i < N; i++)
    {
        cout << "\nEstudiante " << i + 1 << endl;
        cout << "Codigo: ";
        cin >> e[i].codigo;

        cout << "Promedio: ";
        cin >> e[i].promedio;
    }

    // d) Mostrar únicamente los aprobados (>= 10)
    cout << "\n--- Estudiantes Aprobados ---\n";
    for (int i = 0; i < N; i++)
    {
        if (e[i].promedio >= 10)
        {
            cout << "Codigo: " << e[i].codigo << endl;
            cout << "Promedio: " << e[i].promedio << endl;
            cout << "---------------------------\n";
        }
    }

    // e) Liberar memoria
    delete[] e;
    e = nullptr;

    return 0;
}