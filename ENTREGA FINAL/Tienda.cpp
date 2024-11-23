#include "Tienda.h"
using namespace std;

Tienda::Tienda(std::string n) : nombre(n) {}

void Tienda::agregarProducto(Electronico e) {
    inventario.push_back(e);
}

string Tienda::getNombre(){
    return nombre;
}

vector<Electronico> Tienda::getInventario() {
    return inventario;
}
