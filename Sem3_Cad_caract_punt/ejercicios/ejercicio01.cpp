/*
Implementar un programa que:

Identifique todas las palabras en un arreglo char texto[].

Almacene punteros al inicio de cada palabra en un arreglo char* palabras[].

Clasifique las palabras en dos grupos:

palabras cortas (longitud ≤ 3)
palabras largas (longitud > 3)
Imprima ambos grupos ordenados alfabéticamente.
*/

#include<iostream>
#include<cstring>
using namespace std;

// swap(v[j], v[j+1]); // Ejercicio, implementar su propia funcion intercambio

void my_swap(char *&a, char *&b)
{
    char *tmp = a;
    a = b;
    b = tmp;
}


// char * strtok ( char * str, const char * delimiters );

int separar_palabras_strtok(char *texto, char *palabras[])
{
    int i = 0;
    char* token = strtok(texto, " ");

    while (token != nullptr)
    {
        palabras[i] = token;
        token = strtok(nullptr, ","); // continua analizando la cadena
        
        i++;
    }
    
}



// Funciones a implementar
int separar_palabras(char *texto, char *palabras[])
{   
    int i = 0; // contador de palabras
    char *p = texto; // alamcena direccion del primer caracter en texto

    while (*p != '\0')
    {
        if ((p == texto && *p != ' ') || (*(p-1) == ' ' && *p != ' '))
        {
            palabras[i] = p;

            i++;
        }

        p++;
    }
    return i;
}


int longitud_palabra(const char *p)
{
    int l = 0;
    while (*p != ' ' && *p != '\0')
    {
        l++;
        p++;
    }
    return l;
}


void clasificar(char *palabras[], int n,
                char *cortas[], int &nc,
                char *largas[], int &nl)
{
    // recorrer el arreglo de punteros palabras
    // clasificar segun su longitud

    for (int i = 0; i < n; i++)
    {
        int longitud = longitud_palabra(palabras[i]);

        if (longitud <= 3)
        {
            cortas[nc] = palabras[i];

            nc++;
        }
        else
        {
            largas[nl] = palabras[i];

            nl++;
        }
        
    }
    
}


int comparar_palabras(const char *a, const char *b)
{
    int i = 0;

    while (a[i] != ' ' && a[i] != '\0' && b[i] != ' ' && b[i] != '\0')
    {
        if (a[i] != b[i])
        {
            return a[i] - b[i]; //
        }
        
        i++;
    }

    if ((a[i] == ' ' || a[i] == '\0') && (b[i] == ' ' || b[i] == '\0'))
    {
        return 0;
    }

    if (b[i] == ' ' || b[i] == '\0')
    {
        return 1;
    }
    
    return -1;
}


void ordenar(char *v[], int n)
{
    for (int i = 0; i < n - 1; ++i) // numero de pasadas
    {
        for (int j = 0; j < n - i - 1; ++j) // intercambios
        {
            if (comparar_palabras(v[j], v[j+1]) > 0)
            {
                my_swap(v[j], v[j+1]);
            }
        }
    }
}


void imprimir_grupo(const char *titulo, char *v[], int n)
{
    cout << "Palabras " << titulo << endl;
    for (int i = 0; i < n; ++i)
    {
        char* p = v[i];

        while (*p != ' ' && *p != '\0')
        {
            cout << *p;
            p++;
        }
        cout << endl;
    }
    cout << endl;
}


int main()
{
    //Datos de entrada
    char texto[300] = "programar en c++ requiere logica c++ exige disciplina";
    char *palabras[60];
    char *cortas[60];
    char *largas[60];

    int n = separar_palabras(texto, palabras);

    imprimir_grupo(" Originales:", palabras, n);

    int nc = 0, nl = 0;
    
    clasificar(palabras, n, cortas, nc, largas, nl);

    ordenar(cortas, nc);
    ordenar(largas, nl);

    imprimir_grupo(" Palabras cortas (longitud ≤ 3):", cortas, nc);
    imprimir_grupo(" Palabras largas (longitud > 3):", largas, nl);

    return 0;
}

