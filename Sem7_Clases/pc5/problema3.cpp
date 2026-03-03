#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    ofstream archivo("output/grafico.txt");
    if (!archivo)
    {
        cerr << "Error al abrir el grafico.txt." << endl;
        return 1;
    }

    double PI = 3.14159265358979323846; // Definimos el pi
    int numeroPuntos = 80, filas = 21, columnas = 80;
    double x, y;
    double incremento = (2 * PI) / (numeroPuntos - 1);
    double valoresY[numeroPuntos];

    for (int i = 0; i < numeroPuntos; i++) // Calculamos los valores de f(x) = seno(5x)
    {
        x = i * incremento;
        valoresY[i] = sin(5 * x);
    }

    for (int fila = filas - 1; fila >= 0; fila--) // Dibujamos la gráfica
    {
        for (int col = 0; col < columnas; col++)
        {
            double y_pos = valoresY[col] * (filas - 1) / 2 + (filas - 1) / 2;

            if (fila == (int)y_pos)
            {
                archivo << "*"; // Para la curva
            }
            else if (fila == (filas - 1) / 2)
            {
                archivo << "-"; // Los - para el eje X
            }
            else if (col == 0) // Para que el ejer Y este a la izquierda del todo
            {
                archivo << "|"; // Los | para el eje Y
            }
            else
            {
                archivo << " ";
            }
        }
        archivo << endl;
    }

    archivo.close();
    cout << "El gráfico ha sido generado" << endl;

    return 0;
}