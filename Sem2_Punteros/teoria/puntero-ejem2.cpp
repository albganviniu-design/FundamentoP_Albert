#include <iostream>
using namespace std;

int main() 
{

    int x = 100;
    int* p = &x;  // p apunta a x
    cout << "p apunta a: " << *p << endl << endl; // desreferencia

    float y = 23.5;
    float* pf = &y;

    cout << "Valor de y es: " << y << endl;
    cout << "La dirección de y es: " << &y << endl;
    cout << "El valor de y via de pf es: " << *pf << endl << endl;

    char ch = 'A';
    char* pch = &ch;

    cout << "La direccion de ch es: " << (void*)&ch << endl;
    cout << "El valor de y via de pf es: " << *pch << endl << endl;


    return 0;
}