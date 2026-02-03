#include <iostream>
using namespace std;

void f()
{
    int x = 10;       // stack
    int *y = new int; // heap NO SE LIBERA AUTOMATICAMENTE

    delete y;
}

int main()
{
    
    f();

    return 0;
}