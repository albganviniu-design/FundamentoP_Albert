#include <iostream>
using namespace std;

struct Item
{
    char* descripcion;
    int cantidad;
    double precioUnitario;
};

struct Pedido
{
    int numeroPedido;
    char* nombreCliente;
    Item* items;
    int cantidadItems;
};

int my_strlen(const char* str) // Para saber la longitud de la cadena
{
    const char* p = str;
    while (*p != '\0')
    {
        p++;
    }

    return p - str;
}

void my_strcpy(char* destino, const char* origen) // Para copiar la cadena
{
    while (*origen != '\0')
    {
        *destino = *origen;
        destino++;
        origen++;
    }
    *destino = '\0';
}

// Creo el item

Item crearItem(const char* descripcion, int cantidad, double precio)
{
    Item it;

    int len = my_strlen(descripcion);
    it.descripcion = new char[len + 1];
    my_strcpy(it.descripcion, descripcion);

    it.cantidad = cantidad;
    it.precioUnitario = precio;

    return it;
}

// a) CREAR PEDIDO
Pedido* crearPedido(int numero, const char* cliente, int cantidadItems)
{
    // reservar memoria para el pedido
    Pedido* p = new Pedido;

    p->numeroPedido = numero;
    p->cantidadItems = cantidadItems;

    // reservar memoria para nombre del cliente
    int len = my_strlen(cliente);
    p->nombreCliente = new char[len + 1];
    my_strcpy(p->nombreCliente, cliente);

    // reservar arreglo dinámico de items
    p->items = new Item[cantidadItems];

    const char* descripciones[] = {"Laptop", "Mouse", "Teclado"};

    for (int i = 0; i < cantidadItems; i++)
    {
        p->items[i] = crearItem(descripciones[i], i + 1, 100 * (i + 1));
    }

    return p;
}

// b) CALCULAR TOTAL
double calcularTotal(const Pedido* p)
{
    double total = 0;

    for (int i = 0; i < p->cantidadItems; i++)
    {
        total += p->items[i].cantidad * p->items[i].precioUnitario;
    }

    return total;
}

// c) ITEM MÁS CARO
Item* itemMasCaro(Pedido* p)
{
    if (p->cantidadItems == 0)
    {
        return nullptr;
    }

    Item* caro = &p->items[0];

    for (int i = 1; i < p->cantidadItems; i++)
    {
        if (p->items[i].precioUnitario > caro->precioUnitario)
        {
            caro = &p->items[i];
        }
    }

    return caro;
}

// d) LIBERAR MEMORIA
void liberarPedido(Pedido* p)
{
    for (int i = 0; i < p->cantidadItems; i++)
    {
        delete[] p->items[i].descripcion;
    }
    delete[] p->items;
    delete[] p->nombreCliente;
    delete p;
}

// Funcion adicional para mostrar el pedido
void mostrarPedido(Pedido* p)
{
    cout << "Pedido N°: " << p->numeroPedido << endl;
    cout << "Cliente: " << p->nombreCliente << endl;

    cout << "\nItems:\n";
    for (int i = 0; i < p->cantidadItems; i++)
    {
        cout << "- " << p->items[i].descripcion
             << " | Cant: " << p->items[i].cantidad
             << " | Precio: " << p->items[i].precioUnitario
             << endl;
    }

    cout << "\nTotal: " << calcularTotal(p) << endl;

    Item* caro = itemMasCaro(p);
    if (caro != nullptr)
    {
        cout << "\nItem mas caro: " << caro->descripcion
             << " | Precio: " << caro->precioUnitario << endl;
    }
}

int main()
{
    Pedido* pedido = crearPedido(101, "Carlos Perez", 3);

    mostrarPedido(pedido);

    liberarPedido(pedido);

    return 0;
}
