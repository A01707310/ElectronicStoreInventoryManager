#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
using namespace std;

//Creando una plantilla para poder operar con objetos de cualquier tipo (no se limita a una sola clase)
template <typename T>
void MostrarListado(vector<T> VectorObjetos, string stt="Objetos"){
    int ctdObjs = 0; cout<<"Listado de " + stt + ":\n";
    for (const T obj : VectorObjetos){
        cout << ctdObjs << ": " << obj.nombre << "\n";
        ctdObjs+=1; }};

void MostrarTareas(){
    cout<<"\nIngrese el número de operación:\n1. Añadir tienda de Electrónicos al sistema\n2. Agregar electrónicos a una tienda\n3. Mostrar inventario de una tienda\n4. Añadir nuevo cliente al sistema\n5. Crear un pedido\n6. Guardar toda la información en un archivo de texto\n7. Salir"<<endl;
};

class Cliente {
public:
    string nombre, email;
    Cliente(string n, string e) : nombre(n), email(e) {}
};

class Electronico {
public:
    string nombre;
    double precio;

    Electronico(string n = "Nuevo Producto", double p = 0.0) : nombre(n), precio(p) {}
};

class Periferico: public Electronico{
    public:
    bool esInalambrico;
    Periferico(string n, double p, bool inalambrico) : Electronico(n, p), esInalambrico(inalambrico) {}
};

class Factura {
public:
    double total=0.0;
    Factura(double t) : total(t) {}
    Factura() : total(0.0) {}
};

class Pedido {
public:
    Cliente nuevoCliente;
    vector<Electronico> productos;
    Factura factura;

    Pedido(Cliente c, Factura f) : nuevoCliente(c), factura(f) {}
    Pedido() : nuevoCliente(Cliente("", "")), factura(Factura(0.0)) {}

    void agregarProducto(Electronico e) {
        productos.push_back(e);
        factura.total += e.precio;
    }
};

class Tienda {
public:
    std::string nombre;
    std::vector<Electronico> inventario;
    Tienda(std::string n) : nombre(n) {}
    void agregarProducto(Electronico e) {
        inventario.push_back(e);
    }
    void mostrarInventario() {
        std::cout << "Inventario de " << nombre << ":\n";
        for (const auto& producto : inventario) {
            std::cout << "- " << producto.nombre << ": $" << producto.precio << "\n";
        }
    }
    std::vector<Electronico> getInventario() {
        return inventario;
    }
};

void guardarInformacion(vector<Tienda> Tiendas, vector<Cliente> Clientes, map<string, Pedido> Pedidos) {
    ofstream archivo("Registros.txt");
    if (!archivo) {
        cerr << "No se pudo abrir el archivo para guardar la información." << endl;
        return;
    }

    archivo << "Tiendas:\n";
    for (const auto& tienda : Tiendas) {
        archivo << tienda.nombre << "\n";
    }

    archivo << "\nClientes:\n";
    for (const auto& cliente : Clientes) {
        archivo << cliente.nombre << " - " << cliente.email << "\n";
    }

    archivo << "\nPedidos:\n";
    for (const auto& par : Pedidos) {
        archivo << "ID: " << par.first << ", Cliente: " << par.second.nuevoCliente.nombre << ", Total: $" << par.second.factura.total << "\n";
        archivo << "Productos:\n";
        for (const auto& producto : par.second.productos) {
            archivo << "- " << producto.nombre << ": $" << producto.precio << "\n";
        }
    }

    archivo.close();
    cout << "Información guardada en 'informacion.txt'." << endl;
}

