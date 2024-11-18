#ifndef TIENDA_H
#define TIENDA_H

#include "Electronico.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Tienda {
private:
    string nombre;
    vector<Electronico> inventario;
public:
    Tienda(string n);
    void agregarProducto(Electronico e);
    void mostrarInventario();
    string getNombre();
    vector<Electronico> getInventario();
};

#endif // TIENDA_H
