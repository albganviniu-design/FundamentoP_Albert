#include<iostream>
using namespace std;

int main ()
{
    char c = 'A';
    c = c + 1; // aritmetica de caracteres
    cout << c << endl;
    // 'A'  = 65
    // 65 + 1 = 66 --> 'B'

    char ch = 'z';
    ch = ch + 1;

    cout << ch << endl;

    // 'z' + 1 ?

    //
    char c1 = 'D';
    c1 = c1 + ('a' - 'A');

    cout << c1 << endl;

    //'a' - 'A' = 32

    return 0;
}