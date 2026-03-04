# Ejercicios de repaso para el examen final


## Ejercicio 1 : Estructuras y asignación dinámica

Se desea modelar  **polinomios dispersos**, es decir polinomios donde muchos coeficientes son cero y no conviene usar arreglos estáticos

Se define un polinomio como la colección dinámica de términos de la forma:
$a_ix^{e_i}$

donde:

* $a_i$ es el coeficiente (double)
* $e_i$ es el exponente entero no negativo

### Parte 1: Definición de estructura

1. Defina una estructura `Termino`  que contenga: el coeficiente y el exponente

2. Defina una estructura `Polinomio` que contenga:

    * Un puntero dinámico a `Término`
    * La cantidad de términos almacenados

 
 ### Parte 2: Gestión dinámica

 Implemente las siguientes funciones:

 1. `crearPolinomio(Polinomio &p, int n)`
    *  Reserva memoria dinámica para n términos.

2. `leerPolinomio(Polinomio &p, int n)`
    * Permite ingresar coeficientes y exponentes

3. `mostrarPolinomio(const Polinomio &p)`
    * Muestra el polinomio en forma matemática ordenada

4. `evaluarPolinomio(const Polinomio &p, double x)`
    * Evalúa el polinomio en un valor dado

5. `derivarPolinomio(const Polinomio &p, Polinomio &der)`
    * Genera dinámicamente el polinomio derivada

6. `liberarPolinomio(Polinomio &p)`
    * Libera la memoria correctamente

<!--
7. `sumarPolinomios(const Polinomio &p1, const Polinomio &p2, Polinomio &resultado)`
    * Construye dinámicamente un polinomio nuevo polinomio suma
-->


## Ejercicio 2: Archivos

Se define la siguiente estructura

```cpp
struct CuentaBancaria {
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};
```

Se tiene un archivo cuentas.dat. Implementar

1. Función para crear el archivo con N cuentas ingresadas por teclado
    * El archivo debe quedar físicamente ordenado en forma creciente según el número de cuenta
    * No se debe permitir números de cuenta repetidos

2. Función que permita buscar una cuenta por número usando acceso directo (no recorrer todo el archivo innecesariamente) 

3. Función que permita depositar o retirar dinero de una cuenta:
    * No permitir saldo negativo
    * No permitir operaciones en cuentas inactivas
    * La modificación debe hacerse directamente en el archivo

4. Función que permita desactivar una cuenta (no borrarla físicamente)

5. Función que muestre únicamente las cuentas activas


## Ejercicio 3: POO

SE necesita diseñar un sistema que permita trabajar con diferentes figuras geométricas en un plano. Se requier eimplementar  un programa orientado a objetos que permita

### 1. Clase abstracta `Figura`
Debe represetnar el concepto general de una figura geométrica

**Atributos privados:**

* string nombre
* double* colorRGB (arreglo dinámico de 3 valores, R, G ,B)

**Métodos públicos:**
* Constructor
* Constructor de copia
* Operador de asignación
* Destructor virtual
* `virtual double area() const = 0`
* `virtual double perimetro() const = 0`
* `virtual double imprimir() const = 0`
* Getters necesarios



### 2 Clases derivadas

clase `Circulo`

* **Atributos:** `double radio`
* Implementa `area()` y `perimetro()`

Clase `Rectangulo`

* **Atributos:** `double base, altura`
* Implementa `area()` y `perimetro()`

* string nombre
* double* colorRGB (arreglo dinámico de 3 valores, R, G ,B)



### 3 Clase gestor de figuras

Debe implementar un arreglo dinámico de punteros a  `Figura`

**Atributos privados:**

* Figura** figuras
* int cantidad
* int capacidad


**Métodos públicos:**
* Constructor
* Destructor
* Método para agregar figura (redimensionando dinámicamente si es necesario)
* Método para mostrar todas (usando polimorfismo)
* Método para calcular el área total
* Método para guardad en archivo de texto



* Constructor de copia
* Operador de asignación
* Destructor virtual
* `virtual double area() const = 0`
* `virtual double perimetro() const = 0`
* `virtual double imprimir() const = 0`
* Getters necesarios






 