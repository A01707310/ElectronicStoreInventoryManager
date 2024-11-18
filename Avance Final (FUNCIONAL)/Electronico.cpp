#include "Electronico.h"

Electronico::Electronico(std::string n, double p) : nombre(n), precio(p) {}
string Electronico::getNombre(){
    return nombre;
}
double Electronico::getPrecio(){
    return precio;
}