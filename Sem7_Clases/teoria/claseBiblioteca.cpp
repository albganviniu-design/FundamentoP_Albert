#include <iostream>
#include <cstring>
// #include <stdexcept> necesario para invalid_argument
using namespace std;

class Libro
{
private:
    int codigo;
    char titulo[50];
    bool prestado;

    /*
    Problema resuelto:
    Encapsulamiento (protegiendo los datos)
    ahora nadie puede modificar directamente codigo o prestado
    */
public:
    /*
    Problema resuelto:
    El constructor garantiza que el objeto sea valido
    */
    Libro(int c = 0, const char *t = "")
    {
        if (c < 0)
        {
            cout << "Codigo invalido\n";
            //throw invalid_argument("Codigo invalido");
            exit(1); // Existe Forma moderna: Manejo de excepciones
        }

        codigo = c;
        strcpy(titulo, t);
        prestado = false;
    }

    bool prestar()
    {
        if (prestado)
        {
            cout << "El libro ya fue prestado\n";
            return false;
        }
        prestado = true;
        return true;
    }

    void mostrar()
    {
        cout << codigo << " - " << titulo << " - " << (prestado ? "prestado" : "Disponible") << endl;
    }

};

int main()
{
    Libro l1;
    Libro l2(5, "El Aleph");
    Libro l3(4);

    l1.mostrar();
    l2.mostrar();
    l3.mostrar();

    Libro l4(-5);
    l4.mostrar();

    return 0;
}