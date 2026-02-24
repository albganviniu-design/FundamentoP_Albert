#include <iostream>
using namespace std;

/*
Recursividad: Es una tecnica, donde una funcion se llama asi misma

CASO BASE:

CASO RECURSIVO:
*/

int factorial(int n) {
    if (n == 0) { // CASO BASE
        return 1;
    }
    return n * factorial (n-1); // CASO RECURSIVO
}

// n = 4 ¿ Cuantas llamadas hace factorial(4)?
// factorial(4)
//  --> factorial(3)
//   --> factorial(2)
//    ---> factorial (1)
//    --->factorial (0)




// Funcion recursiva que sume elementos de un arreglo

int sumaRecursiva(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n-1] + sumaRecursiva(arr,n-1);
}


int main(){



    return 0;
}