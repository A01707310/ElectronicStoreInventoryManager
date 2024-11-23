#include "Electronico.h"
using namespace std;

Electronico::Electronico(string n, double p, bool tB, double re) : nombre(n), precio(p), tieneBaterias(tB), requerimiento_electrico(re)  {}
string Electronico::getNombre(){
    return nombre;
}
double Electronico::getPrecio(){
    return precio;
}
string Electronico::getEspecificaciones() {
    return "No hay especificaciones";
}
Electronico::~Electronico(){};