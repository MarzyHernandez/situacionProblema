/*
Autor: Mariana Marzayani Hernández Jurado

Leer el archivo de texto en C++
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include "Video.h"
#include "Pelicula.h"
#include "Episodio.h"

using namespace std;

vector<string> separar(string linea);
vector<Video *> CargarArchivo();

int main()
{
    vector<Video *> contenido;
    float calf;
    int opcion;
    bool menu=false;
    while (!menu){
        cout<< "----MENÚ PRINCIPAL-----"<<endl <<endl;
        cout<< "1. Cargar el Archivo de Peliculas" <<endl;
        cout<< "2. Filtrar resultados" <<endl;
        cout<< "3. Buscar serie" <<endl;
        cout<< "4. Filtrar películas" <<endl;
        cout<< "5. Calificar contenido" <<endl;
        cout<< "6. Salir" <<endl;
        cout<< "Ingresa la opción que deseas: ";
        cin>> opcion;

        switch (opcion)
        {
        case 1:
            contenido = CargarArchivo();
            this_thread::sleep_for(chrono::seconds(1));
            break;
        
        case 2: 
            calf= contenido[1]->getCalificacion();
            cout<<calf;
            break;
        
        default:
            menu=true;
            break;
        }
    }
    cout << "Hola mundo" << endl;
    
    
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

vector<Video *> CargarArchivo()
{
    vector<Video *> principal;
    ifstream entrada;
    string nombreArchivo;
    bool archivoValido = false;
    while (!archivoValido)
    {
        cout << "Ingrese el nombre del archivo a cargar: ";
        cin >> nombreArchivo;
        try
        {
            ifstream archivo(nombreArchivo);
            if (archivo.is_open())
            {
                archivoValido = true;
                cout << "Archivo cargado exitosamente." << endl<<endl;
                
                archivoValido = true;
                entrada.open(nombreArchivo);
                string linea;
                int numerolinea = 1;
                while (getline(entrada, linea))
                {
                    vector<string> datos = separar(linea);
                    separar(linea);
                    if (numerolinea != 1)
                    {
                        if (datos.size() == 6)
                        {
                            Pelicula *p = new Pelicula(datos);
                            principal.push_back(p);
                        }
                        else
                        {
                            Episodio *ep = new Episodio(datos);
                            principal.push_back(ep);
                        }
                    }
                    numerolinea++;
                }
                /*for (Video* i : principal)
                {
                    cout<<endl;
                    i->mostrarDatos();
                }*/
                entrada.close();
            }
            else
            {
                throw runtime_error("El archivo no existe.");
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, ingrese un nombre de archivo válido." << endl;
        }
    }

    return principal;
}
