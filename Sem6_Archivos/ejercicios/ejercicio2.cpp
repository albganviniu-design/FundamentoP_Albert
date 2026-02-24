#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream archivoEntrada("input/notas.txt");

    ofstream archivoSalida("output/reporte.txt");

    if (!archivoEntrada)
    {
        cout << "Error, no se pudo abrir notas.txt";
        return 1;
    }

    if (!archivoSalida)
    {
        cout << "Error, no se pudo abrir reporte.txt";
        return 1;
    }

    double nota;
    int contarNotas = 0;
    double suma = 0.0;
    double mayorNota, menorNota;
    int aprobados = 0, desaprobados = 0;
    
    while (archivoEntrada >> nota)
    {
        contarNotas++;
        suma += nota;

        if (contarNotas == 1)
        {
            mayorNota = nota;
            menorNota = nota;
        }
        else
        {
            if (nota > mayorNota)
            {
                mayorNota = nota;
            }
            
            if (nota < menorNota)
            {
                menorNota = nota;
            }
        }

        if (nota >= 10)
        {
            aprobados++;
        }
        else
        {
            desaprobados++;
        }
        
    }

    double promedio = suma/contarNotas;

    archivoSalida << "REPORTE GENERAL" << endl;
    archivoSalida << "---------------------" << endl;
    archivoSalida << "Total de estudiantes: " << contarNotas << endl;
    archivoSalida << "Promedio: " << promedio << endl;
    archivoSalida << "Mayor nota: " << mayorNota << endl;
    archivoSalida << "Menor nota: " << menorNota << endl;
    archivoSalida << "Aprobados: " << aprobados << endl;
    archivoSalida << "Desaprobados: " << desaprobados << endl;

    archivoEntrada.close();
    archivoSalida.close();

    cout << "Reporte generado correctamente" << endl;

    return 0;
}