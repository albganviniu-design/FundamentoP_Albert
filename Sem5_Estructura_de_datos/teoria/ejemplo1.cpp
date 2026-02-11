#include<iostream>
using namespace std;

// 1. DEFINICION DE UNA VARIABLE DEFINIDA POR EL USUARIO
struct Estudiante
{
    int codigo; // miembro de datos
    float promedio;
    char sexo;
}; // CUIDADO


// 6. Estructuras anidadas
struct Fecha
{
    int dia;
    int mes;
    int anio;
};

struct Alumno
{
    int codigo;
    Fecha nacimiento;
};

// 8. Paso de estructuras como parametros de funciones

// Paso por valor (copiamos contenido)
void mostrar(Estudiante e1)
{
    cout << e1.codigo;
}
// Paso por referencia (util para programas eficientes y para modificar datos)
void aumentarPromedio(Estudiante &e1)
{
    e1.promedio += 1;
}

float calcularPromedio(Estudiante e1[], int n)
{

}


int main()
{
    // 2. Declaracion de una estructura
    Estudiante e1 = {25694, 18.5, 'M'};
    Estudiante e2 = {25695, 12.5, 'F'};

    // 3. Inicializacion
    // 3.1. Inicializacion directa (lo de arriba)

    // 3.2 Inicializacion miembro a miembro
    Estudiante e3;

    e3.codigo = 1234; // Operador punto
    e3.promedio = 11.2;
    e3.sexo = 'M';

    // 3.3. Asignacion entre estructuras
    Estudiante e4 = e3;

    // 4. Lectura y escritura de estructuras

    // LECTURA
    Estudiante e5;
    cout << "Ingrese el codigo: ";
    cin >> e5.codigo;

    cout << "Ingrese el promedio: ";
    cin >> e5.promedio;

    cout << "Ingrese el sexo: ";
    cin >> e5.sexo;

    // ESCRITURA
    cout << "Codigo: " << e5.codigo << endl;
    cout << "Promedio: " << e5.promedio << endl;
    cout << "Sexo: " << e5.sexo << endl;

    // 5. Arreglo de estructuras

    Estudiante A[3]; // Define un arreglo de 3 estucturas

    // Codigo para leer los miembros del arreglo A
    // LECTURA DEL ARREGLO DE ESTRUCTURAS
    for (int i = 0; i < 3; i++)
    {
        cout << "Alumno " << i+1 << endl;
        cout << "Ingrese el codigo: ";
        cin >> A[i].codigo;

        cout << "Ingrese el promedio: ";
        cin >> A[i].promedio;

        cout << "Ingrese el sexo: ";
        cin >> A[i].sexo;
    }

    // ESCRITURA DEL ARRGLO DE ESCRITURAS
    for (int i = 0; i < 3; i++)
    {
        cout << "Alumno " << i + 1 << endl;
        cout << "Codigo: " << A[i].codigo;
        cout << "Promedio: " << A[i].promedio;
        cout << "Sexo: " << A[i].sexo;
    }

    // 6. Uso de estructuras anidadas

    Alumno a1;

    // inicializo codigo
    a1.codigo = 1234;

    // inicializo nacimiento
    a1.nacimiento.dia = 12;
    a1.nacimiento.mes = 10;
    a1.nacimiento.anio = 2025;

    // 7. Puntero a estructura
    Estudiante e6 = {123, 14.5, 'F'};
    Estudiante *ptr;

    ptr = &e6; // *ptr = *&e6 = e6;

    // Acceso mediante ptr a los miembros de la estructura
    // PRIMERA FORMA (usando operador flecha ->)
    // -> solo funciona si ptr es un puntero
    cout << ptr -> codigo << endl;
    cout << ptr -> promedio << endl;
    cout << ptr -> sexo << endl;

    // SEGUNDA FORMA
    cout << (*ptr).codigo << endl; // importante el parentesis o sino tendra mas prioridad el punto y si eso es primero da ERROR

    // (*ptr).codigo <> ptr -> codigo;




    return 0;
}