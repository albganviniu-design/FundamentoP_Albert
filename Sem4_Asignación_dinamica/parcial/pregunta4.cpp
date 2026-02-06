#include <iostream>
using namespace std;

void inicializar(int *&codigos, float *&promedios, int capacidad) // Funcion para inicializar con una capacidad inicial
{
    codigos = new int[capacidad];
    promedios = new float[capacidad];
}

void duplicarCapacidad(int *&codigos, float *&promedios, int &capacidad) // Funcion que duplica la capacidad
                                                                         // cuando el arreglo esta lleno
{
    int nuevaCapacidad = capacidad * 2;

    int *nuevosCodigos = new int[nuevaCapacidad];
    float *nuevosPromedios = new float[nuevaCapacidad];

    for (int i = 0; i < capacidad; i++)
    {
        nuevosCodigos[i] = codigos[i];
        nuevosPromedios[i] = promedios[i];
    }

    delete[] codigos;
    delete[] promedios;

    codigos = nuevosCodigos;
    promedios = nuevosPromedios;
    capacidad = nuevaCapacidad;
}

void agregarEstudiante(int *&codigos, float *&promedios,
                       int &cantidad, int &capacidad,
                       int codigo, float promedio)
{
    if (cantidad == capacidad)
    {
        duplicarCapacidad(codigos, promedios, capacidad);
    }

    codigos[cantidad] = codigo;
    promedios[cantidad] = promedio;
    cantidad++; // Cada que se agrega un estudiante va subiendo la cantidad
}

void mostrarEstudiantes(int *codigos, float *promedios, int cantidad)
{
    for (int i = 0; i < cantidad; i++)
    {
        cout << "Codigo: " << codigos[i]
             << " Promedio: " << promedios[i] << endl;
    }
}

void filtrarAprobados(int *&codigos, float *&promedios, int &cantidad)
{
    int aprobados = 0;

    // Contamos los aprobados
    for (int i = 0; i < cantidad; i++)
    {
        if (promedios[i] >= 10)
        {
            aprobados++;
        }
    }

    int *nuevosCodigos = new int[aprobados];
    float *nuevosPromedios = new float[aprobados];

    int j = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (promedios[i] >= 10)
        {
            nuevosCodigos[j] = codigos[i];
            nuevosPromedios[j] = promedios[i];
            j++;
        }
    }

    delete[] codigos;
    delete[] promedios;

    codigos = nuevosCodigos;
    promedios = nuevosPromedios;
    cantidad = aprobados;
}

int main()
{
    int *codigos;
    float *promedios;

    int capacidad = 2;
    int cantidad = 0;

    inicializar(codigos, promedios, capacidad);

    agregarEstudiante(codigos, promedios, cantidad, capacidad, 101, 14.5);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 102, 8.0);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 103, 16.2);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 104, 9.5);
    agregarEstudiante(codigos, promedios, cantidad, capacidad, 105, 12.3);

    cout << "Estudiantes registrados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    cout << "\nFiltrando estudiantes desaprobados..." << endl;

    filtrarAprobados(codigos, promedios, cantidad);

    cout << "Estudiantes aprobados:" << endl;
    mostrarEstudiantes(codigos, promedios, cantidad);

    delete[] codigos;
    codigos = nullptr;

    delete[] promedios;
    promedios = nullptr;

    return 0;
}
