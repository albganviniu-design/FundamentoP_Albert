#include <iostream>
#include <fstream> // para manipular archivos
#include <cstring>
using namespace std;

// Parte 1. Prototipos ---> archivos de encabezado

void escribirArchivo(const string & nombreArchivo, const string & nombre, int nota); // ok
void leerArchivo(const string & nombreArchivo); //Ok

void leerMostrarAprobados(const string & nombreArchivo); // Completar

// ------------------------------------------------
// Archivos binarios
// PARA TRABAJAR CON ARCHIVOS BINARIOS, DEBEMOS USAR  char[], en lugar de string
struct Estudiante {
    char nombre[50];
    int nota;
};

void escribirBinario(const string& nombreArchivo, const string & nombre, int nota); // ok

void leerBinario(const string & nombreArchivo); // ok

void modificarNotaBinario(const string & nombreArchivo, const string & nombre, int nuevaNota); // Completar




// Parte 3: Aplicacion
int main(){

    string nombreArchivo = "notas.txt";

    // Escritura en un archivo de texto
    escribirArchivo(nombreArchivo, "Juan", 9);
    escribirArchivo(nombreArchivo, "Pedro", 11);
    escribirArchivo(nombreArchivo, "Maria", 8);


    // Leemos el archivo y lo mostramos en consola
    leerArchivo(nombreArchivo);

    
    // Agremamos otros estudiantes
    escribirArchivo(nombreArchivo, "Pablo", 12);
    escribirArchivo(nombreArchivo, "Mercedes", 13);
    escribirArchivo(nombreArchivo, "Julio", 10);

    cout << "Datos agregados correctamente " <<endl;


    // Lectura completa
     leerArchivo(nombreArchivo);

    // ---------------------------
    const string archivoBinario = "notas.dat";

    // Escritura en un archivo BINARIO
    escribirBinario(archivoBinario, "Juan", 9);
    escribirBinario(archivoBinario, "Pedro", 11);
    escribirBinario(archivoBinario, "Maria", 8);

    cout << "\nContenido del archivo binario\n";
    leerBinario(archivoBinario);







    return 0;
}


// Parte 2: Archivos .cpp ----> contienen la implementación

void escribirArchivo(const string & nombreArchivo, const string & nombre, int nota) {
    // Paso 1: Instanciamos un objeto de la clase ofstream

    ofstream archivoEscritura;

    // Paso 2: conectamos con la fuente
    archivoEscritura.open(nombreArchivo, ios::app);

    // Comprobar si el archivo existe
    if (!archivoEscritura) {
        cerr << "Error al abrir el archivo para escritura" <<endl;
        return;
    }


    // Paso 3: Procesar datos, escribir en notas.txt
    archivoEscritura << nombre << " " << nota << endl;
    

    // Paso 4: Desconectamos la fuente/destino
    archivoEscritura.close();  // el destructor se encarga internamente  de desconetar (RAII)
}


void leerArchivo(const string & nombreArchivo) {
    // Lectura de un archivo de texto
    // Paso 1: Instanciamos un objeto de la clase ifstream

    ifstream archivoLectura;

    // Paso 2: conectamos con la fuente
    archivoLectura.open(nombreArchivo);

    // Comprobar si el archivo existe
    if (!archivoLectura) {
        cerr << "Error, no existe el archivo" <<endl;
        return;
    }


    // Paso 3: Procesar datos, leer desde notas.txt
    string nombre;
    int nota;
    while (archivoLectura >> nombre >> nota) { // estados del stream
        cout << nombre << " -- " << nota << endl; // mostramos en consola
    }

    // Paso 4: desconectar de la fuente

    archivoLectura.close();
}


void escribirBinario(const string& nombreArchivo, const string & nombre, int nota) {
    ofstream archivo(nombreArchivo, ios::binary | ios::app); // ACTIVAR EL MODO BINARIO y APP

    if (!archivo) {
        cerr << "error al abrir el archivo";
        return;
    }

    Estudiante e;  // &e
    e.nota = nota;

    strncpy(e.nombre, nombre.c_str(), sizeof(e.nombre));

    e.nombre[sizeof(e.nombre) - 1] = '\0';  // Para asegurarnos


    // ESCRITURA en el archivo binario

    archivo.write((char*)&e, sizeof(Estudiante));

    archivo.close();
}

void leerBinario(const string & nombreArchivo) {

    ifstream archivo(nombreArchivo, ios::binary);

    if (!archivo) {
        cerr << "Error al leer archivo binario" <<endl;
        return;
    }

    Estudiante e;

    while (archivo.read((char*)&e, sizeof(Estudiante))) { // estados del stream
        cout << e.nombre << " -- " << e.nota << endl; // mostramos en consola
    }

    archivo.close();


}

