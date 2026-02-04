# Ejercicios de repaso

## Ejercicio 1 (Asignación dinámica)
Implementar un programa  que realice las
siguientes tareas sobre una frase ingresada por el usuario:

1.1. Leer una frase de longitud desconocida.

1.2. Almacenar la frase usando asignación dinámica exacta (ni más ni menos memoria).

1.3. Normalizar la frase:

    - Eliminar espacios múltiples.
    
    - Convertir todas las letras a minúsculas
    
1.4. Contar cuántas palabras tiene la frase.

1.5. Construir dinámicamente un arreglo de palabras, donde cada palabra es un `char*` independiente.

1.6. Mostrar cada palabra junto con su longitud.

1.7. Liberar toda la memoria dinámica correctamente.
    ` `


## Ejercicio 2 (Punteros)

Se tiene una matriz estática cuadrada de enteros `M` de tamaño fijo `N × N`, con `N ≥ 3`.  
La matriz se declara en la función `main` de la siguiente forma:

```cpp
const int N = 5;
int M[N][N];
```
La matriz representa una estructura de relaciones entre filas y columnas.

Utilice aritmética de punteros e implemente las siguientes funciones:


1. `bool esFilaDominante(int (*M)[N], int fila);`

    Una fila se considera dominante si cada uno de sus elementos es estrictamente mayor que el elemento correspondiente de todas las demás filas en la misma columna.

2. `int contarColumnasCriticas(int (*M)[N]);`

    Una columna se considera crítica si la suma de sus elementos es mayor que la suma de cualquier fila de la matriz.

    La función debe retornar la cantidad total de columnas críticas.

3. `bool esMatrizEscalonada(int (*M)[N]);`

    Una matriz es escalonada si, para cada fila, la posición del primer elemento no nulo aparece en una columna estrictamente mayor que la del primer elemento no nulo de la fila anterior.

4. `int valorNucleo(int (*M)[N]);`

    El núcleo de la matriz es un elemento que cumple simultáneamente:

    - Es el máximo de su fila

    - Es el mínimo de su columna

    La función debe retornar el valor del núcleo.
Si no existe ningún elemento que cumpla ambas condiciones, retornar -1.




## Ejercicio 3 (Ordenamiento y búsqueda)

La escuela desea analizar el rendimiento de sus estudiantes del curso de Fundamentos de Programación. Para ello se cuenta con la siguiente información de N estudiantes:

* Código del estudiante (entero, único)
* Nota final (0 – 20)
* Número de inasistencias

La información no está ordenada y proviene de diferentes fuentes.


3.1. Implementar una función que:

    - Lea los datos de N estudiantes
    
    - Almacene la información en arreglos paralelos
```cpp
int codigo[N];
float nota[N];
int faltas[N];
```

3.2. Ordenar los estudiantes de mayor a menor nota, manteniendo la relación entre:

    código ↔ nota ↔ faltas

Condición: si dos estudiantes tienen la misma nota, el que tiene menos faltas va primero.

`void ordenarPorNota(float nota[], int codigo[], int faltas[], int n);`



3.3. Mostrar el ranking académico:

* Top 5 estudiantes

* Promedio del curso

* Número de desaprobados (nota < 10)


3.4. Implementar: Búsqueda secuencial: Buscar un estudiante por su código e imprimir: Nota, Faltas, Posición en el ranking

3.5. Reordenar los datos por código ascendente (ya no por nota).

Use Selection Sort o Insertion Sort


3.6. Una vez ordenado por código: Implementar búsqueda binaria

`int busquedaBinaria(int codigo[], int n, int clave);`




## Ejercicio 4 (recursividad)

Dado un arreglo unidimensional A de n (máximo 15) números enteros positivos. Se desea dividir el arreglo en segmentos contiguos, cumpliendo las siguientes condiciones:

* Cada segmento debe contener al menos un elemento.

* El valor de un segmento se define como el producto de todos sus elementos.

* El costo total de una segmentación es la suma de los valores de todos los segmentos.

Implementar una función recursiva para determinar el costo mínimo posible que se puede obtener al segmentar el arreglo.

