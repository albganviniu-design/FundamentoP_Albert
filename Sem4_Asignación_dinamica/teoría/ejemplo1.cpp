#include<iostream>
using namespace std;

int main()
{
    //int a[100]; // arreglo estatico en el Stack

    int *ptr = new int[100]; // reserva memoria en el Heap

    // Liberamos memoria

    delete [] ptr;

    return 0;
}