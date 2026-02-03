#include <iostream>
using namespace std;

bool esVocal(char c)
{
    if (c >= 'A' && c <= 'Z') // pasamos a minusculas
    {
        c = c + ('a' - 'A');
    }

    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int palabras_con_vocal(const char *texto)
{
    int contador = 0;
    bool inicioPalabra = true;

    while (*texto != '\0')
    {
        if (*texto == ' ') // si hay espacio simplemente pasa al siguiente
        {
            inicioPalabra = true;
        }
        else if (inicioPalabra) // cuando deja de haber espacio verifica que iniciopalabra sea verdad para confirmar que es la primera letra
        {
            if (esVocal(*texto)) // verifica que si la letra es vocal entonces sube +1 el contador
            {
                contador++;
            }

            inicioPalabra = false; // falso hasta que vuelva a ver espacio haci sabemos que no es la primera letra
        }

        texto++; 
    }

    return contador;
}

int main()
{
    const char *texto = "Este es un ejemplo en C++ END";

    cout << "Texto: " << texto << endl;
    cout << "Numero de palabras que comienzan con vocal: " << palabras_con_vocal(texto) << endl;

    return 0;
}
