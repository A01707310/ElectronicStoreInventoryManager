#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include "Cliente.h"
#include "Cliente.cpp"
#include "Electronico.h"
#include "Electronico.cpp"
#include "Computadora.h"
#include "Computadora.cpp"
#include "Smartphone.h"
#include "Smartphone.cpp"
#include "Televisor.h"
#include "Televisor.cpp"
#include "Factura.h"
#include "Factura.cpp"
#include "Pedido.h"
#include "Pedido.cpp"
#include "Tienda.h"
#include "Tienda.cpp"

using namespace std;

// Creando una plantilla para poder operar con objetos de cualquier tipo (no se limita a una sola clase)
template <typename T>
void MostrarListado(vector<T> VectorObjetos, string stt = "Objetos") {
    int ctdObjs = 0;
    cout << "Listado de " + stt + ":\n";
    for (T obj : VectorObjetos) {
        cout << ctdObjs << ": " << obj.getNombre()<< "\n";
        ctdObjs += 1;
    }
}

void MostrarTareas() {
    cout << "\nIngrese el número de operación:\n"
         << "1. Añadir tienda de Electrónicos al sistema\n"
         << "2. Agregar electrónicos a una tienda\n"
         << "3. Mostrar inventario de una tienda\n"
         << "4. Añadir nuevo cliente al sistema\n"
         << "5. Crear un pedido\n"
         << "6. Guardar toda la información en un archivo de texto\n"
         << "7. Salir" << endl;
}

void guardarInformacion(vector<Tienda> Tiendas, vector<Cliente> Clientes, map<string, Pedido> Pedidos) {
    ofstream archivo("Registros.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo para guardar la información." << endl;
        return;
    }

    archivo << "\nTiendas, sus productos y especificaciones de estos:\n";
    for (Tienda tienda : Tiendas) {
        archivo << tienda.getNombre() << endl;
        for (Electronico prod : tienda.getInventario()) {
        archivo << "Nombre del producto: "<< prod.getNombre() << endl;
        archivo << "Precio del producto: " << prod.getPrecio() << endl;
        archivo << "Espeficicaciones del producto: " << prod.getEspecificaciones() << endl;
        }
    }

    archivo << "\nClientes:\n";
    for (Cliente cliente : Clientes) {
        archivo << cliente.getNombre() << " - " << cliente.getEmail() << endl;
    }

    archivo << "\nPedidos:\n";
    for (auto& par : Pedidos) {
        archivo << "ID: " << par.first 
                << ", Cliente: " << par.second.nuevoCliente.getNombre() 
                << ", Total: $" << par.second.factura.getTotal() << endl;
        archivo << "Productos:\n";
        for (Electronico producto : par.second.productos) {
            archivo << "- " << producto.getNombre() << ": $" << producto.getPrecio() << "Especificaciones:\n" << producto.getEspecificaciones() << endl;
        }
    }

    archivo.close();
    cout << "Información guardada en 'Registros.txt'." << endl;
}

