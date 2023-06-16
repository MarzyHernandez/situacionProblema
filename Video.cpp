#include "Video.h"
#include <iostream>
using namespace std;

Video::Video()
{
    id="-";
    nombre="-";
    genero.push_back("-");
    calificacion= "0.0";
    fecha= "-/-/-";
    duracion= "0";

}

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

string Video::getID()
{
    return id;
}

string Video::getNombre()
{
    return nombre;
}

vector<string> Video::getGenero()
{
    return genero;
}

float Video::getCalificacion()
{
    float calf= stof(calificacion);
    return calf;
}

int Video::getDuracion()
{
    int durac= stoi(duracion);
    return durac;
}

string Video::getFecha()
{
    return fecha;
}

void Video::promedioCalificacion(float calificacion)
{
    float c= (this->getCalificacion()+calificacion)/2;
    this->calificacion= to_string(c);
}

void Video::mostrarDatos()
{
}
