#include <iostream>
using namespace std;

// Clase base

// REGLA PRACTICA

// CAda vez que implementemos herencia y polimorfismo
// en clases, usar DESTRUCTORES VIRTUALES

class Animal
{

public:
    virtual void id()
    {                     // no es virtual , enlace estático
        cout << "animal"; // siempre se ejecuta este método
    }

    virtual ~Animal() { cout << "destructor Animal" << endl; }
};

// Clases derivadas

class Cat : public Animal
{ // hereda de Animal

public:
    virtual void id() override
    {
        cout << "cat";
    }
    virtual ~Cat() { cout << "destructor Cat" << endl; }
};

class Dog : public Animal
{

public:
    virtual void id() override
    {
        cout << "dog";
    }
    virtual ~Dog() { cout << "destructor Dog" << endl; }
};

int main()
{

    // Arreglo de punteros tipo Animal
    // Puede almacenar direcciones de objetos Animal o derivados

    Animal *pA[] = {new Animal, new Dog, new Cat};
    for (int i = 0; i < 3; i++)
    {
        pA[i]->id();
        cout << endl;
    }

    // Liberar memoria
    for (int i = 0; i < 3; i++)
    {
        delete pA[i];
    }
}

// ***********************************

// #include <iostream>
// using namespace std;

// // ============================
// // Clase base
// // ============================

// class Animal {
// public:
//     // Función virtual → permite polimorfismo
//     virtual void id() {
//         cout << "animal";
//     }

//     // Destructor virtual → garantiza liberación completa de objetos derivados
//     virtual ~Animal() {
//         cout << "destructor Animal" << endl;
//     }
// };

// // ============================
// // Clases derivadas
// // ============================

// class Cat : public Animal {
// public:
//     void id() override {   // override es opcional, pero recomendado
//         cout << "cat";
//     }

//     ~Cat() override {     // Destructor virtual implícito gracias a override
//         cout << "destructor Cat" << endl;
//     }
// };

// class Dog : public Animal {
// public:
//     void id() override {
//         cout << "dog";
//     }

//     ~Dog() override {
//         cout << "destructor Dog" << endl;
//     }
// };

// // ============================
// // Función principal
// // ============================

// int main() {
//     // Arreglo de punteros a Animal (puede apuntar a objetos derivados)
//     Animal* pA[] = {new Animal, new Dog, new Cat};

//     // Polimorfismo en acción: llamada correcta a id() según objeto real
//     for (int i = 0; i < 3; i++) {
//         pA[i]->id();   // Se llama al método correcto en tiempo de ejecución
//         cout << endl;
//     }

//     // Liberación de memoria correcta
//     for (int i = 0; i < 3; i++) {
//         delete pA[i];  // Llama al destructor derivado y luego al de la base
//     }

//     return 0;
// }