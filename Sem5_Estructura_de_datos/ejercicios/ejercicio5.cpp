#include <iostream>
#include <string>
using namespace std;

// Nodo
struct Proceso 
{
    int id;
    string nombre;
    float memoria;
    Proceso* sig;
};

// Lista
struct ListaProcesos 
{
    Proceso* cabeza;
};

// Inicializar lista vacía
void inicializar(ListaProcesos &lista) 
{
    lista.cabeza = nullptr;
}

// Insertar al inicio
void insertarInicio(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, lista.cabeza};
    lista.cabeza = nuevo;
}

// Insertar al final
void insertarFinal(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, nullptr};

    if (lista.cabeza == nullptr) 
    {
        lista.cabeza = nuevo;
        return;
    }

    Proceso* aux = lista.cabeza;
    while (aux->sig != nullptr)
    {
        aux = aux->sig;
    }

    aux->sig = nuevo;
}

// Mostrar
void mostrar(const ListaProcesos &lista) 
{
    Proceso* aux = lista.cabeza;

    if (aux == nullptr) 
    {
        cout << "(lista vacía)\n";
        return;
    }

    while (aux != nullptr) 
    {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Memoria: " << aux->memoria << " MB\n";
        aux = aux->sig;
    }
}

// Buscar por ID
Proceso* buscar(const ListaProcesos &lista, int id) 
{
    Proceso* aux = lista.cabeza;

    while (aux != nullptr) 
    {
        if (aux->id == id)
        {
            return aux;
        }
        aux = aux->sig;
    }
    return nullptr;
}

// Eliminar por ID
bool eliminar(ListaProcesos &lista, int id) 
{
    if (lista.cabeza == nullptr) 
    {
        return false;
    }

    // eliminar cabeza
    if (lista.cabeza->id == id) 
    {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
        return true;
    }

    Proceso* ant = lista.cabeza;
    Proceso* act = lista.cabeza->sig;

    while (act != nullptr) 
    {
        if (act->id == id) 
        {
            ant->sig = act->sig;
            delete act;
            return true;
        }
        ant = act;
        act = act->sig;
    }

    return false;
}

// Contar procesos
int contar(const ListaProcesos &lista) 
{
    int c = 0;
    Proceso* aux = lista.cabeza;

    while (aux != nullptr) 
    {
        c++;
        aux = aux->sig;
    }
    return c;
}

// Insertar ordenado por memoria ascendente
void insertarOrdenado(ListaProcesos &lista, int id, string nombre, float memoria) 
{
    Proceso* nuevo = new Proceso{id, nombre, memoria, nullptr};

    if (lista.cabeza == nullptr || memoria < lista.cabeza->memoria) 
    {
        nuevo->sig = lista.cabeza;
        lista.cabeza = nuevo;
        return;
    }

    Proceso* aux = lista.cabeza;
    while (aux->sig != nullptr && aux->sig->memoria < memoria)
    {
        aux = aux->sig;
    }

    nuevo->sig = aux->sig;
    aux->sig = nuevo;
}

// Ordenar la lista por memoria
void ordenarPorMemoria(ListaProcesos &lista) 
{
    ListaProcesos nueva;
    inicializar(nueva);

    Proceso* aux = lista.cabeza;
    while (aux != nullptr) 
    {
        insertarOrdenado(nueva, aux->id, aux->nombre, aux->memoria);
        aux = aux->sig;
    }

    // Liberando la lista vieja
    while (lista.cabeza != nullptr) 
    {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
    }

    lista.cabeza = nueva.cabeza;
}

// Liberar memoria total
void liberar(ListaProcesos &lista) 
{
    while (lista.cabeza != nullptr) 
    {
        Proceso* temp = lista.cabeza;
        lista.cabeza = lista.cabeza->sig;
        delete temp;
    }
}

// Para mostrar la busqueda
void mostrarProcesoEncontrado(Proceso* p) 
{
    if (p == nullptr) 
    {
        cout << "No encontrado\n";
    } 
    else 
    {
        cout << "Encontrado -> ID: " << p->id << " | Nombre: " << p->nombre
             << " | Memoria: " << p->memoria << " MB\n";
    }
}

int main() 
{
    ListaProcesos lista;
    inicializar(lista);

    // 3 al inicio
    insertarInicio(lista, 1, "Chrome", 200);
    insertarInicio(lista, 2, "VSCode", 150);
    insertarInicio(lista, 3, "Python", 180);

    // 2 al final
    insertarFinal(lista, 4, "Docker", 300);
    insertarFinal(lista, 5, "Node", 120);

    cout << "Procesos en lista (inicial):\n";
    mostrar(lista);
    cout << "\nTotal procesos: " << contar(lista) << "\n\n";

    // Buscando
    cout << "Buscando ID 3:\n";
    Proceso* encontrado = buscar(lista, 3);
    mostrarProcesoEncontrado(encontrado);
    cout << endl;

    // Eliminación de la cabeza
    cout << "Eliminando cabeza (ID 3)...\n";
    if (eliminar(lista, 3)) cout << "Eliminado ID 3 (cabeza)\n";
    else cout << "No se encontró ID 3\n";
    mostrar(lista);
    cout << "Total: " << contar(lista) << "\n\n";

    // Eliminación en posición intermedia (como ID 1)
    cout << "Eliminando en posición intermedia (ID 1)...\n";
    if (eliminar(lista, 1)) cout << "Eliminado ID 1\n";
    else cout << "No se encontró ID 1\n";
    mostrar(lista);
    cout << "Total: " << contar(lista) << "\n\n";

    // Eliminación al final (ID 5)
    cout << "Eliminando final (ID 5)...\n";
    if (eliminar(lista, 5)) cout << "Eliminado ID 5 (final)\n";
    else cout << "No se encontró ID 5\n";
    mostrar(lista);
    cout << "Total: " << contar(lista) << "\n\n";

    // Caso de proceso que no existe
    cout << "Intentando eliminar ID 999 (no existe)...\n";
    if (eliminar(lista, 999)) 
    {
    cout << "Eliminado ID 999\n";
    }
    else 
    {
    cout << "ID 999 no existe en la lista\n";
    }
    cout << "Total: " << contar(lista) << "\n\n";

    // Ordenar la lista por memoria antes de insertar ordenado
    cout << "Ordenando lista por consumo de memoria (ascendente)...\n";
    ordenarPorMemoria(lista);
    mostrar(lista);
    cout << "Total: " << contar(lista) << "\n\n";

    // Insertar manteniendo orden por memoria
    cout << "Insertando nuevo proceso manteniedno el orden: ID 6 MySQL 170 MB\n";
    insertarOrdenado(lista, 6, "MySQL", 170);
    mostrar(lista);
    cout << "Total: " << contar(lista) << "\n\n";

    // Liberamos memoria
    liberar(lista);
    cout << "Memoria liberada\n";

    return 0;
}
