#include <iostream>
using namespace std;

void tablaASCCI()
{
    for (int i = 0; i < 128; i++)
    {
        cout << i << " le corresponde " << (char)i << endl;
    }
    
}

int main()
{
    char c1 = 'A';
    char c2 = 'a';
    char c3 = '0';

    cout << (int)c1 << endl;
    cout << (int)c2 << endl;
    cout << (int)c3 << endl;

    char x = '9';

    if (x > '5')
    {
        cout << endl
             << "Mayor" << endl;
    }

    tablaASCCI();

    return 0;
}