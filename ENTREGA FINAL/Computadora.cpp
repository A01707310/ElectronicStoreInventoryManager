#include "Computadora.h"

Computadora::Computadora(string n, double p,  bool tB, double re,  int mr,  string proc,  int alm) : Electronico(n,p,tB,re), memoriaRAM(mr), procesador(proc), almacenamiento(alm) {}
string Computadora::getEspecificaciones() {
    return "Computadora con memoria RAM: " + to_string(memoriaRAM) + "\nCon procesador: " + procesador + "\nCon almacenamiento: " + to_string(almacenamiento);
}