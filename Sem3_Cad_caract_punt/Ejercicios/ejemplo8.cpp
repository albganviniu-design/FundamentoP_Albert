#include <iostream>
using namespace std;

int main()
{
    const char* p = "Hola"; // p debe ser const char*
    // p[0] = 'h';             //  comportamiento indefinido

    const char *paises[] = {
        "Peru",
        "Chile",
        "Brasil"};


    return 0;
}