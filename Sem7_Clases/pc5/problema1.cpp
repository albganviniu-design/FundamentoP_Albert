#include <iostream>
#include <iomanip> // Para ordenar con setw
#include <fstream>
using namespace std;

int main()
{
    ifstream archivoEntrada1("entradas/notas.txt");

    ofstream archivoSalida2("output/reporteAlumnos.txt");

    if (!archivoEntrada1)
    {
        cout << "Error, no se pudo abrir notas.txt";
        return 1;
    }

    if (!archivoSalida2)
    {
        cout << "Error, no se pudo abrir reporteAlumno.txt";
        return 1;
    }

    string fila;

    archivoSalida2 << left << setw(10) << "codigo"
         << setw(12) << "Nombre"
         << setw(12) << "Promedio"
         << setw(11) << right << "Condicion" << endl;

    archivoSalida2 << "-------------------------------------------------" << endl;

    float maxPromedio = 0, minPromedio = 20, promedioGeneral = 0;
    string alumnoMax, alumnoMin;
    string nombre;
    float nota1, nota2, nota3;
    int codigo, totalEstudiantes = 0;

    while (getline(archivoEntrada1, fila, ' '))
    {
        codigo = stoi(fila);

        getline(archivoEntrada1, nombre, ' ');

        getline(archivoEntrada1, fila, ' ');
        nota1 = stof(fila);

        getline(archivoEntrada1, fila, ' ');
        nota2 = stof(fila);

        getline(archivoEntrada1, fila);
        nota3 = stof(fila);

        float promedio = (nota1 + nota2 + nota3) / 3;

        if (promedio >= 10)
        {
            if (nota1 < 5 | nota2 < 5 | nota3 < 5)
            {
                archivoSalida2 << left << setw(10) << codigo
                               << setw(12) << nombre
                               << setw(8) << right << fixed << setprecision(2) << promedio
                               << setw(15) << "DESAPROBADO"
                               << endl;
            }
            else
            {
                archivoSalida2 << left << setw(10) << codigo
                               << setw(12) << nombre
                               << setw(8) << right << fixed << setprecision(2) << promedio
                               << setw(15) << "APROBADO"
                               << endl;
            }
        }
        else
        {
            archivoSalida2 << left << setw(10) << codigo
                           << setw(12) << nombre
                           << setw(8) << right << fixed << setprecision(2) << promedio
                           << setw(15) <<"DESAPROBADO"
                           << endl;
        }

        if (promedio > maxPromedio)
        {
            maxPromedio = promedio;
            alumnoMax = nombre + " ";
        }

        if (promedio < minPromedio)
        {
            minPromedio = promedio;
            alumnoMin = nombre + " ";
        }

        promedioGeneral += promedio;

        totalEstudiantes++;
    }

    promedioGeneral = promedioGeneral/totalEstudiantes;

    archivoEntrada1.close();

    archivoSalida2 << "-------------------------------------------------" << endl;

    archivoSalida2 << "El total de estudiantes: " << totalEstudiantes << endl;
    archivoSalida2 << "Promedio general del curso: " << promedioGeneral << endl;

    archivoSalida2 << "-------------------------------------------------" << endl;

    archivoSalida2 << "El mayor promedio: " << fixed << setprecision(2) << maxPromedio << endl;
    archivoSalida2 << "Estudiante: " << alumnoMax << endl;

    archivoSalida2 << "-------------------------------------------------" << endl;

    archivoSalida2 << "El menor promedio: " << fixed << setprecision(2) << minPromedio << endl;
    archivoSalida2 << "Estudiante: " << alumnoMin << endl;

    archivoSalida2 << "-------------------------------------------------" << endl;

    cout << "Reporte generado correctamente." << endl;

    return 0;
}