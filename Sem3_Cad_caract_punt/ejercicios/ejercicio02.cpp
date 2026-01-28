/*
Implementar un programa que:

Identifique cada palabra dentro del arreglo frase.
Guarde punteros al inicio de cada palabra, sin copiar caracteres.
Use un arreglo de punteros a char (char* palabras[]).
Ordene las palabras alfabéticamente, intercambiando solo punteros.
Imprima las palabras ordenadas leyendo desde los punteros.
La frase original NO debe modificarse.
*/

#include<iostream>
using namespace std;

int separar_palabras(char *frase, char *palabras[]);


int comparar(const char *a, const char *b);


void ordenar(char *palabras[], int n);


void imprimir(char *palabras[], int n);



int main()
{
    char frase[200] = "aprender punteros exige mucha logica y practica"; // arreglo base de caracteres
    char *palabras[50];                                                  // arreglo de punteros a palabras

    return 0;
}

/*
Observaciones: Algunas desventajas de este enfoque

-No es posible conservar palabras fuera del alcance de frase.
-No se pueden crear palabras nuevas ni devolverlas desde una función.
-El tamaño de los arreglos es fijo.
*/