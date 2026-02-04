// Ejercicio 1
#include<iostream>
#include<cstring> // para usar strlen
#include<cctype> // tolower() combierte a minusculas las letras
using namespace std;

// 1.1 y 1.2
// Leer una frase de longitud desconocida y almacenar usando asignacion dinameca exacta.
char* leerFrase()
{
    char temp[1000]; // string temp;
    cout << "Ingrese una frase: ";
    cin.getline(temp,1000);

    int len = strlen(temp);
    // realizar la asignacion dinamica
    char *frase = new char[len + 1];

    for (int i = 0; i <= len; i++)
    {
        frase[i] = temp[i];
    }
    
    return frase;
}


// 1.3. Normalizar frase:
// - Eliminar espacios múltiples.
// - Convertir todas las letras a minúsculas
char* normalizarFrase(char* frase)
{
    char temp[1000];
    int i = 0;
    int j = 0;
    bool esEspacio = true;

    // Saltar espacios iniciales
    while (isspace(frase[i]))
    {
        i++;
    }

    while (frase[i] != '\0')
    {
        if (!isspace(frase[i]))
        {
            temp[j] = tolower(frase[i]);
            j++;
            esEspacio = false;
        }
        else if(!esEspacio)
        {
            temp[j] = ' ';
            ++j;
            esEspacio = true;
        }
        ++i;
    }

    if (j > 0 && temp[j - 1] == ' ')
    {
        j--;
    }

    temp[j] = '\0';

    char *normalizada = new char[j + 1];
    for (int k = 0; k <= j; k++)
    {
        normalizada[k] = temp[k];
    }
    
    return normalizada;
}


// 1.4. Contar cuántas palabras tiene la frase.
int contarPalabras(char * frase)
{
    int cont = 0;
    bool estoyPalabra = false;

    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (!isspace(frase[i]) && !estoyPalabra)
        {
            cont++;
            estoyPalabra = true;
        }
        if (isspace(frase[i]))
        {
            estoyPalabra = false;
        }
     }
     return cont;
}


// 1.5. Construir dinámicamente un arreglo de palabras, donde cada palabra es un char* independiente.
char** separarPalabras(char* frase, int n)
{
    char** palabras = new char*[n];

    int i = 0; // para recorres frases
    int j = 0; // para manipular indices de palabras[j]

    while (frase[i] != '\0' && j < n)
    {
        while (isspace(frase[i]))
        {
            i++;
        }
        
        int inicio = i;
        int len = 0;

        while (frase[i] != '\0' && !isspace(frase[i]))
        {
            i++;
            len++;
        }
        
        palabras[j] = new char[len + 1];
        
        for (int k = 0; k < len; k++)
        {
            palabras[j][k] = frase[inicio + k];
        }
        palabras[j][len] = '\0';

        j++;
    }
    return palabras; // Como libero memoria dinamica
}


// 1.6. Mostrar cada palabra junto con su longitud.
void mostrarPalabras(char** palabras, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << palabras[i] << "\t" << strlen(palabras[i]) << endl;
    }
}

// 1.7. Liberar toda la memoria dinámica correctamente.
void liberarMemoria(char** palabras, int n)
{
    for (int i = 0; i < n; i++)
    {
        delete [] palabras [i];
    }
    delete [] palabras;
}

int main()
{
    char *frase = leerFrase(); // debo liberar memoria

    char *normalizada = normalizarFrase(frase); // debo liberar memoria

    int numPal = contarPalabras(normalizada);

    char** palabras = separarPalabras(normalizada, numPal); // debo liberar memoria

    mostrarPalabras(palabras, numPal);

    delete[] frase;
    frase = nullptr;

    delete[] normalizada;
    normalizada = nullptr;

    liberarMemoria(palabras, numPal);
    palabras = nullptr;

    return 0;
}