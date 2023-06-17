/*
Autor: Mariana Marzayani Hernández Jurado

Clase derivada Pelicula
Pelicula.cpp
*/

// Incluir las librerías y archivos necesarios
#include "Pelicula.h"

// Cosntructor vacío
Pelicula::Pelicula()
{
}

// Constructor con parámetros
Pelicula::Pelicula(string id, string nombre, vector<string> genero, 
string calificacion, string fecha, string duracion): Video(id, nombre, genero,
 calificacion,  fecha,  duracion){
}

// Constructor a partir de un vector
Pelicula::Pelicula(vector<string> datos)
{
    // Asigna los datos segpun su posición
    this->id = datos[0];
    this->nombre= datos[1];
    this->duracion=datos[2]  ;
    string str = datos[3];
    vector<string> genero;
    size_t pos = 0;
    // Ciclo while para separar los géneros
    while ((pos = datos[3].find('&')) != string::npos) {
        string elemento = datos[3].substr(0, pos);
        genero.push_back(elemento);
        datos[3].erase(0, pos + 1);
    }
    genero.push_back(datos[3]);
    this->genero= genero;
    this->calificacion= datos[4];
    this->fecha= datos[5];
}

// Muestra en pantalla los datos de la película
// Se sobreescribe el método
void Pelicula::mostrarDatos()
{
    cout<< "Nombre: "<< nombre<< endl;
    cout<< "Duración: "<< duracion << endl;
    cout<< "Genero: ";
    for (string i: this->getGenero()){
        cout << i <<" ";
    }
    cout<< endl;
    cout<< "Calificación: "<< calificacion<< endl;
    cout<< "Fecha:  "<< fecha<< endl;
    cout <<"---------------------------------" <<endl;
}