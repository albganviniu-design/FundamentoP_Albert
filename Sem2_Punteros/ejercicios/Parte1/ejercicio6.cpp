#include <iostream>
using namespace std;

void incrementar(int* p) 
{
    *p += 1;
}

int main() 
{
    int x = 10;
    incrementar(&x);
    cout << x << endl;
}