# Asignación dinámica de memoria en C++

A continuación se detallan algunos ejemplos del manejo correcto de memoria dinámica.


## 1. Arreglos estáticos vs arreglos dinámicos

### 1.1 Arreglos estáticos

```cpp
int a[100];
```
**Características**

* Tamaño fijo en tiempo de compilación
* Se almacenan en el *stack*
* Se destruyen automáticamente al salir del bloque

**Problemas reales**

* Desperdicio de memoria
* Riesgo de *stack overflow*
* No escalables

### 1.2 Arreglos dinámicos

```cpp
int* a = new int[100];
```

**Características**

* Tamaño decidido en tiempo de ejecución
* Memoria en el *heap*
* Vida controlada explícitamente por el programador

> *con memoria dinámica, el poder viene con responsabilidad*

## 2. Memoria dinámica de la PC 

### 2.1 Stack vs Heap

| Stack           | Heap           |
| --------------- | -------------- |
| Automático      | Manual         |
| Rápido          | Más flexible   |
| Tamaño limitado | Gran capacidad |

```cpp
void f() {
    int x = 10;        // stack
    int* y = new int; // heap
}
```

**Error frecuente**: olvidar que `y` **no se libera automáticamente**


## 3. Asignación dinámica: operador `new`

### 3.1 Asignación simple

```cpp
int* p = new int;
*p = 42;
```

#### Error frecuente 1: usar sin inicializar

```cpp
int* p = new int; 
cout << *p;  // valor basura
```

**Corrección**

```cpp
int* p = new int(0);
```

### 3.2 Asignación de arreglos

```cpp
int n;
cin >> n;
int* v = new int[n];
```

#### Error frecuente 2: asumir que el arreglo se inicializa

```cpp
for(int i = 0; i < n; i++)
    cout << v[i];  // valor basura
```


**Corrección**

```cpp
int* v = new int[n](); // inicializa en 0
```

## 4. Liberación de memoria: operador `delete`

### 4.1 Liberación correcta

```cpp
delete p;
p = nullptr;
```

### 4.2 Liberación de arreglos

```cpp
delete[] v;
v = nullptr;
```

---

### 4.3 Errores críticos frecuentes

#### Error 1: olvidar liberar

```cpp
int* v = new int[100];
// no delete[]
```

**Memory leak** (detectable con Valgrind)


#### Error 2: usar `delete` en lugar de `delete[]`

```cpp
int* v = new int[10];
delete v;  // Error
```

> Este error **no siempre falla**, por eso es peligroso



####  Error 3: doble liberación

```cpp
int* p = new int;
delete p;
delete p; // Error
```

Detectado por ASan

## 5. Arreglos dinámicos unidimensionales con punteros

### 5.1 Paso de arreglos dinámicos a funciones

```cpp
void llenar(int* v, int n) {
    for(int i = 0; i < n; i++)
        v[i] = i * i;
}
```

>  El arreglo **no se copia**, se pasa la dirección

### 5.2 Error frecuente: perder la referencia

```cpp
int* v = new int[10];
v = new int[20];  //  fuga de memoria
```

**Corrección**

```cpp
delete[] v;
v = new int[20];
```

## 6. Arreglos multidimensionales dinámicos

### 6.1 Matriz como puntero a punteros

```cpp
int filas = 3, columnas = 4;

int** M = new int*[filas];
for(int i = 0; i < filas; i++)
    M[i] = new int[columnas];
```

### 6.2 Liberación correcta (orden crítico)

```cpp
for(int i = 0; i < filas; i++)
    delete[] M[i];

delete[] M;
```

#### Error frecuente: liberar solo `M`

```cpp
delete[] M; //  fuga masiva
```

### 6.3 Error frecuente: índices fuera de rango

```cpp
M[3][0] = 10;  // fuera de límites
```
Detectado por ASan


