#include <iostream>
using namespace std;

const int MAX_LIBROS = 100;

struct Libro {
    int codigo;
    char titulo[50];
    bool prestado;
};

struct Usuario
{
    int codigo;
    string nombres;
    int prestamos;
};


// Funciones a implementar

void registrarUsuario();

void registrarLibro(Libro libros[], int &n);

int buscarLibro(Libro libros[], int n, int codigo);

void prestarLibro(Libro libros[],int n);

void devolverLibro(Libro libros[], int n);

void guardarEnArchivo(Libro libros[], int n);

void cargarDesdeArchivo(Libro libros[], int n);

void mostrarLibros(Libro libros[], int n);

int main()
{
    // Menú interactivo
    Libro libros[MAX_LIBROS];

    libros[0].codigo = -100;

    int cantidad = 0;

    int opcion;

    do
    {
        cout << "\n1. Registrar libro\n";
        cout << "2. Prestar Libro\n";
        cout << "3. Devolver libro\n";
        cout << "4. Buscar libro\n";
        cout << "5. Mostrar libros\n";
        cout << "6. Salir\n";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            registrarLibro(libros, cantidad);
            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;
        }

    } while (opcion != 6);

    return 0;
}

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