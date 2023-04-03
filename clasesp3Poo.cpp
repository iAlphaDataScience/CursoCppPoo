#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <ctime>
#include <ratio>
using namespace std;
using namespace std::chrono;

//______________________________________________________________________________________
class Clientes
{
private:
    string Documento;
    string Nombre;
    string Apellido;
    string Direccion;
    string Telefono;

public:
    Clientes() {}

    Clientes(string Documento, string Nombre, string Apellido, string Direccion, string Telefono)
    {
        this->Documento = Documento;
        this->Nombre = Nombre;
        this->Apellido = Apellido;
        this->Direccion = Direccion;
        this->Telefono = Telefono;
    }

    void setDocumento(string Documento) { this->Documento = Documento; }
    string getDocumento() { return this->Documento; }

    void setNombre(string Nombre) { this->Nombre = Nombre; }
    string getNombre() { return this->Nombre; }

    void setApellido(string Apellido) { this->Apellido = Apellido; }
    string getApellido() { return this->Apellido; }

    void setDireccion(string Direccion) { this->Direccion = Direccion; }
    string getDireccion() { return this->Direccion; }

    void setTelefono(string Telefono) { this->Telefono = Telefono; }
    string getTelefono() { return this->Telefono; }

    string DarNombreCompleto()
    {
        return this->Nombre + ", " + this->Apellido;
    }
};

//______________________________________________________________________________________
class Trailer
{
private:
    string Url;
    short Duracion;

public:
    Trailer() {}

    Trailer(string Url, short Duracion)
    {
        this->Url = Url;
        this->Duracion = Duracion;
    }

    void setUrl(string Url) { this->Url = Url; }
    string getUrl() { return this->Url; }

    void setDuracion(short Duracion) { this->Duracion = Duracion; }
    short getDuracion() { return this->Duracion; }
};

//______________________________________________________________________________________
class Pelicula
{
private:
    int numeroCopia;
    string Titulo;
    string Sinopsis;
    string Genero;
    string paisOrigen;
    vector<Trailer> colTrailer;

public:
    Pelicula() {}

    Pelicula(int numeroCopia, string Titulo, string Sinopsis, string Genero, string paisOrigen)
    {
        this->numeroCopia = numeroCopia;
        this->Titulo = Titulo;
        this->Sinopsis = Sinopsis;
        this->Genero = Genero;
        this->paisOrigen = paisOrigen;
        this->colTrailer = std::vector<Trailer>(); // Agregacion
    }

    void AgregarTrailer(string url, short duracion)
    {
        Trailer miTrailer = Trailer(url, duracion);
        colTrailer.push_back(miTrailer);
    }

    void setnumeroCopia(int numeroCopia) { this->numeroCopia = numeroCopia; }
    int getnumeroCopia() { return this->numeroCopia; }

    void setTitulo(string Titulo) { this->Titulo = Titulo; }
    string getTitulo() { return this->Titulo; }

    void setSinopsis(string Sinopsis) { this->Sinopsis = Sinopsis; }
    string getSinopsis() { return this->Sinopsis; }

    void setGenero(string Genero) { this->Genero = Genero; }
    string getGenero() { return this->Genero; }

    void setpaisOrigen(string paisOrigen) { this->paisOrigen = paisOrigen; }
    string getpaisOrigen() { return this->paisOrigen; }

    void setcolTrailer(vector<Trailer> colTrailer) { this->colTrailer = colTrailer; }
    vector<Trailer> getcolTrailer() { return this->colTrailer; }

    // Ejercicio 5
    short TotalTiempoTrailers()
    {
        short total = 0;

        for (Trailer item : this->colTrailer)
        {
            total += item.getDuracion();
        }

        return total;
    }
};


//______________________________________________________________________________________
class Alquiler {
private:
    float costoBase = 80; // No está en UML. Se usa para calcular el costo total
    int Numero;
    string fechaInicio;
    string fechaFinal;
    float costoTotal;
    Clientes Cliente; // Tiene un objeto de tipo Cliente
    vector<Pelicula> colPeliculas; // Tiene una lista de Peliculas

public:
    Alquiler() {}

    Alquiler(int Numero, string fechaInicio, string fechaFinal, float costoTotal, Clientes Cliente, vector<Pelicula> colPeliculas) {
        this->Numero = Numero;
        this->fechaInicio = fechaInicio;
        this->fechaFinal = fechaFinal;
        this->costoTotal = costoTotal;
        this->Cliente = Cliente;
        this->colPeliculas = colPeliculas;
    }

    void setNumero(int Numero) {
        this->Numero = Numero;
    }

    int getNumero() {
        return this->Numero;
    }

    void setFechaInicio(string fechaInicio) {
        this->fechaInicio = fechaInicio;
    }

    string getFechaInicio() {
        return this->fechaInicio;
    }

    void setFechaFinal(string fechaFinal) {
        this->fechaFinal = fechaFinal;
    }

    string getFechaFinal() {
        return this->fechaFinal;
    }

    void setCostoTotal(float costoTotal) {
        this->costoTotal = costoTotal;
    }

    float getCostoTotal() {
        return this->costoTotal;
    }

    void setCliente(Clientes Cliente) {
        this->Cliente = Cliente;
    }

    Clientes getCliente() {
        return this->Cliente;
    }

    void setColPeliculas(vector<Pelicula> colPeliculas) {
        this->colPeliculas = colPeliculas;
    }

    vector<Pelicula> getColPeliculas() {
        return this->colPeliculas;
    }

    // Punto c) ii)
    string darNombreCompletoCliente() {
        return this->Cliente.DarNombreCompleto();
    }

