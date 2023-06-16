#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"
#include <iostream>
#include <vector>
using namespace std;

class Pelicula: public Video{
    public:
    Pelicula();
    Pelicula(string id, string nombre, vector<string> genero, string calificacion, 
    string fecha, string duracion);
    Pelicula(vector<string> datosP);
    void mostrarDatos();
};

#endif