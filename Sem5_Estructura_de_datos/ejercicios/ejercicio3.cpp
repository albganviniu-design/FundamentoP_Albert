#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Seleccion
{
    string nombre;
    int puntosTotales;
    float rendimiento;
    int PG;
    int PE;
    int PP;
};

int main()
{
    Seleccion S[5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        S[i].nombre = "Pais_Seleccion " + to_string(i);

        do
        {
            S[i].PE = rand() % 101;
            S[i].PG = rand() % 101;
            S[i].PP = rand() % 101;

        } while (!(S[i].PE + S[i].PG + S[i].PP == 100));

        S[i].puntosTotales = S[i].PE + 3*S[i].PG;

        S[i].rendimiento = ((float)S[i].puntosTotales/300)*100;
    }

    cout << "Seleccion" << "\t\tPG" << "\tPP" << "\tPE" << "\tPuntaje" << "\t\tRendimiento" << endl;

    int j = 0;
    float c = S[0].rendimiento;

    for (int i = 0; i < 5; i++)
    {
        cout << S[i].nombre << "\t" << S[i].PG << "\t" << S[i].PP << "\t" << S[i].PE 
             << "\t" << S[i].puntosTotales << "\t\t" << fixed << setprecision(1) << S[i].rendimiento << endl;

        if (c <= S[i].rendimiento)
        {
            c = S[i].rendimiento;
            j = i;
        }
    }
    
    cout << "La seleccion con mejor rendimiento es: " << S[j].nombre << "\tRendimiento: " << S[j].rendimiento << endl;

    return 0;
}