/*
Autor: Mariana Marzayani Hernández Jurado

Clase derivada Episodio
Episodio.cpp
*/

// Incluir las librerías y archivos necesarios
#include "Episodio.h"
#include <sstream>

// Muestra en pantalla los datos del episodios
// Se reescribe el método
void Episodio::mostrarDatos()
{
    cout<< "Serie: "<< nombre << endl;
    cout<< "Nombre: "<< nombreEpisodio<< endl;
    cout<< "Temporada: "<< temporada<< endl;
    cout<< "Episodio:  "<< numeroEpisodio<< endl;
    cout<< "Duración: "<< duracion << endl;
    cout<< "Genero: "<< endl;
    cout<< "Calificación: "<< calificacion<< endl;
    cout<< "Fecha:  "<< fecha<< endl;
}

// Contrustor vacío
Episodio::Episodio(): Video()
{
    nombreEpisodio= "-";
    temporada= "0";
    numeroEpisodio="0";
}

// Contructor con parámetros
Episodio::Episodio(string id, string nombre, vector<string> genero, 
string calificacion, string fecha, string duracion,string idEp, string nombreEpisodio, 
string temporada, string numeroEpisodio):Video(id,  nombre, genero,  calificacion, 
 fecha,  duracion)
{
    this->nombreEpisodio= nombreEpisodio;
    this->temporada= temporada;
    this->numeroEpisodio= numeroEpisodio;
}

// Constructor a partir de un vector
Episodio::Episodio(vector<string> datos)
{
    // Asigna los datos segpun su posición
    this->id = datos[0];
    this->nombre= datos[1];
    this->duracion=datos[2]  ;
    string str = datos[3];
    vector<string> genero;
    size_t pos = 0;
    // Ciclo while para separar los géneros
    while ((pos = datos[3].find('&')) != string::npos) {
        string elemento = datos[3].substr(0, pos);
        genero.push_back(elemento);
        datos[3].erase(0, pos + 1);
    }
    genero.push_back(datos[3]);
    this->calificacion= datos[4];
    this->fecha= datos[5];
    this->idEp= datos [6];
    this->nombreEpisodio= datos[7];
    this->temporada= datos[8];
    this->numeroEpisodio= datos[9];
}
