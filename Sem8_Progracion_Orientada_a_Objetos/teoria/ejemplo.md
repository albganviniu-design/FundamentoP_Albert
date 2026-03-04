# Ejemplo de programa orientado a objetos

## Objetivo:

Comprender y utilizar los 4 principios básicos de POO
* Abstracción
* Encapsulación
* Herencia
* Polimorfismo

## Ejercicio

Implementar un sistema para gestionar vehículos en una empresa

Existen distintos tipos de vehículos
* Automóvil
* Camión
* Motocicleta

Estos vehículos comparten información
* Placa
* Marca
* Año
* Precio

Cada tipo tiene información adicional
* Automóvil: número de puertas
* Camión: capacidad de carga (ton)
* Motocicleta: Potencia


1. Implementar una clase base: Vehiculo

2. Implementar clases derivadas:
* Automovil
* Camion
* Motocicleta

3. Usar Polimorfismo dinámico para calcular el precio final

* Automóvil: precio final = precio base + 5%
* Camion: precio final = precio base + 12%
* MOtocicleta: precio final = precio base + 3%


4. El sistema debe permitir 
* Registrar vehículos
* Mostrar todos los vehículos
* Guardar los vehículos en una archivo binario
* Leer el archivo binario y construir los objetos correctamente


5. Utilizar múltiples archivos (h. .cpp)