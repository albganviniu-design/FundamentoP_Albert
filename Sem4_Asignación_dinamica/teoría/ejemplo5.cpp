#include <iostream>
using namespace std;

int main()
{

    int* v = new int[10];
    // ...
    v = new int[20]; //  fuga de memoria

    delete [] v;

    return 0;
}