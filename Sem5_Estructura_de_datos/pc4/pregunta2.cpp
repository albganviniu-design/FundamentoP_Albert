#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

struct Seleccion
{
    string nombre;
    int puntajeTotal;
    float rendimiento;
    int PG;
    int PE;
    int PP;
    int GF;
    int GC;
    int DG;
};

int main()
{
    Seleccion S[5];

    srand(time(0));

    for (int i = 0; i < 5; i++)
    {
        S[i].nombre = "Pais_" + to_string(i);

        do
        {
            S[i].PE = rand() % 101;
            S[i].PG = rand() % 101;
            S[i].PP = rand() % 101;

        } while (S[i].PE + S[i].PG + S[i].PP != 100); // 100 partidos

        // Goles
        S[i].GF = 0;
        S[i].GC = 0;

        // Partidos ganados
        for (int k = 0; k < S[i].PG; k++)
        {
            int gc = rand() % 5;                 // 0 a 4
            int gf = gc + 1 + rand() % (5 - gc); // mayor que gc
            S[i].GF += gf;
            S[i].GC += gc;
        }

        // Partidos empatados
        for (int k = 0; k < S[i].PE; k++)
        {
            int goles = rand() % 6; // 0 a 5
            S[i].GF += goles;
            S[i].GC += goles;
        }

        // Partidos perdidos
        for (int k = 0; k < S[i].PP; k++)
        {
            int gf = rand() % 5;                 // 0 a 4
            int gc = gf + 1 + rand() % (5 - gf); // mayor que gf
            S[i].GF += gf;
            S[i].GC += gc;
        }

        S[i].DG = S[i].GF - S[i].GC; // DG = GF - GC diferencia de goles

        S[i].puntajeTotal = S[i].PE + 3 * S[i].PG;
        S[i].rendimiento = ((float)S[i].puntajeTotal / 300) * 100;
    }

    // Ordenando los puntajes
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            if (S[j].puntajeTotal > S[i].puntajeTotal ||
                (S[j].puntajeTotal == S[i].puntajeTotal && S[j].DG > S[i].DG) ||
                (S[j].puntajeTotal == S[i].puntajeTotal && S[j].DG == S[i].DG && S[j].GF > S[i].GF))
            {
                Seleccion aux = S[i];
                S[i] = S[j];
                S[j] = aux;
            }
        }
    }

    // Imprimiendo la tabla
    cout << "Seleccion   PG     PE     PP     GF     GC     DG     Pts     Rend(%)" << endl;
    cout << "----------------------------------------------------------------------" << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << S[i].nombre << setw(8)
             << S[i].PG << setw(7)
             << S[i].PE << setw(7)
             << S[i].PP << setw(7)
             << S[i].GF << setw(7)
             << S[i].GC << setw(7)
             << S[i].DG << setw(8)
             << S[i].puntajeTotal << setw(9)
             << fixed << setprecision(1) << S[i].rendimiento << endl;
    }

    cout << "\nCampeon: " << S[0].nombre
         << " | Puntaje: " << S[0].puntajeTotal
         << " | DG: " << S[0].DG
         << " | Rendimiento: " << fixed << setprecision(1) << S[0].rendimiento << "%" << endl;

    return 0;
}
