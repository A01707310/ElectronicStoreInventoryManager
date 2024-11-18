#ifndef FACTURA_H
#define FACTURA_H

class Factura {
private:
    double total=0.0;
public:
    Factura(double t);
    Factura();
    double getTotal();
    void setTotal(double nT);
};

#endif // FACTURA_H
