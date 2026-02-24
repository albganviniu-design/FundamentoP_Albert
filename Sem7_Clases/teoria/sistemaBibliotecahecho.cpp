#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

const int MAX_LIBROS = 100;

struct Libro
{
    int codigo;
    char titulo[50];
    bool prestado;
};

// Funciones a implementar

void registrarLibro(Libro libros[], int &n)
{
    if (n >= MAX_LIBROS)
    {
        cout << "Capacidad maxima alcanzada.\n";
        return;
    }

    cout << "Ingrese codigo del libro: ";
    cin >> libros[n].codigo;
    cin.ignore();

    cout << "Ingrese titulo del libro: ";
    cin.getline(libros[n].titulo, 50);

    libros[n].prestado = false;

    n++; // actualiza la cantidad de libros
    cout << "Libro registrado correctamente.\n";
}

int buscarLibro(Libro libros[], int n, int codigo)
{
    for (int i = 0; i < n; i++)
    {
        if (libros[i].codigo == codigo)
        {
            return i;
        }
    }
    return -1;
}

void prestarLibro(Libro libros[], int n)
{
    int codigo;
    cout << "Ingrese codigo del libro a prestar: ";
    cin >> codigo;

    int pos = buscarLibro(libros, n, codigo);

    if (pos == -1)
    {
        cout << "Libro no encontrado.\n";
    }
    else if (libros[pos].prestado)
    {
        cout << "El libro ya esta prestado.\n";
    }
    else
    {
        libros[pos].prestado = true;
        cout << "Libro prestado correctamente.\n";
    }
}

void devolverLibro(Libro libros[], int n)
{
    int codigo;
    cout << "Ingrese codigo del libro a devolver: ";
    cin >> codigo;

    int pos = buscarLibro(libros, n, codigo);

    if (pos == -1)
    {
        cout << "Libro no encontrado.\n";
    }
    else if (!libros[pos].prestado)
    {
        cout << "El libro no estaba prestado.\n";
    }
    else
    {
        libros[pos].prestado = false;
        cout << "Libro devuelto correctamente.\n";
    }
}

void guardarEnArchivo(Libro libros[], int n)
{
    ofstream archivo("biblioteca.dat", ios::binary);

    if (!archivo)
    {
        cout << "Error al abrir el archivo.\n";
        return;
    }

    archivo.write((char *)&n, sizeof(n));
    archivo.write((char *)libros, sizeof(Libro) * n);

    archivo.close();
    cout << "Datos guardados correctamente.\n";
}

void cargarDesdeArchivo(Libro libros[], int &n)
{
    ifstream archivo("biblioteca.dat", ios::binary);

    if (!archivo)
    {
        cout << "No existe archivo previo.\n";
        return;
    }

    archivo.read((char *)&n, sizeof(n));
    archivo.read((char *)libros, sizeof(Libro) * n);

    archivo.close();
    cout << "Datos cargados correctamente.\n";
}

void mostrarLibros(Libro libros[], int n)
{
    if (n == 0)
    {
        cout << "No hay libros registrados.\n";
        return;
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\nCodigo: " << libros[i].codigo;
        cout << "\nTitulo: " << libros[i].titulo;
        cout << "\nEstado: " << (libros[i].prestado ? "Prestado" : "Disponible");
        cout << "\n--------------------------\n";
    }
}

int main()
{
    // Menú interactivo
    Libro libros[MAX_LIBROS];
    int cantidad = 0;
    int opcion;

    cargarDesdeArchivo(libros, cantidad);

    do
    {
        cout << "\n===== MENU BIBLIOTECA =====\n";
        cout << "1. Registrar libro\n";
        cout << "2. Prestar libro\n";
        cout << "3. Devolver libro\n";
        cout << "4. Mostrar libros\n";
        cout << "5. Guardar en archivo\n";
        cout << "6. Cargar desde archivo\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarLibro(libros, cantidad);
            break;
        case 2:
            prestarLibro(libros, cantidad);
            break;
        case 3:
            devolverLibro(libros, cantidad);
            break;
        case 4:
            mostrarLibros(libros, cantidad);
            break;
        case 5:
            guardarEnArchivo(libros, cantidad);
            break;
        case 6:
            cargarDesdeArchivo(libros, cantidad);
            break;
        case 0:
            guardarEnArchivo(libros, cantidad);
            cout << "Saliendo del programa...\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}