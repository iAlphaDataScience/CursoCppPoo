#include <iostream>
#include <string>
using namespace std;

class Auto{
    //Atributos
    private:
        double peso;
        double longitud;
        double altura;
        bool climatizador;
        string tapiceria;
    
    public:
        //Constructores (son metodos que se llaman igual que la clase)    
        Auto(){
            this->peso=30;
            this->longitud=3;
            this->altura=2;
            this->climatizador=true;
            this->tapiceria="cuero sintetico";
        }          
        Auto(double _peso, double longitud, double altura, bool climatizador, string tapiceria){
            this->peso=peso;
            this->longitud=longitud;
            this->altura=altura;
            this->climatizador=climatizador;
            this->tapiceria=tapiceria;
        }       
        void setExtras (bool climatizador, string tapiceria){// no retorna nada
            this->climatizador = climatizador;
            this->tapiceria = tapiceria;
        }
        
        void setNoExtras (double peso, double longitud, double altura){// no retorna nada
            this->peso = peso;
            this->longitud= longitud;
            this->altura = altura;
        }
        void setNoExtras (double longitud, double altura){// no retorna nada
            this->longitud= longitud;
            this->altura = altura;
        }
                
        void setClimatizador(bool climatizador){
            this->climatizador = climatizador;
        }                
        bool getClimatizador(){//retorna un booleano
            return this->climatizador;
        }
        

        void setTaceria(string tapiceria){
            this->tapiceria = tapiceria;
        }               
        string getTapiceria(){//retorna un booleano
            return this->tapiceria;
        }
};


int main(){

    Auto auto2(35, 5, 2, false, "cuero");
    Auto auto3(40, 5 , 2, false, "tela");
    Auto auto4; //llama al constructor sin parametros
    
    cout << auto2.getClimatizador()<< endl;
    cout << auto2.getTapiceria()<< endl;
 
    auto2.setClimatizador(true);
    auto2.setTaceria("tela");

    cout << auto2.getClimatizador() << endl;
    cout << auto2.getTapiceria() << endl;

    /* Para que no pase esto, son los getters y setters
    auto2.altura=100;
    cout << auto2.altura;*/
    
    //Pruebo el constructor sin paramatros
    cout << auto4.getClimatizador() << endl;
    cout << auto4.getTapiceria() << endl;
}