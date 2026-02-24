#include <iostream>
using namespace std;

const int MAX = 30;


void ordenarRanking(char nombres[][21], int tiempos[], int n) // Usamos ordenamiento burbuja en la funcion
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - 1 - i; j++) 
        {

            if (tiempos[j] > tiempos[j + 1]) 
            {

                // intercambiamos tiempos
                int auxT = tiempos[j];
                tiempos[j] = tiempos[j + 1];
                tiempos[j + 1] = auxT;

                // intercambiamos nombres
                char auxN[21];
                for (int k = 0; k < 21; k++)
                {
                    auxN[k] = nombres[j][k];
                }

                for (int k = 0; k < 21; k++)
                {
                    nombres[j][k] = nombres[j + 1][k];
                }

                for (int k = 0; k < 21; k++)
                {
                    nombres[j + 1][k] = auxN[k];
                }
            }
        }
    }
}


void mostrarRanking(char nombres[][21], int tiempos[], int n) // Mostramos el ranking
{
    cout << "\nRANKING FINAL:\n";

    for (int i = 0; i < n; i++) 
    {
        cout << i + 1 << ". " << nombres[i] << " - " << tiempos[i] << " segundos\n";
    }
}


void buscarCorredor(char nombres[][21], int tiempos[], int n) // Buscamos al corredor
{
    char buscado[21];

    cout << "\nIngrese el nombre a buscar: ";
    cin >> buscado;

    for (int i = 0; i < n; i++) 
    {
        bool igual = true;
        for (int j = 0; j < 21; j++) 
        {
            if (nombres[i][j] != buscado[j]) 
            {
                igual = false;
                break;
            }
            if (nombres[i][j] == '\0')
            {
                break;
            }
        }

        if (igual) 
        {
            cout << "Corredor encontrado\n";
            cout << "Posicion: " << i + 1 << endl;
            cout << "Tiempo: " << tiempos[i] << " segundos\n";
            return;
        }
    }

    cout << "Corredor no encontrado\n";
}


void mostrarRango(char nombres[][21], int tiempos[], int n) 
{
    int tmin, tmax;

    cout << "\nIngrese tiempo minimo y maximo: ";
    cin >> tmin >> tmax;

    cout << "Corredores en el rango [" << tmin << ", " << tmax << "]:\n";

    for (int i = 0; i < n; i++) 
    {
        if (tiempos[i] >= tmin && tiempos[i] <= tmax) 
        {
            cout << nombres[i] << " - " << tiempos[i] << " segundos\n";
        }
    }
}


int main() {

    int n;
    char nombres[MAX][21];
    int tiempos[MAX];

    cout << "Ingrese el numero de corredores: ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        cout << "Nombre del corredor " << i + 1 << ": ";
        cin >> nombres[i];

        cout << "Tiempo (en segundos): ";
        cin >> tiempos[i];
    }

    ordenarRanking(nombres, tiempos, n);

    mostrarRanking(nombres, tiempos, n);

    buscarCorredor(nombres, tiempos, n);

    mostrarRango(nombres, tiempos, n);

    return 0;
}
