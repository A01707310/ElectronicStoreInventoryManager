#ifndef ELECTRONICO_H
#define ELECTRONICO_H

#include <string>
using namespace std;

class Electronico {
private:
    string nombre;
    double precio;
public:
    Electronico(string n = "Nuevo Producto", double p = 0.0);
    string getNombre();
    double getPrecio();
};

#endif // ELECTRONICO_H
