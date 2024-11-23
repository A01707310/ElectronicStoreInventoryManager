#ifndef PEDIDO_H
#define PEDIDO_H

#include "Cliente.h"
#include "Electronico.h"
#include "Factura.h"
#include <vector>
using namespace std;

class Pedido {
public:
    Cliente nuevoCliente;
    vector<Electronico> productos;
    Factura factura;

    Pedido(Cliente c, Factura f);
    Pedido();
    void agregarProducto(Electronico e);
};

#endif // PEDIDO_H
