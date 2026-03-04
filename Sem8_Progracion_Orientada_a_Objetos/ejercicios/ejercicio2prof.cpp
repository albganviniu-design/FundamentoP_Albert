#include <iostream>
#include <fstream>
using namespace std;

struct CuentaBancaria
{
    int numeroCuenta;
    char titular[40];
    double saldo;
    bool activa;
};

//---------------------------------------------------
// Crear archivo con acceso directo
//---------------------------------------------------
void crearArchivo(int N)
{
    fstream archivo("cuentas.dat", ios::binary | ios::out | ios::in);

    if (!archivo)
    {
        // Si no existe lo creamos
        archivo.open("cuentas.dat", ios::out | ios::binary);
        archivo.close();

        archivo.open("cuentas.dat", ios::binary | ios::out | ios::in);
    }

    CuentaBancaria cuenta;

    for (int i = 0; i < N; i++)
    {
        cout << "Numero de cuenta " << i + 1 << ": " << endl;
        cin >> cuenta.numeroCuenta;

        long posicion = sizeof(CuentaBancaria) * (cuenta.numeroCuenta - 1);

        // Movemos el puntero de lectura (seekg) a posicion
        archivo.seekg(posicion);

        // Creamos un objeto temporal para verificar si hay registros en esa posicion
        CuentaBancaria temp;
        archivo.read((char *)&temp, sizeof(CuentaBancaria));

        // Si pudo leer y la cuenta esta activa, significa que ya existe
        if (archivo.gcount() == sizeof(CuentaBancaria) && temp.activa)
        {
            cout << "Ya existe una cuenta con este numero\n";
            i--;
        }
        else
        {
            // Si fallo la lectura, debemos reestablecer los valores de archivo
            archivo.clear();

            // mover el puntero de escritura
            archivo.seekp(posicion);

            cout << "Titular: ";
            cin >> cuenta.titular;

            cout << "Saldo: ";
            cin >> cuenta.saldo;

            cuenta.activa = true;

            archivo.write((char *)&cuenta, sizeof(CuentaBancaria));
        }
        // No se pueden repetir numero de cuentas
    }

    archivo.close();
}

//---------------------------------------------------
// Buscar cuenta usando acceso directo
//---------------------------------------------------
bool buscarCuenta(int numero, CuentaBancaria &cuenta)
{
    fstream archivo("cuentas.dat", ios::binary | ios::in);

    if (!archivo)
        return false;

    long posicion = sizeof(CuentaBancaria) * (numero - 1);

    // Movemos puntero a la posicion correspondiente
    archivo.seekg(posicion);

    archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

    archivo.close();

    if (cuenta.numeroCuenta == numero && cuenta.activa)
        return true;

    return false;
}

//---------------------------------------------------
// Depositar o retirar dinero
//---------------------------------------------------
void operarCuenta(int numero, double monto)
{
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if (!archivo)
    {
        cout << "No existe el archivo\n";
        return;
    }

    long posicion = sizeof(CuentaBancaria) * (numero - 1);

    // Movemos el puntero de lectura
    archivo.seekg(posicion);

    CuentaBancaria cuenta;
    archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

    if (cuenta.numeroCuenta != numero || !cuenta.activa)
    {
        cout << "Cuenta inexistente o inactiva\n";
        archivo.close();
        return;
    }

    // No permitir saldo negativo
    if (cuenta.saldo + monto < 0)
    {
        cout << "Operacion invalida. Saldo insuficiente\n";
        archivo.close();
        return;
    }

    cuenta.saldo += monto;

    // Movemos puntero de escritura a la misma posicion
    archivo.seekp(posicion);

    // La modificacion se hace directamente en el archivo
    archivo.write((char *)&cuenta, sizeof(CuentaBancaria));

    archivo.close();

    cout << "Operacion realizada correctamente\n";
}

//---------------------------------------------------
// Desactivar cuenta (borrado logico)
//---------------------------------------------------
void desactivarCuenta(int numero)
{
    fstream archivo("cuentas.dat", ios::binary | ios::in | ios::out);

    if (!archivo)
        return;

    long posicion = sizeof(CuentaBancaria) * (numero - 1);

    archivo.seekg(posicion);

    CuentaBancaria cuenta;
    archivo.read((char *)&cuenta, sizeof(CuentaBancaria));

    if (cuenta.numeroCuenta != numero || !cuenta.activa)
    {
        cout << "Cuenta no encontrada\n";
        archivo.close();
        return;
    }

    // No se borra fisicamente, solo se desactiva
    cuenta.activa = false;

    archivo.seekp(posicion);
    archivo.write((char *)&cuenta, sizeof(CuentaBancaria));

    archivo.close();

    cout << "Cuenta desactivada correctamente\n";
}

//---------------------------------------------------
// Mostrar unicamente cuentas activas
//---------------------------------------------------
void mostrarActivas()
{
    ifstream archivo("cuentas.dat", ios::binary);

    if (!archivo)
    {
        cout << "No existe el archivo\n";
        return;
    }

    CuentaBancaria cuenta;

    while (archivo.read((char *)&cuenta, sizeof(CuentaBancaria)))
    {
        if (cuenta.activa)
        {
            cout << "Numero: " << cuenta.numeroCuenta << endl;
            cout << "Titular: " << cuenta.titular << endl;
            cout << "Saldo: " << cuenta.saldo << endl;
            cout << "-----------------------\n";
        }
    }

    archivo.close();
}

//---------------------------------------------------
int main()
{
    int opcion;
    int numero;
    double monto;

    do
    {
        cout << "\n1- Crear archivo";
        cout << "\n2- Depositar";
        cout << "\n3- Retirar";
        cout << "\n4- Desactivar cuenta";
        cout << "\n5- Mostrar activas";
        cout << "\n0- Salir";
        cout << "\nOpcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int N;
            cout << "Cantidad de cuentas: ";
            cin >> N;
            crearArchivo(N);
            break;
        }

        case 2:
            cout << "Numero de cuenta: ";
            cin >> numero;
            cout << "Monto: ";
            cin >> monto;
            operarCuenta(numero, monto);
            break;

        case 3:
            cout << "Numero de cuenta: ";
            cin >> numero;
            cout << "Monto: ";
            cin >> monto;
            operarCuenta(numero, -monto);
            break;

        case 4:
            cout << "Numero de cuenta: ";
            cin >> numero;
            desactivarCuenta(numero);
            break;

        case 5:
            mostrarActivas();
            break;
        }

    } while (opcion != 0);

    return 0;
}