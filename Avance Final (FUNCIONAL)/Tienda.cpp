#include "Tienda.h"
using namespace std;

Tienda::Tienda(std::string n) : nombre(n) {}

void Tienda::agregarProducto(Electronico e) {
    inventario.push_back(e);
}

void Tienda::mostrarInventario() {
    std::cout << "Inventario de " << nombre << ":\n";
    for (Electronico producto : inventario) {
        std::cout << "- " << producto.getNombre() << ": $" << producto.getPrecio() << "\n";
    }
}

string Tienda::getNombre(){
    return nombre;
}

vector<Electronico> Tienda::getInventario() {
    return inventario;
}
