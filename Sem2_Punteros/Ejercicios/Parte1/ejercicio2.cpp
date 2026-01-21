#include <iostream>
using namespace std;

int* crearEntero() 
{
    int static x = 42;
    return &x;
}

int main() 
{
    int* p = crearEntero();
    cout << *p << endl;
}