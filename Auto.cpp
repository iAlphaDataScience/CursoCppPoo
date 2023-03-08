#include <iostream>
#include <string>

using namespace std;

class Auto {
private:
    double peso;
    double longitud;
    double altura;
    bool climatizador;
    string tapiceria;
    
public:
    // Constructor 1
    Auto() {
        peso = 1000.0;
        longitud = 3.5;
        altura = 1.5;
        climatizador = false;
        tapiceria = "standard";
    }
    
    // Constructor 2
    Auto(double peso, double longitud) {
        this->peso = peso;
        this->longitud = longitud;
        altura = 1.5;
        climatizador = false;
        tapiceria = "standard";
    }
    
    // Constructor 3
    Auto(double peso, double longitud, double altura, bool climatizador, string tapiceria) {
        this->peso = peso;
        this->longitud = longitud;
        this->altura = altura;
        this->climatizador = climatizador;
        this->tapiceria = tapiceria;
    }
    
    string getExtras() {
        string extras = "Tapicería: " + tapiceria + ", Climatizador: ";
        extras += climatizador ? "Sí" : "No";
        return extras;
    }
    
    void setExtras(bool climatizador, string tapiceria) {
        this->climatizador = climatizador;
        this->tapiceria = tapiceria;
    }
    
    string getInfoAuto() {
        string info = "Peso: " + to_string(peso) + " kg, Longitud: ";
        info += to_string(longitud) + " m, Altura: " + to_string(altura) + " m";
        return info;
    }
};

int main() {
    Auto auto1; // Creamos el objeto auto1 de tipo Auto y llamamos al constructor por defecto
    Auto auto2(3.5, 5); // Se crea auto2 con el segundo constructor
    Auto auto3(6, 3.5, 2.5, false, "ninguna"); // Se crea auto3 con el tercer constructor
    
    cout << auto2.getExtras() << endl;
    
    auto2.setExtras(true, "cuero"); // Cambio tapicería y pongo climatizador
    cout << auto2.getExtras() << endl;
    
    cout << endl;
    cout << auto1.getInfoAuto() << endl;
    cout << auto1.getExtras() << endl;
    cout << auto2.getInfoAuto() << endl;
    
    cout << auto3.getExtras() << endl;
    cout << auto3.getInfoAuto() << endl;
    
    return 0;
}
