#include "Smartphone.h"

Smartphone::Smartphone(string n,double p,bool tB,double re, string os, int mr, int alm) : Electronico(n,p,tB,re), sistemaOperativo(os), memoriaRAM(mr), almacenamiento(alm) {}

string Smartphone::getEspecificaciones() {
    return "Smartphone de sistema Operativo "+ sistemaOperativo + "\nCon memoria RAM: " + to_string(memoriaRAM) + "\nCon almacenamiento: " + to_string(almacenamiento);
}
