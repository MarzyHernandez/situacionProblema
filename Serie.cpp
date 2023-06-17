#include "Serie.h"
#include <iostream>
using namespace std;

string Serie::getNombre()
{
    return this->nombre;
}

float Serie::getProm()
{
    return this->calificacionPromedio;
}

Serie::Serie(vector<Episodio> episodios)
{
    this->nombre = episodios[0].getNombre();
    this->episodios = episodios;
    promedioSerie();
}

void Serie::mostrarSerie()
{
    for (Episodio i: episodios){
        i.mostrarDatos();
        cout <<endl;
    }
}

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
