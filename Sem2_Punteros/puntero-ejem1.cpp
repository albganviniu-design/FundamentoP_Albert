#include <iostream>
using namespace std;

int main() 
{
    int a = 42;  // Variable en la memoria stack
    int* ptr = &a; // ptr guarda la dirección de a

    cout << "Valor de a: " << a << endl;
    cout << "Dirección de a: " << &a << endl;
    cout << "Valor desde el puntero: " << *ptr << endl;

    return 0;
}