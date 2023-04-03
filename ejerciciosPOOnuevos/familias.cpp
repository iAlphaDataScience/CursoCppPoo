#include <iostream>
#include <string>
using namespace std;

class Familias{
    //Atributos
    protected:
        string nombreIntegrante;
    public:
        Familias(string nombreIntegrante){
            this->nombreIntegrante=nombreIntegrante;
        }
        
        string getNombre(){
            return nombreIntegrante;
        }
        void setNombre(string nombreIntegrante){
            this->nombreIntegrante=nombreIntegrante;
        }

        virtual void respiarar(){
            cout << "Puedo respirar" << endl;
        }
        void comer(){
            cout << "Puedo comer" << endl;
        }
        virtual void hablar(){
            cout << "puedo hablar" << endl;
        }
};

class Perro : public Familias {
    //Atributos
    private:
        string apodo;
    public:
        Perro(string nombreIntegrante, string apodo): Familias(nombreIntegrante){
            this->apodo=apodo;
        }
        string getApodo(){
            return apodo;
        }
        void setApodo(string apodo){
            this->apodo=apodo;
        }
        void hablar () override{
            cout << "guau" << endl;
        }

};

class Gato : public Familias {
    private:
        string apodo;
    public:               
        void maullar() {
            cout << "miau" << endl;
        }
};

class Humano : public Familias {
    public:
        Humano(string nombreIntegrante):Familias(nombreIntegrante){

        }
};

int main() {
    //Creamos instancias 
    Familias nuevo("noTiene");
    cout << nuevo.getNombre() << endl;
    nuevo.setNombre("Familiar");
    cout << nuevo.getNombre() << endl;
    nuevo.respiarar();
    nuevo.comer();

    Perro perrito("Ayudante de Santa", "huesos");
    cout << perrito.getNombre() << endl;
    cout << perrito.getApodo() << endl;
    perrito.setApodo("amigo");
    cout << perrito.getApodo() << endl;
    perrito.respiarar();
    perrito.comer();
    perrito.hablar();
    
    
    //Gato gatoSimpson();//Llama al constructor sin parametros de la clase Padre
    

    Humano manito("Angel");
    cout << manito.getNombre() << endl;
    manito.setNombre("Luis");
    cout << manito.getNombre() << endl;
    manito.hablar();
    return 0;
}
