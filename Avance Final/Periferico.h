#ifndef PERIFERICO_H
#define PERIFERICO_H

#include "Electronico.h"
using namespace std;

class Periferico : public Electronico {
public:
    bool esInalambrico;

    Periferico(string n="Periférico", double p=0.0, bool inalambrico=false);
};

#endif // PERIFERICO_H
