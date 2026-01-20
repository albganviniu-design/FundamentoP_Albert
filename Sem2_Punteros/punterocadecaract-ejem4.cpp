#include <iostream>
using namespace std;

int main() 
{

    char mensaje[] = "Hola Mundo";
    char* pm = mensaje;

    while (*pm != '\0') //desreferncia
    {
        cout << *pm << " Direccion: " << (void*)pm << endl;
        pm++; //aritmetica de punteros
    }
    cout << endl;

    return 0;
}