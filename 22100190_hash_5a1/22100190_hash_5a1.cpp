#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
using namespace std;

struct Persona {
    int registro;
    string nombre;
    string apellido;
    int edad;
};

struct NodoLista {
    Persona persona;
    int siguiente;
};

class MetodoHash {
private:
    NodoLista lista[100];
    int tablaHash[113];
    int siguienteLibre;

public:
    MetodoHash();
    void ingresarDatos(Persona& persona);
    void Hash(Persona persona);
    void buscarElemento(int registro);
};

MetodoHash::MetodoHash() {
    for (int i = 0; i < 113; ++i) {
        tablaHash[i] = -1;
    }
    siguienteLibre = 0;
}

void MetodoHash::ingresarDatos(Persona& persona) {
    cout << endl << "BUSQUEDA SECUENCIAL" << endl;
    cout << "a) Introducir datos" << endl << "b) Buscar" << endl << "c) Salir" << endl;
    cout << "Cual es tu opcion? ";
    char preguntaOpcion;
    cin >> preguntaOpcion;

    if (preguntaOpcion == 'a') {
        cout << endl << "Ingresa tu registro: ";
        cin >> persona.registro;

        cout << "Nombre: ";
        cin >> persona.nombre;
        persona.nombre = persona.nombre.substr(0, 50);

        cout << "Apellido: ";
        cin >> persona.apellido;
        persona.apellido = persona.apellido.substr(0, 50);

        cout << "Edad: ";
        cin >> persona.edad;
        Hash(persona);
    }
    else if (preguntaOpcion == 'b') {
        cout << endl << "Ingresa un registro a buscar: ";
        int registro;
        cin >> registro;
        buscarElemento(registro);
    }
    else if (preguntaOpcion == 'c') {
        exit(1);
    }
}

void MetodoHash::buscarElemento(int registro) {
    bool encontrado = false;

    for (int i = 0; i < siguienteLibre; ++i) {
        if (lista[i].persona.registro == registro) {
            cout << "Registro: " << lista[i].persona.registro << endl;
            cout << "Nombre: " << lista[i].persona.nombre << endl;
            cout << "Apellido: " << lista[i].persona.apellido << endl;
            cout << "Edad: " << lista[i].persona.edad << endl << endl;
            encontrado = true;
        }
    }

    if (!encontrado)
        cout << "Registro no encontrado" << endl;
}

void MetodoHash::Hash(Persona persona) {
    int indice = persona.registro % 113;

    // nuevo nodo para el elemento
    NodoLista* nuevoNodo = new NodoLista;
    nuevoNodo->persona = persona;
    nuevoNodo->siguiente = -1; // por defecto no hay ningun elemento

    // Si la posición esta vacía, simplemente asigna el nuevo nodo
    if (tablaHash[indice] == -1) {
        tablaHash[indice] = siguienteLibre;
        lista[siguienteLibre] = *nuevoNodo; // guarda en el nuevo nodo
        siguienteLibre++;
    }
    else {
        // en caso de colision
        int posicion = tablaHash[indice];
        while (lista[posicion].siguiente != -1) {
            posicion = lista[posicion].siguiente;
        }
        // añade en la siguiente posicion de la lista que este libre
        lista[posicion].siguiente = siguienteLibre;
        lista[siguienteLibre] = *nuevoNodo; // guarda
        siguienteLibre++;
    }
}

int main() {
    MetodoHash ordenamiento;
    Persona persona;

    while (true) {
        ordenamiento.ingresarDatos(persona);
    }

    cout << endl;
    return 0;
}