    // Punto c) iii)
    double darCostoTotal() {
        return this->costoTotal = this->colPeliculas.size() * costoBase;
    }

    bool documentoClienteAlquiler(string documento) {
        if (this->Cliente.getDocumento() == documento) {
            return true;
        }
        else {
            return false;
        }
    }
};

//____________________________________________________________________________________________
class Videoclub {
private:
    vector<Pelicula> colPeliculas;
    vector<Clientes> colClientes;
    vector<Alquiler> colAlquileres;

public:
    Videoclub() {}

    Videoclub(std::vector<Clientes> colClientes, vector<Pelicula> colPeliculas, std::vector<Alquiler> colAlquileres) {
        this->colClientes = colClientes;
        this->colPeliculas = colPeliculas;
        this->colAlquileres = colAlquileres;
    }

    void setColPeliculas(vector<Pelicula> colPeliculas) {
        this->colPeliculas = colPeliculas;
    }

    vector<Pelicula> getColPeliculas() {
        return this->colPeliculas;
    }

    void setColClientes(vector<Clientes> colClientes) {
        this->colClientes = colClientes;
    }

    vector<Clientes> getColClientes() {
        return this->colClientes;
    }

    void setColAlquileres(vector<Alquiler> colAlquileres) {
        this->colAlquileres = colAlquileres;
    }

    std::vector<Alquiler> getColAlquileres() {
        return this->colAlquileres;
    }

    //Punto c) i)
    bool BuscarCliente(string documento) {
        for (Clientes item : this->colClientes) {
            if (item.getDocumento() == documento) {
                return true;
            }
        }
        return false;
    }

    //Punto c) iv)
    vector<Alquiler> DarAlquileresPorDocumento(string documento) {
        std::vector<Alquiler> colAlquileresCliente;
        for (Alquiler item : this->colAlquileres) {
            // if(item.documentoClienteAlquiler(documento))
            if (item.getCliente().getDocumento() == documento) {
                colAlquileresCliente.push_back(item);
            }
        }
        return colAlquileresCliente;
    }
};
/*
class DateTime {
public:
    DateTime() {
        auto now = system_clock::now();
        time_t now_c = system_clock::to_time_t(now);
        localtime_s(&timeinfo, &now_c);
    }
    int Year() const { return timeinfo.tm_year + 1900; }
    int Month() const { return timeinfo.tm_mon + 1; }
    int Day() const { return timeinfo.tm_mday; }
    int Hour() const { return timeinfo.tm_hour; }
    int Minute() const { return timeinfo.tm_min; }
    int Second() const { return timeinfo.tm_sec; }
    void AddDays(int days) { 
        auto now = system_clock::now();
        now += days * hours(24);
        time_t now_c = system_clock::to_time_t(now);
        localtime_s(&timeinfo, &now_c);
    }
private:
    struct tm timeinfo;
};*/

//______________________________________________________________________________________
int main() {
    //Se crean los clientes (2) y la Lista de clientes
            vector<Clientes> colClientes;
            Clientes cli1("12226668", "Pepe", "Perez", "Av Pepe 123", "09000000");
            Clientes cli2("12227779", "Ana", "Perez", "Av Ana 321", "09111111");
            colClientes.push_back(cli1);
            colClientes.push_back(cli2);
    
    //Se crean las peliculas (6), los trailers (1 o 2 por pelicula) y las respectivas listas            
            Pelicula peli1(1, "Titanic", "Regular", "Drama", "EEUU");
            peli1.AgregarTrailer("url1", 10);
            peli1.AgregarTrailer("url2", 15);          
            Pelicula peli2(2, "El Rey Leon", "Muy Buena", "Animación", "EEUU");
            peli2.AgregarTrailer("url3", 5);            
            Pelicula peli3(3, "Terminator 2: Judgment Day", "Muy Buena", "Ciencia Ficcion", "EEUU");
            peli3.AgregarTrailer("url4", 7);           
            Pelicula peli4(4, "Star Wars: Episode IV - A New Hope", "Muy Buena", "Ciencia Ficcion", "EEUU");
            peli4.AgregarTrailer("url5", 1);           
            Pelicula peli5(5, "The Matrix", "Muy Buena", "Ciencia Ficcion", "EEUU");
            peli5.AgregarTrailer("url6", 15);           
            Pelicula peli6(6, "The NeverEnding Story", "Buena", "Fantacia", "EEUU");
            peli6.AgregarTrailer("url7", 18);                    
            vector<Pelicula> colPeliculas;
            colPeliculas.push_back(peli1);
            colPeliculas.push_back(peli2);
            vector<Pelicula> colPeliculas2;
            colPeliculas2.push_back(peli3);
            colPeliculas2.push_back(peli4);
            colPeliculas2.push_back(peli5);//Nadie Alquilo The NeverEnding Story
    
    //Se crean los alquileres y lista de alquileres
            vector<Alquiler> colAlquileres;//La función AddDays permite agregar días a la fecha  
            Alquiler nuevoAli1(1, "03/04/23", "04/04/23", 0, cli1, colPeliculas);
            Alquiler nuevoAli2(2, "03/04/23", "04/04/23", 0, cli2, colPeliculas2);                       
            colAlquileres.push_back(nuevoAli1);
            colAlquileres.push_back(nuevoAli2);
    
    //Se crea el Video club
            Videoclub nuevoVideoClub(colClientes, colPeliculas,  colAlquileres);
            string documento = "12226667";
            string registro;
            bool existeElCliente = nuevoVideoClub.BuscarCliente(documento);

            if (existeElCliente) {
                registro = "esta registrado";
            } else {
                registro = "no esta registrado";
            }
            cout << "\nPunto c) i): El documento " << documento << " " << registro << endl;
    return 0; 
}