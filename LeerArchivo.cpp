/*
Autor: Mariana Marzayani Hernández Jurado

Leer el archivo de texto en C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> separar(string linea);

int main()
{
    ifstream entrada;
    entrada.open("DatosPeliculas.csv");
    string linea;
    int numerolinea = 1;
    while (getline(entrada, linea))
    {
        // cout<<(numerolinea++) <<linea <<endl;
        vector<string> datos = separar(linea);
        separar(linea);
        if (numerolinea != 1)
        {
            if (datos.size() == 6)
            {
                cout << numerolinea << "Pelicula: " << endl;
                // new Pelicula (datos); constructor de pelíucla que acepte un vector
            }
            else
            {
                cout<< numerolinea << "Episodio: " << endl;
            }
        }
        numerolinea++;
    }
    entrada.close();
    return 0;
}

vector<string> separar(string linea)
{
    vector<string> tokens; // Componentes de la línea

    stringstream entrada(linea); // Flujo de datos
    string dato;
    int numeroTokens = 0;
    while (getline(entrada, dato, ','))
    {
        if (dato != "" && dato != "\n" && dato != "\r")
        {
            // cout<< dato <<endl;
            tokens.push_back(dato); // Guarda el vector
            numeroTokens++;
        }
    }
    // cout<< "Tokens: "<<numeroTokens <<endl <<endl;

    return tokens;
}
