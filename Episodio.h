/*
Autor: Mariana Marzayani Hernández Jurado

Clase derivada Episodio
Episodio.h
*/

// Comparación del sistema
#ifndef EPISODIO_H
#define EPISODIO_H

// Incluir las librerías y archivos necesarios
#include "Video.h"
#include <vector>
#include <iostream>

// Clase derivada Episodio
class Episodio: public Video{
private:
    string idEp;
    string nombreEpisodio;
    string temporada;
    string numeroEpisodio;
public:
    Episodio();
    Episodio(string id, string nombre, vector<string> genero, string calificacion, 
    string fecha, string duracion,string idEp, string nombreEpisodio, string temporada, string numeroEpisodio);
    Episodio(vector<string> datosE);
    void mostrarDatos();
    string getNombreEp();
};

#endif