#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
    int N;
    int notas[30][30];
    double promedios[30];
    //char estados[N];

    int aprob=0;
    double sumadeaprob=0;
    double promdeaprob;
    double sumpromedios=0;
    double promgen;

    int notamax=0;
    int notamin=21;

    cout << endl << "Ingrese la cantidad de alumnos (5-30): ";
    cin >> N;

    srand(time(0));
    
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            notas[i][j] = rand()%21;

            if (notas[i][j] > notamax)
            {
                notamax = notas[i][j];
            }

            if (notas[i][j] < notamin)
            {
                notamin = notas[i][j];
            }
            
            
        }
    }

    for (int i = 1; i <= N; i++)
    {
        promedios[i]=(notas[i][1]+notas[i][2]+notas[i][3]+notas[i][4]+notas[i][5])/5;
        sumpromedios=sumpromedios+promedios[i];

        if (promedios[i]>10)
        {
            aprob=aprob+1;
            sumadeaprob=sumadeaprob+promedios[i];
        }
        
    }
    promgen=(sumpromedios)/N;
    promdeaprob=(sumadeaprob)/aprob;
    

    cout << "Promedio general de la clase: " << promgen << endl;
    cout << "Cantidad de aprobados: " << aprob << endl;
    cout << "Nota maxima: " << notamax << endl;
    cout << "Nota minima: " << notamin << endl;
    cout << "Promedio de aprobados: " << promdeaprob << endl << endl;

    cout << "--- LISTA ORIGINAL ---" << endl;
    cout << "Alumno\tPromedio\tEstado\tnotas" << endl;
    cout << "--------------------------------------------" << endl;

    for (int i = 1; i <= N; i++)
    {

        for (int j = 1; j <= 5; j++)
        {
            cout << notas[i][j] << "\t";
        }
        cout << endl;
    }
    
    return 0;
}