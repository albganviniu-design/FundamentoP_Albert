#include <iostream>
#include <fstream>
using namespace std;

class Figura
{
private:
    string nombre;
    double* colorRGB;

public:
    // Constructores
    // constructor de parametros
    Figura(string nom, double r, double g, double b) : nombre(nom)
    {
        colorRGB = new double[3];
        colorRGB[0] = r;
        colorRGB[1] = g;
        colorRGB[2] = b;
    }

    // constructor de copia profunda (deep copy) vs shallow copy (el sistema lo crea / por defecto)
    Figura(Figura & otro): nombre(otro.nombre)
    {
        colorRGB = new double[3];
        for (int i = 0; i < 3; i++)
        {
            colorRGB[i] = otro.colorRGB[i];
        }
    }

    // Redefinir el operador de asignacion

    // puntero oculto this

    Figura& operator = (Figura& otro)
    {
        if (this != &otro)
        {
            nombre = otro.nombre;

            delete[] colorRGB;

            colorRGB = new double[3];

            for (int i = 0; i < 3; i++)
            {
                colorRGB[i] = otro.colorRGB[i];
            }
        }
        return *this;
    }

    // Destructor
    virtual ~Figura()
    {
        delete[] colorRGB;
    }

    // Getters
    string getNombre() const { return nombre; }

    double getR() const { return colorRGB[0]; }
    double getG() const { return colorRGB[1]; }
    double getB() const { return colorRGB[2]; }

    // Metodos virtuales puros

    virtual double area() const = 0;
    virtual double perimetro() const = 0;
    virtual void imprimir() const = 0;
};

// ---------------- Circulo -------------------
class Circulo : public Figura
{
private:
    double radio;

public:
    Circulo(double r, double cr, double cg, double cb)
        : Figura("Circulo", cr, cg, cb), radio(r) {}

    double area() const override
    {
        return 3.1416 * radio * radio;
    }

    double perimetro() const override
    {
        return 2 * 3.1416 * radio;
    }

    void imprimir() const override
    {
        cout << "Figura: " << getNombre() << endl;
        cout << "Radio: " << radio << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
        cout << endl;
    }
};

// ---------------- Rectangulo -------------------
class Rectangulo : public Figura
{
private:
    double base;
    double altura;

public:
    Rectangulo(double b, double a, double r, double g, double bcolor)
        : Figura("Rectangulo", r, g, bcolor)
    {
        base = b;
        altura = a;
    }

    double area() const override
    {
        return base * altura;
    }

    double perimetro() const override
    {
        return 2 * (base + altura);
    }

    void imprimir() const override
    {
        cout << "Figura: " << getNombre() << endl;
        cout << "Base: " << base << endl;
        cout << "Altura: " << altura << endl;
        cout << "Area: " << area() << endl;
        cout << "Perimetro: " << perimetro() << endl;
        cout << endl;
    }
};

// ---------------- Gestor de figuras -------------------
class GestorFiguras
{
private:
    Figura **figuras;
    int cantidad;
    int capacidad;

    void redimensionar()
    {
        capacidad *= 2;

        Figura **nuevo = new Figura *[capacidad];

        for (int i = 0; i < cantidad; i++)
            nuevo[i] = figuras[i];

        delete[] figuras;

        figuras = nuevo;
    }

public:
    // Constructor
    GestorFiguras(int cap = 5)
    {
        capacidad = cap;
        cantidad = 0;
        figuras = new Figura *[capacidad];
    }

    // Destructor
    ~GestorFiguras()
    {
        for (int i = 0; i < cantidad; i++)
            delete figuras[i];

        delete[] figuras;
    }

    // Agregar figura
    void agregarFigura(Figura *f)
    {
        if (cantidad == capacidad)
            redimensionar();

        figuras[cantidad++] = f;
    }

    // Mostrar figuras
    void mostrarFiguras() const
    {
        for (int i = 0; i < cantidad; i++)
            figuras[i]->imprimir(); // POLIMORFISMO
    }

    // Area total
    double areaTotal() const
    {
        double total = 0;

        for (int i = 0; i < cantidad; i++)
            total += figuras[i]->area();

        return total;
    }

    // Guardar en archivo
    void guardarArchivo(string nombreArchivo)
    {
        ofstream archivo(nombreArchivo);

        for (int i = 0; i < cantidad; i++)
        {
            archivo << figuras[i]->getNombre() << " ";
            archivo << figuras[i]->area() << " ";
            archivo << figuras[i]->perimetro() << endl;
        }

        archivo.close();
    }
};

int main()
{
    GestorFiguras gestor;

    gestor.agregarFigura(new Circulo(5, 255, 0, 0));
    gestor.agregarFigura(new Rectangulo(4, 6, 0, 255, 0));
    gestor.agregarFigura(new Circulo(3, 0, 0, 255));

    cout << "---- FIGURAS ----" << endl;

    gestor.mostrarFiguras();

    cout << "Area total: " << gestor.areaTotal() << endl;

    gestor.guardarArchivo("figuras.txt");

    return 0;
}