#ifndef VIDEO_H
#define VIDEO_H

#include <vector>
#include <iostream>
using namespace std;

class Video {
protected:
    string id;
    string nombre;
    vector<string> genero;
    string calificacion;
    string fecha;
    string duracion;
public:
    Video();
    Video(string id, string nombre, vector<string> genero, 
    string calificacion, string fecha, string duracion);
    string getID();
    string getNombre();
    vector<string> getGenero();
    float getCalificacion();
    int getDuracion();
    string getFecha();
    void promedioCalificacion(float calificacion);
    virtual void mostrarDatos();
};

#endif
