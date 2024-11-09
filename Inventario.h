#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>

class Producto {
protected:
    std::string color;
    float consumo_energia;
    float precio;
    float descuento;
    int uds_disponibles;
    std::string descripcion;

public:
    Producto(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);

    void anadir_uds(int cantidad);
    void quitar_uds(int cantidad);
    void eliminar_producto();
};

// Clases derivadas de Producto para cada tipo de producto

class Computadora : public Producto {
public:
    Computadora(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

class Tablet : public Producto {
public:
    Tablet(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

class Telefono : public Producto {
public:
    Telefono(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

class Laptop : public Producto {
public:
    Laptop(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

class Pantalla : public Producto {
public:
    Pantalla(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

class Altavoz : public Producto {
public:
    Altavoz(std::string color, float consumo, float precio, float descuento, int uds, std::string desc);
};

#endif // INVENTARIO_H
