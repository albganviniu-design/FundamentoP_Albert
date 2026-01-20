#include<iostream>
using namespace std;

int superdigito(int n)
{
    if (n<=9)
    {
        return n; //caso base
    }

    int ns;
    int sum=0;

    if (n>=10)
    {

        do
        {
            ns=n%10;
            n=n/10;
            sum=sum+ns;

        } while (n>=10);
        sum=sum+n;
    }
    return superdigito(sum); // recursion
    
}

int main()
{
    int n;

    cout << endl << "Escriba un numero entero no negativo:";
    cin >> n;

    if (n<0)
    {
        cout << endl << "Error, valor no valido vuelva a intentarlo el numero debe ser un entero no negativo" << endl << endl;
    }
    else
    {
        cout << "El superdigito del numero es: " << superdigito(n) << endl << endl;
    }
    
    return 0;
}