int main() {
    int seleccion, n_Tiendas = 0;
    vector<Tienda> Tiendas;
    vector<Cliente> Clientes;

    //mapa clave:'ID', valor: 'Objeto Pedido'
    map<string,Pedido> Pedidos;
    
    cout<<"Bienvenido al Administrador de Tiendas Electrónicas";
    MostrarTareas(); cin>>seleccion;

    do
    {
        if (seleccion==1)
        {
            string nom_Tienda;
            cout<<"Ingresa el nombre de la tienda"<<endl; cin>>nom_Tienda;
            //ESTO 'Tienda tienda((nom_Tienda!="") ? nom_Tienda : "Tienda "+to_string(n_Tiendas)); Tiendas.push_back(tienda);' EQUIVALE A ESTO 'Tiendas.push_back(Tienda((nom_Tienda!="") ? nom_Tienda : "Tienda "+to_string(n_Tiendas)));' EN ESTE CASO
            Tiendas.push_back(Tienda((nom_Tienda!="") ? nom_Tienda : "Tienda "+to_string(n_Tiendas)));
            n_Tiendas+=1;
            cout<<"Éxito en la operación\n"; MostrarTareas(); cin>>seleccion;
        }

        else if (seleccion==2)
        {
            int selTienda;
            double precio;
            string nombre;
            bool esInalambrico;

            // Mostrando listado y esperando selección de tienda
            MostrarListado(Tiendas, "Tiendas");
            cout << "Ingresa el número de tienda a la que quieres añadir el producto:"; cin >> selTienda;

            // Creando el producto a agregar
            cout << "\nNuevo producto para el inventario de la tienda " + Tiendas[selTienda].nombre + "\n";
            cout << "Ingresa el NOMBRE del producto: "; cin >> nombre;
            cout << "Ingresa el PRECIO del producto: "; cin >> precio;
            cout << "¿Es inalámbrico? (1 para sí, 0 para no): "; cin >> esInalambrico;

            // Cambiando a la creación de un objeto Periferico
            Periferico prod(nombre, precio, esInalambrico);
            // Añadiendo el producto al inventario de la tienda seleccionada
            Tiendas[selTienda].agregarProducto(prod);
            cout << "Éxito en la operación\n"; MostrarTareas(); cin >> seleccion;
        }

        else if (seleccion==3)
        {
            int selTienda;

            //Mostrando listado y esperando la selección de tienda
            MostrarListado(Tiendas, "Tiendas");
            cout<<"Ingresa el núm. cuya tienda correspondiente almacenará el producto: "; cin>>selTienda;
            //Mostrando inventario para la tienda seleccionada
            Tiendas[selTienda].mostrarInventario();

            cout<<"Éxito en la operación\n"; MostrarTareas(); cin>>seleccion;
        }

        else if (seleccion==4)
        {
            string nombre, email;

            cout<<"Ingresa el NOMBRE del nuevo Cliente\n"; cin>>nombre; cout<<"Ingresa el EMAIL del nuevo cliente\n"; cin>>email;
            //Notar: los clientes son globales entre las tiendas. Serán los mismos, indistintamente, respecto a las tiendas (No están sujetos a ellas, no hay clientes exclusivos de una tienda).
            /*ESTO 'Cliente nuevoCliente(nombre, email);' Y ESTO 'Clientes.push_back(nuevoCliente);' EQUIVALEN, PARA ESTE CASO*/
            Clientes.push_back(Cliente(nombre, email));

            cout<<"Éxito en la operación\n"; MostrarTareas(); cin>>seleccion;
        }

        else if (seleccion == 5) {
            int selCliente, selTienda, selProd, tempID = 1; // Comenzar en 1
            Electronico prodtc; 
            Factura facturaActual;

            // Seleccionar un cliente al cual asignar un pedido (Mostrar lista de clientes)
            MostrarListado(Clientes, "Clientes");
            cout << "Num. de cliente acreedor del pedido: "; 
            cin >> selCliente;

            // Validar selección de cliente
            if (selCliente < 0 || selCliente >= Clientes.size()) {
                cout << "Selección de cliente inválida." << endl;
                MostrarTareas(); 
                cin >> seleccion;
            }

            // Escoger una tienda para mostrar su inventario
            MostrarListado(Tiendas, "Tiendas");
            cout << "Num. de tienda que aloja el producto por añadir al pedido: "; 
            cin >> selTienda;

            // Validar selección de tienda
            if (selTienda < 0 || selTienda >= Tiendas.size()) {
                cout << "Selección de tienda inválida." << endl;
                MostrarTareas(); 
                cin >> seleccion;
            }

            // Seleccionar producto a asignar 
            MostrarListado(Tiendas[selTienda].getInventario(), ("productos en la tienda '" + Tiendas[selTienda].nombre + "'"));
            cout << "Num. de producto por añadir al pedido: "; 
            cin >> selProd;

            // Validar selección de producto
            if (selProd < 0 || selProd >= Tiendas[selTienda].getInventario().size()) {
                cout << "Selección de producto inválida." << endl;
                MostrarTareas(); 
                cin >> seleccion;
            }

            prodtc = Tiendas[selTienda].getInventario()[selProd];            
            
            // Crear el Pedido y guardarlo en el mapa de Pedidos, asignándole una ID única.
            Pedido orden(Clientes[selCliente], facturaActual);
            orden.agregarProducto(prodtc);

            // Buscar un ID único
            while (Pedidos.find(to_string(tempID)) != Pedidos.end()) {
                tempID++;
            }
            Pedidos[to_string(tempID)] = orden;

            cout << "Éxito en la operación\n"; 
            MostrarTareas(); 
            cin >> seleccion;
        }


        else if (seleccion==6)
        {
            guardarInformacion(Tiendas, Clientes, Pedidos);
            cout<<"Éxito en la operación\n"; MostrarTareas(); cin>>seleccion;
        }
    } while (seleccion!=7);
    
    return 0;
    };
