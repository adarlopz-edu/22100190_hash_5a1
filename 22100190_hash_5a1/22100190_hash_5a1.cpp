#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Persona {
    int registro;
    string nombre;
    string apellido;
    int edad;
};

struct Lista {
    Persona persona;
    Lista* siguiente;
};

class MetodoHash {
private:
    string preguntaOpcion;
    Lista* tablaHash[113]; 

public:
    MetodoHash();
    void ingresarDatos(Persona& persona);
    void Hash(Persona persona);
    // void buscarElemento(int registro);
};

MetodoHash::MetodoHash() {
    for (int i = 0; i < 113; ++i) {
        tablaHash[i] = 0; //todas las posiciones se van a cero
    }
}

void MetodoHash::ingresarDatos(Persona& persona) {
    cout << "METODO DE ORDENACION POR HASH" << endl;
    cout << "a) Introducir datos" << endl << "b) Buscar" << endl << "c) Salir" << endl;
    cout << "Cual es tu opcion? ";
    cin >> preguntaOpcion;

    for (char& c : preguntaOpcion) {
        c = tolower(c);
    }

    if (preguntaOpcion == "a") {
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
    if (preguntaOpcion == "b") {
         cout << endl << "Ingresa un registro a buscar: ";
         cin >> persona.registro;
         //buscarElemento(persona.registro);
    }
    if (preguntaOpcion == "c") {
        exit(1);
    }
}

void MetodoHash::Hash(Persona persona) {
    int indice = persona.registro % 113;

    // Crea un nuevo nodo para el nuevo elemento
    Lista* nuevoNodo = new Lista;
    nuevoNodo->persona = persona;
    nuevoNodo->siguiente = nullptr;

    // Verifica si la posición en la tabla está vacía
    if (tablaHash[indice] == 0) {
        tablaHash[indice] = nuevoNodo;
    }
    else {
        // Si la posición ya está ocupada, añade el nuevo nodo al final de la lista enlazada
        Lista* temp = tablaHash[indice];
        while (temp->siguiente != nullptr) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
    }
}


int main() {
    MetodoHash ordenamiento;
    Persona persona;

    ordenamiento.ingresarDatos(persona);

    cout << endl;
    return 0;
}
