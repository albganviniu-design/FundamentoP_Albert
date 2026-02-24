# Archivos en C++

## 1. Introducción 
En programación, los archivos permiten almacenar información de manera persistente, es decir, que los datos sobrevivan a la ejecución del programa.

Sin archivos:

* Todo se pierde al terminar el programa.

* Solo existe almacenamiento en memoria (RAM).

Con archivos:

* Podemos guardar estructuras complejas.

* Podemos construir sistemas reales (sistemas académicos, inventarios, etc.).


En C++, el manejo de archivos se realiza mediante la biblioteca:

`#include <fstream>`


## 2. Flujos de Entrada y Salida (I/O Streams)
C++ usa el concepto de flujo (stream): una abstracción de datos que fluyen desde un origen hacia un destino.

**Flujos básicos**

| Clase      | Uso               |
| ---------- | ----------------- |
| `ifstream` | Leer archivos     |
| `ofstream` | Escribir archivos |
| `fstream`  | Leer y escribir   |


**Ejemplo básico: escribir en archivo**

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream archivo("datos.txt");

    if (!archivo) { // Buena práctica, verificar si el archivo se abrió correctamente
        cout << "Error al abrir el archivo\n";
        return 1;
    }

    archivo << "Hola mundo\n";
    archivo << 25 << endl;

    archivo.close();
}
```


## 3.  Texto vs Binario – Estados del Stream

### Archivo de texto

* Legible por humanos

* Usa formato ASCII


### Archivo binario

* Guarda datos en memoria tal como están

* Más eficiente

* No legible directamente



### Estados del stream

| Método    | Significado    |
| --------- | -------------- |
| `.good()` | Todo correcto  |
| `.fail()` | Fallo lógico   |
| `.eof()`  | Fin de archivo |
| `.bad()`  | Error grave    |


## 4. Archivos de Texto

**Ejemplo**  
Guardar N estudiantes ingresados dinámicamente en un archivo de texto.


```cpp
// Definición
struct Estudiante {
    int codigo;
    char nombre[50];
    float promedio;
};

```


```cpp
// Función para escribir archivo
void guardarTexto(Estudiante* arr, int n) {
    ofstream archivo("estudiantes.txt");

    for (int i = 0; i < n; i++) {
        archivo << arr[i].codigo << " "
                << arr[i].nombre << " "
                << arr[i].promedio << endl;
    }

    archivo.close();
}
```

* arr es un puntero a estructura


* Se usa indexación como arreglo


* No se guarda la estructura como bloque


* Se serializa campo por campo



## 5. Modos de Acceso

| Modo          | Significado           |
| ------------- | --------------------- |
| `ios::in`     | Lectura               |
| `ios::out`    | Escritura             |
| `ios::app`    | Añadir al final       |
| `ios::binary` | Modo binario          |
| `ios::ate`    | Posicionarse al final |


**Ejemplo**
`
ofstream archivo("datos.txt", ios::app);
`

## 6. Archivo Secuencial
Un archivo secuencial se procesa de principio a fin.

### Ejercicio 

Leer archivo de texto y calcular promedio general usando función recursiva.


``` cpp
// Función recursiva
float sumaRecursiva(float* arr, int n) {
    if (n == 0) return 0;
    return arr[n-1] + sumaRecursiva(arr, n-1);
}

```

```cpp
// Solución completa
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream archivo("estudiantes.txt");

    Estudiante temp;
    float* promedios = new float[100];
    int n = 0;

    while (archivo >> temp.codigo >> temp.nombre >> temp.promedio) {
        promedios[n++] = temp.promedio;
    }

    float suma = sumaRecursiva(promedios, n);

    cout << "Promedio general: " << suma / n;

    delete[] promedios;
    archivo.close();
}
```


**Errores frecuentes**

* No liberar memoria

* No verificar archivo

* No validar división por cero



## 7. Archivo Binario
Este tipo de archivos sí permite guardar la estructura completa en bloque.

**Ejemplo**

```cpp
void guardarBinario(Estudiante* arr, int n) {
    ofstream archivo("estudiantes.dat", ios::binary);

    archivo.write(reinterpret_cast<char*>(arr), n * sizeof(Estudiante));

    archivo.close();
}
```

* `reinterpret_cast<char*>` es necesario porque: `write()` trabaja con secuencia de bytes

* Necesita puntero a `char`


**Errores frecuentes**

* No usar estructuras con punteros internos en binario sin serialización manual.

**Ejemplo peligroso**

```cpp
struct Nodo {
    int dato;
    Nodo* siguiente; //  no guardar directamente
};
```

* Guardar esto en binario rompe la estructura.

## 8. Archivos de Acceso Aleatorio
Permite ir directamente a una posición específica.

**Funciones:**

| Función   | Uso                     |
| --------- | ----------------------- |
| `seekg()` | mover puntero lectura   |
| `seekp()` | mover puntero escritura |
| `tellg()` | posición actual         |


**Ejemplo:** modificar estudiante específico

```cpp
void modificarPromedio(int posicion, float nuevoPromedio) {
    fstream archivo("estudiantes.dat", ios::in | ios::out | ios::binary);

    archivo.seekp(posicion * sizeof(Estudiante));

    Estudiante e;
    archivo.read(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    e.promedio = nuevoPromedio;

    archivo.seekp(posicion * sizeof(Estudiante));
    archivo.write(reinterpret_cast<char*>(&e), sizeof(Estudiante));

    archivo.close();
}
```

* El archivo se comporta como un arreglo persistente:
[Est0][Est1][Est2][Est3]

* Cada bloque ocupa `sizeof(Estudiante)` bytes.

### Ejercicio

Crear un sistema que:

* Permita registrar estudiantes dinámicamente.

* Los guarde en binario.

* Permita modificar uno usando acceso aleatorio.

* Permita mostrar todos.

* Calcule promedio.


