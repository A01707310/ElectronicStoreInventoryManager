#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
using namespace std;

class Cliente {
private:
    string nombre;
    string email;
public:
    Cliente(string n, string e);
    string getNombre();
    string getEmail();
};

#endif // CLIENTE_H
