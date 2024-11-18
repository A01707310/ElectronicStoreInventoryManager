#include "Factura.h"

Factura::Factura(double t) : total(t) {}
Factura::Factura() : total(0.0) {}
double Factura::getTotal(){
    return total;
}
void Factura::setTotal(double nT) {
    total=nT;
}