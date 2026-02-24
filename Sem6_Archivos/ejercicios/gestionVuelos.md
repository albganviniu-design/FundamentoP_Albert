# REPASO: Sistema de Gestión de Vuelos

Desarrollar un sistema en C++ que permita gestionar los vuelos de un aeropuerto aplicando:

- Estructuras (`struct`)
- Arreglos dinámicos
- Asignación dinámica (`new` / `delete`)
- Listas enlazadas
- Validaciones lógicas
- Manejo de archivos (texto y binario)
- Liberación correcta de memoria
---

# PARTE I – MODELO EN MEMORIA

## Estructuras base

### Pasajero

```cpp
struct Pasajero {
    int dni;
    char nombre[50];
};
```
### Asiento
```cpp
struct Asiento {
    int numero;
    bool reservado;
    Pasajero* pasajero;   // nullptr si está libre
};
```
Reglas:
- Cuando se reserve un asiento, se debe crear dinámicamente un Pasajero.
- Cuando se cancele una reserva, se debe liberar la memoria con delete.

---

### NodoReserva (Lista Enlazada)

```cpp
struct NodoReserva {
    Pasajero pasajero;
    int numeroAsiento;
    NodoReserva* siguiente;
};
```
---

### Vuelo

```cpp
struct Vuelo {
    char codigo[10];
    char destino[50];
    int capacidad;
    Asiento* asientos;          // arreglo dinámico
    NodoReserva* listaReservas; // lista enlazada
};
```
---

# FUNCIONALIDADES

El programa debe implementar un menú interactivo.

---
## 1. Crear Vuelo

Solicitar:
- Código
- Destino
- Capacidad

Debe:

- Reservar dinámicamente el arreglo de asientos:
  ```cpp
    vuelo.asientos = new Asiento[capacidad];
    ```

- Inicializar cada asiento:
  ```cpp
      numero = i + 1
      reservado = false
      pasajero = nullptr
  ```

- Inicializar listaReservas en nullptr.

---

## 2. Mostrar Mapa de Asientos

Ejemplo de salida:

    Vuelo: LA123 - Lima

    Asientos:
    1 [X]
    2 [ ]
    3 [X]
    4 [ ]

Donde:
- [X] = ocupado
- [ ] = libre

---

## 3. Reservar Asiento

Solicitar:

- DNI
- Nombre
- Número de asiento

Validaciones a implementar:

1. El asiento debe existir (rango válido).
2. El asiento no debe estar reservado.
3. El pasajero no debe estar ya en la lista enlazada.

Si es válido:

- Crear dinámicamente un Pasajero.
- Asignarlo al asiento.
- Insertar un nodo en la lista enlazada.

---

## 4. Cancelar Reserva

Solicitando DNI, debe:

1. Buscar en la lista enlazada.
2. Si existe:
   - Liberar memoria del pasajero del asiento.
   - Marcar asiento como libre.
   - Eliminar nodo correctamente (caso cabeza, intermedio o último).
3. Si no existe:
   - Mostrar mensaje adecuado.

---

## 5. Mostrar Lista de Pasajeros

Recorrer la lista enlazada y mostrar:

    DNI - Nombre - Asiento

---

## 6. Mostrar Estadísticas

Calcular:

- Total de asientos
- Asientos ocupados
- Asientos libres
- Porcentaje de ocupación

Expresión:

    ocupacion = (ocupados * 100.0) / capacidad;

---

## 7. Liberar Memoria Antes de Salir

Debe existir una función que:

- Recorra el arreglo y elimine cada Pasajero dinámico.
- Elimine todos los nodos de la lista enlazada.
- Elimine el arreglo dinámico con delete[].

---

# PARTE II – MANEJO DE ARCHIVOS

---

## 8. Generar Reporte en Archivo de Texto

Nombre del archivo:

    reporte_<codigo>.txt

Contenido mínimo:

    *** REPORTE DE VUELO ***
    Codigo: LA123
    Destino: Lima
    Capacidad: 10
    Ocupados: 4
    Libres: 6
    Porcentaje: 40%

    Lista de Pasajeros:
    12345678 - Ever Meza - Asiento 2

Requisitos:

- Usar ofstream.
- Verificar apertura.
- Cerrar archivo correctamente.

---

## 9. Guardar Reservas en Archivo Binario

Archivo:

    reservas_<codigo>.dat

Guardar por cada reserva:

- DNI
- Nombre
- Número de asiento

Ejemplo de estructura auxiliar:

    struct RegistroBinario {
        int dni;
        char nombre[50];
        int asiento;
    };

Escritura:

    archivo.write((char*)&registro, sizeof(registro));


## 10. Variantes opcionales

1. Permitir múltiples vuelos.
2. Buscar vuelo por código.
3. Ordenar pasajeros por DNI antes de generar reporte.
4. Separar asientos por clase.
5. Cargar reservas desde archivo al iniciar el programa.

---

