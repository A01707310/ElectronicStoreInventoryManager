#include "Periferico.h"

Periferico::Periferico(std::string n, double p, bool inalambrico) 
    : Electronico(n, p), esInalambrico(inalambrico) {}
