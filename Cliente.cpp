#include "Cliente.h"
using namespace std;
Cliente::Cliente(string n, string e) : nombre(n), email(e) {};
string Cliente::getNombre(){
    return nombre;
}
string Cliente::getEmail(){
    return email;
}
