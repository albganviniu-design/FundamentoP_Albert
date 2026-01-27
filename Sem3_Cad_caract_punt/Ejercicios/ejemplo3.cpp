#include <iostream>
using namespace std;

int main()
{
    char arr1[5] = {'H', 'o', 'l', 'a', '!'}; // arreglo de caracteres // falta el caractere nulo '\0'
    char arr2[5] = "Hola"; // es una cadena

    cout << arr1[0] << endl;
    cout << arr2 << endl;

    return 0;
}