int main() {
    int seleccion, n_Tiendas = 0;
    vector<Tienda> Tiendas;
    vector<Cliente> Clientes; 
    vector<string> TiposElectronicos = {"Computadora", "Smartphone", "Televisor"};
    // mapa clave:'ID', valor: 'Objeto Pedido'
    map<string, Pedido> Pedidos;

    cout << "Bienvenido al Administrador de Tiendas Electrónicas";
    
    MostrarTareas();
    cin >> seleccion;

    do {
        if (seleccion == 1) {
            string nom_Tienda;
            cout << "Ingresa el nombre de la tienda" << endl;
            cin >> nom_Tienda;
            Tiendas.push_back(Tienda((nom_Tienda != "") ? nom_Tienda : "Tienda " + to_string(n_Tiendas)));
            n_Tiendas += 1;
            cout << "Éxito en la operación"<< endl;
            MostrarTareas();
            cin >> seleccion;

        } else if (seleccion == 2) {
            int selTienda;
            int selTipo;
            double precio;
            string nombre;
            bool tieneBat;
            double reqEl;

            // Mostrando listado y esperando selección de tienda
            MostrarListado(Tiendas, "Tiendas");
            cout << "Ingresa el número de tienda a la que quieres añadir el producto:";
            cin >> selTienda; cout<< endl;

            // Creando el producto a agregar
            cout << "\nNuevo electrónico para el inventario de la tienda " + Tiendas[selTienda].getNombre() << endl;
            
            cout << "Escoge un número de producto: 1. Computadora, 2. Smartphone, 3. Televisor";

            cout << "Escoge el tipo de electrónico a añadir al inventario";
            cin >> selTipo; cout<< endl;

            cout << "Ingresa el NOMBRE del producto: ";
            cin >> nombre;
            cout << "Ingresa el PRECIO del producto: ";
            cin >> precio;
            cout << "¿Tiene baterías?: ";
            cin >> tieneBat;
            cout << "Requerimiento Electrónico: ";
            cin >> reqEl;
            
            if (selTipo == 1) {
                int RAM; 
                string procesador;
                int almacenamiento;
                cout << "Ingresa la ctdad. de memoria RAM de la computadora: ";
                cin >> RAM;
                cout << "Ingresa el nombre del procesador de la computadora: ";
                cin >> procesador;
                cout << "Ingresa el almacenamiento de la computadora: ";
                cin >> almacenamiento;
                Computadora prod(nombre, precio, tieneBat, reqEl, RAM, procesador, almacenamiento);
                Tiendas[selTienda].agregarProducto(prod);
            }

            if (selTipo == 2) {
                string os; 
                int RAM;
                int almacenamiento;
                cout << "Ingresa el sistema operativo del smartphone: ";
                cin >> os;
                cout << "Ingresa la ctdad. de memoria RAM del smartphone: ";
                cin >> RAM;
                cout << "Ingresa el almacenamiento del smartphone: ";
                cin >> almacenamiento;
                Smartphone prod(nombre, precio, tieneBat, reqEl, os, RAM, almacenamiento);
                Tiendas[selTienda].agregarProducto(prod);
            }

            if (selTipo == 3) {
                int pulgs;
                string tPantalla;
                cout << "Ingresa el tamaño en pulgadas del televisor: ";
                cin >> pulgs;
                cout << "Ingresa el tipo de pantalla del televisor: ";
                cin >> tPantalla;
                Televisor prod(nombre, precio, tieneBat, reqEl, pulgs, tPantalla);
                Tiendas[selTienda].agregarProducto(prod);
            };

            // Añadiendo el producto al inventario de la tienda seleccionada
            cout << "Éxito en la operación" << endl;
            MostrarTareas();
            cin >> seleccion;

        } else if (seleccion == 3) {
            int selTienda;

            // Mostrando listado y esperando la selección de tienda
            MostrarListado(Tiendas, "Tiendas");
            cout<<"Ingresa el núm. cuya tienda correspondiente almacenará el producto: ";
            cin>>selTienda;
            cout<< endl;

            // Mostrando inventario para la tienda seleccionada
            cout << "Inventario de " << Tiendas[selTienda].getNombre() << ":\n";
            for (Electronico prod:Tiendas[selTienda].getInventario()) {
                cout << "- " << prod.getNombre() << ": $" << prod.getPrecio() << "\n";
            };
            
            cout<<"Éxito en la operación"<< endl;
            MostrarTareas();
            cin>>seleccion;

        } else if (seleccion == 4) {
            string nombre, email;
            cout<<"Ingresa el NOMBRE del nuevo Cliente"<< endl;
            cin>>nombre;
            cout<<"Ingresa el EMAIL del nuevo cliente"<< endl;
            cin>>email;

            // Los clientes son globales entre las tiendas
            Clientes.push_back(Cliente(nombre, email));
            cout<<"Éxito en la operación"<< endl;
            MostrarTareas();
            cin>>seleccion;

        } else if (seleccion == 5) {
            int selCliente, selTienda, selProd, tempID = 1; 
            
            Electronico prodtc; 
            Factura facturaActual; 

            // Seleccionar un cliente al cual asignar un pedido
            MostrarListado(Clientes, "Clientes");
            cout << "Num. de cliente acreedor del pedido: "; 
            cin >> selCliente; cout<< endl;

            // Validar selección de cliente
            if (selCliente < 0 || selCliente >= Clientes.size()) { 
                cout << "Selección de cliente inválida."<< endl; 
                MostrarTareas(); 
                cin >> seleccion; 
                continue; 
             }

             // Escoger una tienda para mostrar su inventario
             MostrarListado(Tiendas, "Tiendas"); 
             cout<< "Num. de tienda que aloja el producto por añadir al pedido: "; 
             cin >> selTienda; cout<< endl;

             // Validar selección de tienda
             if (selTienda < 0 || selTienda >= Tiendas.size()) { 
                 cout<< "Selección de tienda inválida."<< endl; 
                 MostrarTareas(); 
                 cin >> seleccion; 
                 continue; 
             }

             // Seleccionar producto a asignar
             MostrarListado(Tiendas[selTienda].getInventario(), ("productos en la tienda '" + Tiendas[selTienda].getNombre() + "'")); 
             cout<< "Num. de producto por añadir al pedido: "; 
             cin >> selProd; cout<< endl;

             // Validar selección de producto
             if (selProd < 0 || selProd >= Tiendas[selTienda].getInventario().size()) { 
                 cout<< "Selección de producto inválida."<< endl; 
                 MostrarTareas(); 
                 cin >> seleccion; 
                 continue; 
             }

             prodtc = Tiendas[selTienda].getInventario()[selProd]; 

             // Crear el Pedido y guardarlo en el mapa de Pedidos, asignándole una ID única.
             Pedido orden(Clientes[selCliente], facturaActual); 
             orden.agregarProducto(prodtc); 

             // Buscar un ID único
             while (Pedidos.find(to_string(tempID)) != Pedidos.end()) { tempID++; } 

             Pedidos[to_string(tempID)] = orden; 
             cout<< "Éxito en la operación"<< endl; 
             MostrarTareas(); 
             cin >> seleccion;

        } else if (seleccion == 6) { 
              guardarInformacion(Tiendas, Clientes, Pedidos); 
              cout<< "Éxito en la operación"<< endl; 
              MostrarTareas(); 
              cin >> seleccion; 
        }
        
    } while (seleccion != 7);

    return 0; 
}