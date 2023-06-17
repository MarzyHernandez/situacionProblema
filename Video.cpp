/*
Autor: Mariana Marzayani Hernández Jurado

Clase base Video
Video.cpp
*/

// Incluir las librerías y archivos necesarios
#include "Video.h"
#include <iostream>
using namespace std;

// Constructor vació de Video
Video::Video()
{
    id="-";
    nombre="-";
    genero.push_back("-");
    calificacion= "0.0";
    fecha= "-/-/-";
    duracion= "0";

}

// Constructor con parámetros
Video::Video(string id, string nombre, vector<string> genero, string calificacion, 
string fecha, string duracion)
{
    this->id=id;
    this->nombre= nombre,
    this-> genero= genero;
    this-> calificacion = calificacion;
    this-> fecha= fecha;
    this-> duracion = duracion;
}

// Devuelve le ID del video
string Video::getID()
{
    return id;
}

// Devuelve el nombre del video
string Video::getNombre()
{
    return nombre;
}

// Devueve el género
vector<string> Video::getGenero()
{
    return genero;
}

// Devuelve la calificacion
float Video::getCalificacion()
{
    float calf= stof(calificacion);
    return calf;
}

// Cambia la calificación 
void Video::setCalificacion(float calificacion)
{
    this->calificacion= to_string(calificacion);
}

void Video::mostrarDatos()
{
}
