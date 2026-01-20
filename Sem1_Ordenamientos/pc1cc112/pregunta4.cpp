#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void imprimir(int arr[][8], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}


int main(){

    int matriz[8][8];

    int n;

    do {
        cout << "Ingrese la dimension (entre 2 - 8): ";
        cin >> n;

    } while (n < 2 || n > 8);

    // generando elementos aleatorios
    srand(time(0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matriz[i][j] = rand() % 1001;
        }
    }



    imprimir(matriz, n);

    // Implementar ordenamiento por seleccion   (Tareas)




    return 0;
}