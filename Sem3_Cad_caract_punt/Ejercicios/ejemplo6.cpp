#include <iostream>
#include <cstring> // strlen(), strcpy, strcat(), strcmp()
using namespace std;

// Utilizando punteros, implementar
// su propia funcion que permita
// calcular la longitud de una cadena

// recorrer la cadena y contar los caracteres

int my_strlen(const char *str)
{
    //int contador = 0; // puede ser con un contador tambien
    const char* p = str;
    while (*p != '\0')
    {
        p++; 
    }

    return p-str;
}


char* my_strcpy(char* destination, const char* source)
{
    char* inicio = destination;

    while (*source != '\0')
    {
        *destination = *source; // copia caracter a caracter
        destination++; // <> destination = destination + 1
        source++;
    }

    *destination = '\0';

    return inicio;
}

char* my_strcat(char *destination, const char *source)
{
    char* inicio = destination;

    while (*destination != '\0')
    {
        destination++;
    }

    while (*source != '\0')
    {
        *destination++ = *source++;
    }

    *destination = '\0';

    return inicio;
}


int my_strcmp(const char *str1, const char *str2)
{
    while (*str1 != '\0' && *str2 != '\0')
    {
        if (*str1 != *str2)
        {
            return *str1 - *str2;
        }
        str1++;
        str2++;
    }

    return *str1 - *str2;
}


int main()
{
    char cad[] = "Fundamentos de Programacion"; // salida 27

    cout << endl << "Longitud con strlen: " << strlen(cad) << endl;
    cout << "Longitud: " << my_strlen(cad) << endl;

    char destino[50];
    const char origen[] = "Fundamentos de Programacion";

    // Llamar a la funcion my_strcpy

    cout << endl << "Cadena copiada: " << my_strcpy(destino, origen) << endl;
    cout << "Copia con strcpy: " << strcpy(destino, origen) << endl;

    char destino1[50] = "Fundamentos";
    char destino2[50] = "Fundamentos";
    const char origen1[] = " de Programacion";

    // Llamar a my_strcat

    cout << endl << "Concatena con my_strcat: " << my_strcat(destino1, origen1) << endl;
    cout << "Concatena con strcat: " << strcat(destino2, origen1) << endl;

    // Llamar a my_strcmp

    cout << endl << my_strcmp("Hola", "Hola") << endl; // 0
    cout << my_strcmp("Hola", "Holb") << endl; // negativo
    cout << my_strcmp("Holb", "Hola") << endl; // positivo

    return 0;
}
