#ifndef ELECTRONICO_H
#define ELECTRONICO_H
#include <iostream>
#include <string>
using namespace std;

class Electronico {
private:
    string nombre;
    double precio;
    bool tieneBaterias;
    double requerimiento_electrico;
    
public:
    Electronico(string n = "Nuevo Producto", double p = 0.0,  bool tB=false, double re=10.0);
    string getNombre();
    double getPrecio();
    virtual string getEspecificaciones();
    ~ Electronico();
};

#endif // ELECTRONICO_H
