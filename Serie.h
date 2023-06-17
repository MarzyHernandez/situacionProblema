/*
Autor: Mariana Marzayani Hernández Jurado

Clase  Serie
Serie.h
*/

// Comparación del sistema
#ifndef SERIE_H
#define SERIE_H

// Incluir las librerías y archivos necesarios
#include "Episodio.h"
#include <vector>
#include <iostream>
using namespace std;

// Clase serie
class Serie{
    private:
    // Atributos
    string nombre;
    vector<Episodio> episodios;
    float calificacionPromedio;
    public: 
    // contructores y métodos
    string getNombre();
    float getProm();
    Serie(vector<Episodio> episodios);
    void mostrarSerie();
    void promedioSerie();
    // Sobre carga de operadores
    friend std::ostream& operator<<(std::ostream& os,  Serie& serie);

};

#endif
