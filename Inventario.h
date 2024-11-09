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

    std::string getColor() const;
    float getConsumoEnergia() const;
    float getPrecio() const;
    float getDescuento() const;
    int getUdsDisponibles() const;
    std::string getDescripcion() const;
};

class Computadora : public Producto {
private:
    int memoria_ram;
    std::string procesador;

public:
    Computadora(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, int ram, std::string proc);

    int getMemoriaRam() const;
    std::string getProcesador() const;
};

class Tablet : public Producto {
private: 
    bool soporte_sim; 

public:
    Tablet(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, bool sim);

    bool tieneSoporteSim() const;
};

class Telefono : public Producto {
private:
    int num_camaras;
    bool soporte_5g;

public:
    Telefono(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, int camaras, bool soporte5g);

    int getNumCamaras() const;
    bool tieneSoporte5G() const;
};

class Laptop : public Producto {
private:
    int tamano_pantalla;
    bool teclado_iluminado; 

public:
    Laptop(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, int tamano, bool iluminado);

    int getTamanoPantalla() const;
    bool tieneTecladoIluminado() const;
};

class Pantalla : public Producto {
private:
    int resolucion;
    int frecuencia_refresco; 

public:
    Pantalla(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, int resolucion, int frecuencia);

    int getResolucion() const;
    int getFrecuenciaRefresco() const;
};

class Altavoz : public Producto {
private:
    int potencia;
    bool soporte_bluetooth; 

public:
    Altavoz(std::string color, float consumo, float precio, float descuento, int uds, std::string desc, int potencia, bool bluetooth);

    int getPotencia() const;
    bool tieneSoporteBluetooth() const;
};

#endif
