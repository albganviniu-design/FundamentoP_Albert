#include <iostream>
using namespace std;

struct Producto
{
    int codigo;
    char* nombre;
    double precio;
    int stock;
};

// Función para que me ayude a calcular longitud de cadena
int longitudCadena(const char* texto)
{
    const char* p = texto;
    while (*p != '\0')
    {
        p++; 
    }

    return p - texto;
}

// Función para ayudar a copiar la cadena
void copiarCadena(char* destino, const char* origen)
{
    while (*origen != '\0')
    {
        *destino = *origen;
        destino++;
        origen++;
    }

    *destino = '\0';
}


// a) Crear producto
Producto crearProducto(int codigo, const char* nombre, double precio, int stock)
{
    Producto p;
    p.codigo = codigo;
    p.precio = precio;
    p.stock = stock;

    int len = longitudCadena(nombre);
    p.nombre = new char[len + 1];

    copiarCadena(p.nombre, nombre);

    return p;
}

// b) Crear inventario
Producto* crearInventario(int n)
{
    Producto* inventario = new Producto[n];

    const char* nombres[] = {"Teclado", "Mouse", "Monitor", "Laptop", "Impresora"};

    for (int i = 0; i < n; i++)
    {
        inventario[i] = crearProducto(100 + i, nombres[i], 10.5 * (i + 1), 5 * (i + 1));
    }

    return inventario;
}

// c) Buscar producto
Producto* buscarProducto(Producto* inventario, int n, int codigoBuscado)
{
    for (int i = 0; i < n; i++)
    {
        if (inventario[i].codigo == codigoBuscado)
        {
            return &inventario[i];
        }
    }
    return nullptr;
}

// d) Liberar memoria
void liberarInventario(Producto* inventario, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete[] inventario[i].nombre;
    }
    delete[] inventario;
}

// Funcion adicional para mostrar el inventario
void mostrarInventario(Producto* inventario, int n)
{
    cout << "\tINVENTARIO\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Codigo: " << inventario[i].codigo
             << " | Nombre: " << inventario[i].nombre
             << " | Precio: " << inventario[i].precio
             << " | Stock: " << inventario[i].stock << endl;
    }
}

int main()
{
    int n = 5;

    Producto* inventario = crearInventario(n);

    mostrarInventario(inventario, n);

    cout << "\nBuscando producto con codigo 102...\n";
    Producto* encontrado = buscarProducto(inventario, n, 102);

    if (encontrado != nullptr)
    {
        cout << "Producto encontrado: "
             << encontrado->nombre
             << " | Precio: " << encontrado->precio << endl;
    }
    else
    {
        cout << "Producto no encontrado\n";
    }

    liberarInventario(inventario, n);

    return 0;
}
