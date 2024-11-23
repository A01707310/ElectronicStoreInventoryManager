#include "Televisor.h"

Televisor::Televisor(string n,double p,double tB,bool re, int pulgs, string tP) : Electronico(n,p,tB,re), pulgadas(pulgs), tipoPantalla(tP) {};
string Televisor::getEspecificaciones() {
    return "Pantalla tipo " + tipoPantalla + " de " + to_string(pulgadas) + " pulgadas";
}