#include <iostream>
using namespace std;

int guardarDirecciones(char* texto, char** indice)
{
    int n = 0;
    bool inicioPalabra = true;

    while (*texto != '\0')
    {
        if (*texto != ' ' && inicioPalabra)
        {
            *(indice + n) = texto;
            n++;
            inicioPalabra = false;
        }
        else if (*texto == ' ')
        {
            inicioPalabra = true;
        }
        texto++;
    }

    return n;
}

int comparar(const char* a, const char* b)
{
    while (*a != '\0' && *b != '\0')
    {
        if (*a < *b) 
        {
            return -1;
        }
        if (*a > *b) 
        {
            return 1;
        }
        a++;
        b++;
    }

    if (*a == '\0' && *b == '\0') 
    {
        return 0;
    }
    if (*a == '\0') 
    {
        return -1;
    }
    return 1;
}

void ordenarIndice(char** indice, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (comparar(*(indice + i), *(indice + j)) > 0)
            {
                char* tmp = *(indice + i);
                *(indice + i) = *(indice + j);
                *(indice + j) = tmp;
            }
        }
    }
}

void imprimir(char* texto, char** indice, int n)
{
    int maxLen = 0;

    for (int i = 0; i < n; i++)
    {
        int len = 0;
        char* p = *(indice + i);

        while (*p != '\0' && *p != ' ')
        {
            len++;
            p++;
        }

        if (len > maxLen)
        {
            maxLen = len;
        }
    }

    for (int i = 0; i < n; i++)
    {
        char* p = *(indice + i);
        int pos = p - texto;
        int len = 0;

        while (*p != '\0' && *p != ' ')
        {
            cout << *p;
            p++;
            len++;
        }

        while (len < maxLen + 4)
        {
            cout << " ";
            len++;
        }

        cout << "(posicion " << pos << ")\n";
    }
}

int main()
{
    char texto[] = "los punteros no se copian se referencian y se ordenan";
    char* indice[20];

    int n = guardarDirecciones(texto, indice);
    ordenarIndice(indice, n);

    cout << "Salida:\n";
    imprimir(texto, indice, n);

    return 0;
}
