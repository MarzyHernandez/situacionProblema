/*
Autor: Mariana Marzayani Hernández Jurado

Clase  Serie
Serie.cpp
*/

// Incluir las librerías y archivos necesarios
#include "Serie.h"
#include <iostream>
using namespace std;

// Devueve el nombre de la serie
string Serie::getNombre()
{
    return this->nombre;
}

// Devuelve el promedio de todos los episodios de la serie
float Serie::getProm()
{
    return this->calificacionPromedio;
}

// Constructor con parámetros. Recibe un vector de episodios 
Serie::Serie(vector<Episodio> episodios)
{
    this->nombre = episodios[0].getNombre();
    this->episodios = episodios;
    promedioSerie();
}

// Recore los episodios y llama su método mostrarDatos
void Serie::mostrarSerie()
{
    for (Episodio i: episodios){
        i.mostrarDatos();
        cout <<endl;
    }
}

// Saa el promedio de los episodios de la serie
void Serie::promedioSerie()
{
    float cal=0;
    float prom=0;
    for (Episodio episodio: episodios){
        cal+=episodio.getCalificacion();
    }
    prom = cal/episodios.size();
    this->calificacionPromedio= prom;
}

// Sobrecarga de operadores
// Regresa los generales datos de la serie y llama nostrar Serie
std::ostream &operator<<(std::ostream &os,  Serie &serie)
{
    os <<endl <<"----------SERIE------------"<<endl;
    os << "Serie: " << serie.getNombre() <<endl;
    os << "Calificación promedio: " << serie.getProm() <<endl <<endl;
    os << "Mostrando episodios.. "  <<endl <<endl;
    os <<endl <<"---------------------------"<<endl;
    serie.mostrarSerie();
    return os;
}
