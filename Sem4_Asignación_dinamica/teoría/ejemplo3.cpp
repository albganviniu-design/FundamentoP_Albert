#include <iostream>
using namespace std;

int main()
{

    int *p = new int(0); // no puede ser new int eso es un error debe ser new int(0)
    cout << *p; // forma correcta, valor basura

    delete p; //libera memoria
    p = nullptr; // buena practica si esto no esta y hay 2 delete hay error ya que hay puntero colgante para eso usamos esto

    delete p;
    // PUNTERO COLGANTE (dangling pointer)



    return 0;
}