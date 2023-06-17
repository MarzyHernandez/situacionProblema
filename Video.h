/*
Autor: Mariana Marzayani Hernández Jurado

Clase base Video
Video.h
*/

// Comparación del sistema
#ifndef VIDEO_H
#define VIDEO_H

// Incluir las librerías y archivos necesarios
#include <vector>
#include <iostream>
using namespace std;

// Declaración de la clase abstracta video
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
    void setCalificacion(float calificacion);
    // Función virtual pura
    virtual void mostrarDatos()=0;
};

#endif

