#include "Pedido.h"

Pedido::Pedido(Cliente c, Factura f) : nuevoCliente(c), factura(f) {}
Pedido::Pedido() : nuevoCliente(Cliente("", "")), factura(Factura(0.0)) {}

void Pedido::agregarProducto(Electronico e) {
    productos.push_back(e);
    factura.setTotal(factura.getTotal()+e.getPrecio());
}
