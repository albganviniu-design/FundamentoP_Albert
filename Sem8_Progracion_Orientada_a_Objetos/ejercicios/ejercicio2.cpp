#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct CuentaBancaria
{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

//--------------------------------------------
// Buscar cuenta (búsqueda binaria)
// Devuelve posición o -1 si no existe
//--------------------------------------------
int buscarCuenta(int numeroBuscado)
{
    fstream archivo("cuentas.dat", ios::in | ios::binary);
    if (!archivo)
    {
        return -1;
    }

    archivo.seekg(0, ios::end);
    int total = archivo.tellg() / sizeof(CuentaBancaria);

    int inicio = 0, fin = total - 1;
    CuentaBancaria cuenta;

    while (inicio <= fin)
    {
        int medio = (inicio + fin) / 2;

        archivo.seekg(medio * sizeof(CuentaBancaria));
        archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

        if (cuenta.numeroCuenta == numeroBuscado)
        {
            archivo.close();
            return medio;
        }
        else if (numeroBuscado < cuenta.numeroCuenta)
        {
            fin = medio - 1;
        }
        else
        {
            inicio = medio + 1;
        }
    }

    archivo.close();
    return -1;
}

//--------------------------------------------
// Crear archivo ordenado y sin repetidos
//--------------------------------------------
void crearArchivo()
{
    int N;
    cout << "Cantidad de cuentas a ingresar: ";
    cin >> N;

    CuentaBancaria *cuentas = new CuentaBancaria[N];

    for (int i = 0; i < N;)
    {
        cout << "\nCuenta " << i + 1 << endl;

        cout << "Numero de cuenta: ";
        cin >> cuentas[i].numeroCuenta;

        // Verificar repetidos en memoria
        bool repetido = false;
        for (int j = 0; j < i; j++)
        {
            if (cuentas[i].numeroCuenta == cuentas[j].numeroCuenta)
            {
                repetido = true;
                break;
            }
        }

        if (repetido)
        {
            cout << "Numero repetido. Reingrese.\n";
            continue;
        }

        cout << "Titular: ";
        cin.ignore();
        cin.getline(cuentas[i].titular, 40);

        cout << "Saldo inicial: ";
        cin >> cuentas[i].saldo;

        cuentas[i].activa = true;
        i++;
    }

    // Ordenar por numeroCuenta
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (cuentas[i].numeroCuenta > cuentas[j].numeroCuenta)
            {
                CuentaBancaria aux = cuentas[i];
                cuentas[i] = cuentas[j];
                cuentas[j] = aux;
            }
        }
    }

    ofstream archivo("cuentas.dat", ios::binary);
    archivo.write((char *)cuentas, sizeof(CuentaBancaria) * N);
    archivo.close();

    delete[] cuentas;

    cout << "\nArchivo creado correctamente.\n";
}

//--------------------------------------------
// Depositar o retirar
//--------------------------------------------
void operarCuenta()
{
    int numero;
    double monto;

    cout << "Numero de cuenta: ";
    cin >> numero;

    int pos = buscarCuenta(numero);
    if (pos == -1)
    {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    fstream archivo("cuentas.dat", ios::in | ios::out | ios::binary);
    CuentaBancaria cuenta;

    archivo.seekg(pos * sizeof(CuentaBancaria));
    archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

    if (!cuenta.activa)
    {
        cout << "Cuenta inactiva.\n";
        archivo.close();
        return;
    }

    cout << "Ingrese monto (positivo=deposito, negativo=extraccion): ";
    cin >> monto;

    if (cuenta.saldo + monto < 0)
    {
        cout << "Saldo insuficiente.\n";
        archivo.close();
        return;
    }

    cuenta.saldo += monto;

    archivo.seekp(pos * sizeof(CuentaBancaria));
    archivo.write((char *)&cuenta, sizeof(CuentaBancaria));

    archivo.close();

    cout << "Operacion realizada. Nuevo saldo: " << cuenta.saldo << endl;
}

//--------------------------------------------
// Desactivar cuenta
//--------------------------------------------
void desactivarCuenta()
{
    int numero;
    cout << "Numero de cuenta a desactivar: ";
    cin >> numero;

    int pos = buscarCuenta(numero);
    if (pos == -1)
    {
        cout << "Cuenta no encontrada.\n";
        return;
    }

    fstream archivo("cuentas.dat", ios::in | ios::out | ios::binary);
    CuentaBancaria cuenta;

    archivo.seekg(pos * sizeof(CuentaBancaria));
    archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

    cuenta.activa = false;

    archivo.seekp(pos * sizeof(CuentaBancaria));
    archivo.write((char *)&cuenta, sizeof(CuentaBancaria));

    archivo.close();

    cout << "Cuenta desactivada correctamente.\n";
}

//--------------------------------------------
// Mostrar cuentas activas
//--------------------------------------------
void mostrarActivas()
{
    ifstream archivo("cuentas.dat", ios::binary);
    if (!archivo)
    {
        cout << "No existe archivo.\n";
        return;
    }

    CuentaBancaria cuenta;

    cout << "\n--- CUENTAS ACTIVAS ---\n";

    while (archivo.read((char *)&cuenta, sizeof(CuentaBancaria)))
    {
        if (cuenta.activa)
        {
            cout << "\nNumero: " << cuenta.numeroCuenta;
            cout << "\nTitular: " << cuenta.titular;
            cout << "\nSaldo: " << cuenta.saldo << endl;
        }
    }

    archivo.close();
}

//--------------------------------------------
// MENÚ PRINCIPAL
//--------------------------------------------
int main()
{
    int opcion;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Crear archivo\n";
        cout << "2. Depositar / Retirar\n";
        cout << "3. Desactivar cuenta\n";
        cout << "4. Mostrar cuentas activas\n";
        cout << "0. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            crearArchivo();
            break;
        case 2:
            operarCuenta();
            break;
        case 3:
            desactivarCuenta();
            break;
        case 4:
            mostrarActivas();
            break;
        case 0:
            cout << "Fin del programa.\n";
            break;
        default:
            cout << "Opcion invalida.\n";
        }

    } while (opcion != 0);

    return 0;
}