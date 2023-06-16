#include "Pelicula.h"

Pelicula::Pelicula()
{
}

Pelicula::Pelicula(string id, string nombre, vector<string> genero, 
string calificacion, string fecha, string duracion): Video(id, nombre, genero,
 calificacion,  fecha,  duracion){
}

Pelicula::Pelicula(vector<string> datos)
{
    this->id = datos[0];
    this->nombre= datos[1];
    this->duracion=datos[2]  ;
    string str = datos[3];
    vector<string> genero;
    size_t pos = 0;
    while ((pos = datos[4].find('&')) != string::npos) {
        string elemento = datos[4].substr(0, pos);
        genero.push_back(elemento);
        datos[4].erase(0, pos + 1);
    }
    genero.push_back(datos[4]);
    this->calificacion= datos[4];
    this->fecha= datos[5];
}

void Pelicula::mostrarDatos()
{
    cout<< "Nombre: "<< nombre<< endl;
    cout<< "Duración: "<< duracion << endl;
    cout<< "Genero: "<< endl;
    cout<< "Calificación: "<< calificacion<< endl;
    cout<< "Fecha:  "<< fecha<< endl;
}