/*
Autor: Mariana Marzayani Hernández Jurado

Clase derivada Pelicula
Pelicula.h
*/

// Comparación del sistema
#ifndef PELICULA_H
#define PELICULA_H

// Incluir las librerías y archivos necesarios
#include "Video.h"
#include <iostream>
#include <vector>
using namespace std;

// Clase derivda Pelicula
class Pelicula: public Video{
    public:
    Pelicula();
    Pelicula(string id, string nombre, vector<string> genero, string calificacion, 
    string fecha, string duracion);
    Pelicula(vector<string> datosP);
    // Sobreescribe método 
    void mostrarDatos();
};

#endif