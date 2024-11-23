#ifndef TELEVISOR
#define TELEVISOR
#include "Electronico.h"

class Televisor: public Electronico
{
private:
    int pulgadas;
    string tipoPantalla;
public:
    Televisor(string n,double p,double tB,bool re, int pulg, string tP);
    string getEspecificaciones() override;
};

#endif