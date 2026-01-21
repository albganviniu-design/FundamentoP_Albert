#include <iostream>
using namespace std;

int main() 
{
    int arr[3] = {10, 20, 30};
    int* p = arr;

    p = p + 2;
    cout << *p << endl;
}