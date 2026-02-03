#include <iostream>
using namespace std;

// 1.1. Solicitar al usuario el número n de estudiantes.
void leerEstudiantes(int &n)
{
    cout << "Ingrese el numero de estudiantes: ";
    cin >> n;
}

// 1.2. Reservar memoria dinámica para almacenar las notas float notas[n]
float *reservarMemoria(int n)
{
    return new float[n];
}

// 1.3. Leer las notas desde el teclado
void leerNotas(float *notas, int n, int inicio)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ingrese la nota del estudiante " << inicio + i << ": ";
        cin >> notas[i];
    }
}

// 1.4. Calcular: Promedio del curso. Nota máxima y mínima
void calcularEstadisticas(float *notas, int n, float &promedio, float &max, float &min)
{
    float suma = 0;
    max = notas[0];
    min = notas[0];

    for (int i = 0; i < n; i++)
    {
        suma += notas[i];

        if (notas[i] > max)
        {
            max = notas[i];
        }
        if (notas[i] < min)
        {
            min = notas[i];
        }
    }

    promedio = suma / n;
}

// 1.5. Redimensionar dinámicamente el arreglo para agregar k estudiantes.
void redimensionar(float *&notas, int &n, int k)
{
    // asignar memoria dinamica de tamaño n + k
    float *nuevasNotas = new float[n + k];

    // Copiar los valores antiguos
    for (int i = 0; i < n; i++)
    {
        nuevasNotas[i] = notas[i];
    }

    // actualizar notas (puntero) y n
    delete[] notas;
    notas = nuevasNotas; // perdemos referencia al bloque antiguo
    n += k;
}

// 1.8. Liberar correctamente la memoria

void liberarMemoria(float *&notas)
{
    delete[] notas;
    notas = nullptr;
}

int main()
{
    int n;
    leerEstudiantes(n);

    // 1. Reservar memoria
    float *notas = reservarMemoria(n);

    // 2. Leer notas
    leerNotas(notas, n, 1);

    // 3. Calcular estadísticas iniciales
    float promedio, max, min;
    calcularEstadisticas(notas, n, promedio, max, min);

    cout << "\n--- Resultados iniciales ---\n";
    cout << "Promedio: " << promedio << endl;
    cout << "Nota maxima: " << max << endl;
    cout << "Nota minima: " << min << endl;

    // 4. Agregar k estudiantes
    int k;
    cout << "\nIngrese la cantidad de estudiantes a agregar: ";
    cin >> k;

    // Redimensionando para agregar k estudiantes
    redimensionar(notas, n, k);

    // Leer nuevas notas
    leerNotas(notas + n - k, k, n - k + 1);

    // 5. Recalcular estadísticas
    calcularEstadisticas(notas, n, promedio, max, min);

    cout << "\n--- Resultados finales ---\n";
    cout << "Promedio: " << promedio << endl;
    cout << "Nota maxima: " << max << endl;
    cout << "Nota minima: " << min << endl;

    // 6. Liberar memoria
    liberarMemoria(notas);

    return 0;
}