#include <iostream>
using namespace std;

int main() 
{

    int* ptr = nullptr;

    if (ptr != nullptr) 
    {
        cout << *ptr << endl;
    } 
    else 
    {
        cout << "Puntero nulo, no se puede desreferenciar." << endl;
    }


    return 0;
}