#include <iostream>
using namespace std;

int main() 
{
    int x;
    int* p = &x;
    *p = 10;
    cout << *p << endl;

    return 0;
}