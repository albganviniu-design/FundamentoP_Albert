## Retroalimentación – Problema al leer `notas.txt` en el laboratorio 6

Durante el laboratorio surgió un problema al intentar leer el archivo `notas.txt` desde un programa en C++.  
El código era correcto, pero la lectura fallaba al procesar el primer dato.

### Causa real del problema

El error no estaba en el archivo `ejercicio02.cpp`, sino en la **codificación del archivo de texto**.

En mi entorno de trabajo:

- Uso **VSCode instalado en Windows**
- Trabajo conectado a **WSL (Ubuntu 24.04)**
- VSCode estaba configurado para guardar archivos como **UTF-8 with BOM**
- WSL (Linux) utiliza por defecto **UTF-8 sin BOM**

Esto generó un pequeño “choque cultural de sistemas”.

---

##  ¿Qué ocurrió exactamente?

El archivo `notas.txt` fue guardado con codificación: UTF-8 with BOM en mi PC.

Eso significa que el archivo contiene **tres bytes adicionales invisibles al inicio**:

EF BB BF


Estos bytes corresponden al **Byte Order Mark (BOM)**.

Aunque no son visibles en el editor, sí existen físicamente en el archivo.


---

##  ¿Por qué afectó la lectura en C++?

Recordemos cómo funciona la lectura con `ifstream`:

1. `ifstream` crea un buffer interno.
2. Lee bytes crudos desde el sistema de archivos.
3. El operador de extracción `>>` intenta convertir esos bytes al tipo solicitado (en el ejercicio, `double`).
4. El parser ignora espacios en blanco (`" "`, `\t`, `\n`, `\r\n`).
5. Espera encontrar:
   - un dígito
   - un signo (`+` o `-`)
   - o EOF

El problema era que el archivo no comenzaba con un dígito, el primer byte
- No es espacio en blanco
- No es un dígito
- No es un signo

Por lo tanto:

- El stream entra en estado `failbit`
- La conversión falla
- La lectura del primer valor no se realiza correctamente

---



##  Solución (si tienen el mismo problema)

En VSCode: Seleccionar **"Save with Encoding"**. Elegir **UTF-8** (sin BOM). Guardar nuevamente el archivo.
