#ifndef SMARTPHONE
#define SMARTPHONE
#include "Electronico.h"

class Smartphone: public Electronico
{
private:
    string sistemaOperativo;
    int memoriaRAM;
    int almacenamiento;
public:
    Smartphone(string n,double p,bool tB,double re, string os, int mr, int alm);
    string getEspecificaciones() override;
};

#endif