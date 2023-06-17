#ifndef SERIE_H
#define SERIE_H

#include "Episodio.h"
#include <vector>
#include <iostream>
using namespace std;

class Serie{
    private:
    string nombre;
    vector<Episodio> episodios;
    float calificacionPromedio;
    public: 
    string getNombre();
    float getProm();
    Serie(vector<Episodio> episodios);
    void mostrarSerie();
    void promedioSerie();
    friend std::ostream& operator<<(std::ostream& os,  Serie& serie);

};

#endif
