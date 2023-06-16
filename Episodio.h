#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"
#include <vector>
#include <iostream>

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
};

#endif