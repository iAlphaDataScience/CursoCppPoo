#include <iostream>
#include <string>

using namespace std;

// Class declaration
class Familia {
protected:
    string nombreIntegrante;

public:
    Familia() {
        nombreIntegrante = "nada";
    }
    Familia(string nombreIntegrante) {
        this->nombreIntegrante = nombreIntegrante;
    }

    string getInfo() {
        return nombreIntegrante;
    }

    void setInfo(string nombreIntegrante) {
        this->nombreIntegrante = nombreIntegrante;
    }

    void respirar() {
        cout << "Puedo respirar" << endl;
    }

    void comer() {
        cout << "Puedo comer" << endl;
    }
};

class Gato : public Familia {
public:
    void maullar() {
        cout << "miau" << endl;
    }
};

class Perro : public Familia {
private:
    string apodo;

public:
    Perro(string nombrePerro) : Familia(nombrePerro) {
        // NO HAY CODIGO
    }

    void setApodoPerro(string apodo) {
        this->apodo = apodo;
    }

    string getApodoPerro() {
        return apodo;
    }

    void ladrar() {
        cout << "gua" << endl;
    }
};

class Humano : public Familia {
public:
    Humano(string nombreHumano) : Familia(nombreHumano) {
        // NO HAY CODIGO
    }

    void hablar() {
        cout << "soy una persona" << endl;
    }
};

int main() {
    //Creamos instancias 
    Familia Nuevo("ninguno");//Llama al constructor por parametros
    Gato gatoSimpson;//Llama al constructor sin parametros de la clase Padre
    Perro perroSimpson("Ayudante de Santa");//Llaman al segundo constructor de la clase Padre
    Humano hijoSimpson("Bart");
    Humano hijaSimpson("Lisa");

    //Utilizo las instancias
    perroSimpson.ladrar();
    gatoSimpson.maullar();
    gatoSimpson.respirar();
    Nuevo.respirar();
    cout << Nuevo.getInfo() << endl;
    hijaSimpson.hablar();

    cout << endl;
    cout << gatoSimpson.getInfo() << endl;
    gatoSimpson.setInfo("Bola de Nieve");
    cout << gatoSimpson.getInfo() << endl;
    cout << endl;

    cout << perroSimpson.getInfo() << endl;
    perroSimpson.setApodoPerro("huesos");
    cout << perroSimpson.getInfo() << endl;

    return 0;
}