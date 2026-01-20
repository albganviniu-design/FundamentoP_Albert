#include <iostream>
using namespace std;

int main() 
{

    int a = 50;
    int* p1 = &a;
    int** p2 = &p1;

    cout << "Valor de a: " << a << endl;
    cout << "Valor de a vía p1: " << *p1 << endl;
    cout << "Valor de a vía p2: " << **p2 << endl;


    return 0;
}