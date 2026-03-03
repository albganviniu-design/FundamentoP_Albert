#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

struct Venta
{
    int idVenta;
    int idVendedor;
    int idProducto;
    int cantidad;
    double precioUnitario;
};

int main()
{

    ifstream archivo("entradas/ventas.dat", ios::binary); // archivo binario

    if (!archivo)
    {
        cout << "Error al abrir ventas.dat" << endl;
        return 1;
    }

    int numRegistros;
    archivo.read((char *)&numRegistros, sizeof(int));

    Venta *ventas = new Venta[numRegistros];

    // Para identificar totales
    int *vendedores = new int[numRegistros];
    double *totalVendedor = new double[numRegistros];

    int *productos = new int[numRegistros];
    int *totalProducto = new int[numRegistros];

    int numVendedores = 0;
    int numProductos = 0;

    double montoTotal = 0.0;

    for (int i = 0; i < numRegistros; i++)
    {
        archivo.read((char *)&ventas[i], sizeof(Venta));

        double subtotal = ventas[i].cantidad * ventas[i].precioUnitario;
        montoTotal += subtotal;

        // Para los vendedores
        bool encontrado = false;

        for (int j = 0; j < numVendedores; j++)
        {
            if (vendedores[j] == ventas[i].idVendedor)
            {
                totalVendedor[j] += subtotal;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            vendedores[numVendedores] = ventas[i].idVendedor;
            totalVendedor[numVendedores] = subtotal;
            numVendedores++;
        }

        // Para los productos
        encontrado = false;

        for (int j = 0; j < numProductos; j++)
        {
            if (productos[j] == ventas[i].idProducto)
            {
                totalProducto[j] += ventas[i].cantidad;
                encontrado = true;
                break;
            }
        }

        if (!encontrado)
        {
            productos[numProductos] = ventas[i].idProducto;
            totalProducto[numProductos] = ventas[i].cantidad;
            numProductos++;
        }
    }

    // Vendedor con mayor recaudación
    int mejorVendedor = -1;
    double mayorRecaudacion = 0;

    for (int i = 0; i < numVendedores; i++)
    {
        if (totalVendedor[i] > mayorRecaudacion)
        {
            mayorRecaudacion = totalVendedor[i];
            mejorVendedor = vendedores[i];
        }
    }

    // Producto más vendido
    int mejorProducto = -1;
    int mayorCantidad = 0;

    for (int i = 0; i < numProductos; i++)
    {
        if (totalProducto[i] > mayorCantidad)
        {
            mayorCantidad = totalProducto[i];
            mejorProducto = productos[i];
        }
    }

    ofstream reporte("output/reporte.txt"); // Reporte en output
    reporte << fixed << setprecision(2);

    reporte << "--- REPORTE GENERAL DE VENTAS ----\n\n";
    reporte << "Total de registros: " << numRegistros << "\n\n"; // NUMERO TOTAL DE REGISTROS

    reporte << "MONTO TOTAL VENDIDO:\n";
    reporte << "S/. " << montoTotal << "\n\n";

    reporte << "---------------------------------------\n";
    reporte << "VENDEDOR CON MAYOR RECAUDACIÓN:\n";
    reporte << "ID Vendedor: " << mejorVendedor << "\n";
    reporte << "Total vendido: S/. " << mayorRecaudacion << "\n\n";

    reporte << "---------------------------------------\n";
    reporte << "PRODUCTO MÁS VENDIDO:\n";
    reporte << "ID Producto: " << mejorProducto << "\n";
    reporte << "Total unidades: " << mayorCantidad << "\n\n";

    reporte << "---------------------------------------\n";
    reporte << "VENTAS SOSPECHOSAS (cantidad > 100):\n\n";

    for (int i = 0; i < numRegistros; i++)
    {
        if (ventas[i].cantidad)
        {
            reporte << left
                    << setw(10) << "ID Venta:"
                    << setw(4) << ventas[i].idVenta
                    << setw(12) << "| Vendedor:"
                    << setw(4) << ventas[i].idVendedor
                    << setw(12) << "| Producto:"
                    << setw(4) << ventas[i].idProducto
                    << setw(12) << "| Cantidad:"
                    << setw(4) << ventas[i].cantidad
                    << "\n";
        }
    }

    archivo.close();
    reporte.close();

    // Liberamos la memoria
    delete[] ventas;
    delete[] vendedores;
    delete[] totalVendedor;
    delete[] productos;
    delete[] totalProducto;

    cout << "Reporte generado correctamente." << endl;
    return 0;
}