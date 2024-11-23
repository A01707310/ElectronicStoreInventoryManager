#ifndef COMPUTADORA
#define COMPUTADORA
#include "Electronico.h"
#include <string>

class Computadora: public Electronico
{
private:
    int memoriaRAM;
    string procesador;
    int almacenamiento;
public:
    Computadora(string n = "Nuevo Producto", double p = 0.0,  bool tB=false, double re=10.0,  int mr=2,  string proc="4 núcleos",  int alm = 360);
    string getEspecificaciones() override;
};

#endif