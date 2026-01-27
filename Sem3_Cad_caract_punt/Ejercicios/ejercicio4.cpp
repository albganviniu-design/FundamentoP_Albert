#include <iostream>
using namespace std;

void imprimir(const char *p) //const ya que lo ultimo que quiero es imprimir
{                            //sin cambiar ningun caracter de la cadena
    while (*p != '\0')       
    {
        cout << *p;
        p++; // <> p = p + 1
    }
}

int main()
{

    //CUIDADO, el nombre de un arreglo
    //es un puntero const a su primer elemento
    int arr[] = {1, 2, 3};
    //arr++; // ERROR EL PUNTERO arr ES CONST


    char texto[] = "Hola"; // cadena
    char* p = texto;

    cout << p << endl;


    char palabra[] = "PERU";
    char* p1 = palabra;

    cout << *(p1 + 1) << endl; // <> p1 + 1*sizeof(char)

    return 0;
}