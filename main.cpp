/*
Autor: Mariana Marzayani Hernández Jurado

Leer el archivo de texto en C++
*/

//Cargar librerías y archivos necesarios
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <thread>
#include <algorithm>
#include <cctype>
#include "Video.h"
#include "Serie.h"
#include "Pelicula.h"
#include "Episodio.h"

using namespace std;

// Declarar las funciones
vector<Episodio *> episodios;
vector<string> separar(string linea);
vector<Video *> CargarArchivo();
string eliminarEspacios(const string &cadena);
bool buscarGenero(const string &generoBuscado, const vector<string> &generos);

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


// Función main principal
int main()
{
    // Inicializar variables de la función
    int aux = 0;
    int serie_usuario;
    vector<Episodio> serie;
    vector<Serie> series;
    vector<Video *> contenido;
    float calf;
    int opcion;
    bool menu = false;

    // Este ciclo while permite que el usuario pueda ver el menú y realizar acciones 
    // hasta que seleccione la opción de salir
    while (!menu)
    {
        // Mostrar el menú principal
        cout << "----MENÚ PRINCIPAL-----" << endl
             << endl;
        cout << "1. Cargar el Archivo de Peliculas" << endl;
        cout << "2. Filtrar resultados" << endl;
        cout << "3. Buscar serie" << endl;
        cout << "4. Filtrar películas" << endl;
        cout << "5. Calificar contenido" << endl;
        cout << "6. Salir" << endl;
        cout << "Ingresa la opción que deseas: ";
        cin >> opcion;

        // Switch case para comparar la selección del usuario
        switch (opcion)
        {
        // Case 1. Cargar el archivo de películas
        /*Si el usuario no ha cargado este archivo, no puede ir a ningun otro lugar
        del menú y si la yo ha cargado, se recalca que no es necesario cargarlo nuevamente*/
        case 1:
            // if ace uso de una variable auxiliar para saber si ya se ha cargado el archivo
            if (aux == 0)
            {
                contenido = CargarArchivo();
                this_thread::sleep_for(chrono::seconds(1));
                aux = 1;
            }
            else
            {
                cout << "Ya haz cargado el archivo" << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }

            break;
        // Case 2. Filtrar resultados
        case 2:
            // Condicional para asegurar que el usuario ya cargó el archvo
            if (aux == 1)
            {
                // Inicialización de variables locales
                int op;
                string gen;
                float cal;
                // Submenú de opciones
                cout << endl
                     << " Filtrar contenido : " << endl
                     << endl;
                cout << " 1. Filtrar por calificación " << endl;
                cout << " 2. Filtrar por género: " << endl
                     << endl;
                cout << "Ingresa la opción: ";
                cin >> op;
                // Acceder a la opción elegida
                if (op == 1)
                {
                    cout << "Filtrar contenido por calificación: " << endl;
                    cout << "Ingrese la calificación mínima(1-7): ";
                    cin >> cal;
                    if (cal > 7 || cal < 1)
                    {
                        cout << "No hay contenido con esa calificación" << endl;
                    }
                    else
                    {
                        cout << "Cargando contenido con calificación mayor a " << cal << endl
                             << endl;
                        this_thread::sleep_for(chrono::seconds(1));
                        // Se recorre el vector con todos los videos para hacer la comparación uno por uno
                        for (Video *cont : contenido)
                        {
                            if (cont->getCalificacion() >= cal)
                            {
                                cont->mostrarDatos();
                                cout << endl;
                            }
                        }
                    }
                }
                else if (op == 2)
                {
                    cout << "Filtrar contenido por género: " << endl;
                    cout << "Ingrese el género: ";
                    cin >> gen;
                    string genNuevo = eliminarEspacios(gen);
                    // Se recorre todo el vector de videos para saber que genero coincide
                    for (Video *cont : contenido)
                    {
                        if (buscarGenero(genNuevo, cont->getGenero()))
                        {
                            cont->mostrarDatos();
                            cout << endl;
                        }
                    }
                    this_thread::sleep_for(chrono::seconds(1));
                }
                // Si no se ha elegido una opción válida, se regresa al menú principal
                else
                {
                    cout << "Ingrese una opción válida." << endl
                         << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }
            else
            {
                // En caso de que el usuario no haya cargado el archivo 
                cout << "Debes de cargar el archivo primero " << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;

        // Case 3. Buscar serie
        case 3:
            // Condicional para asegurar que el usuario ya cargó el archvo
            if (aux == 1)
            {
                // Se recorre el vector de eposiodios
                for (int i = 0; i < episodios.size(); i++)
                {
                    // Se agrupan los episodios por series
                    serie.push_back(*episodios[i]);
                    if (i + 1 == episodios.size() || episodios[i]->getNombre() != episodios[i + 1]->getNombre())
                    {
                        Serie nuevaSerie(serie);
                        series.push_back(nuevaSerie);
                        serie.clear();
                    }
                }
                // Se muestra un menú con las series disponibles
                cout << "Series disponibles: " << endl
                     << endl;
                for (int i = 0; i < series.size(); i++)
                {
                    cout << i + 1 << ". " << series[i].getNombre() << endl;
                }
                cout << endl;
                // Elección del usuario
                cout << "Ingresa el número de la serie: ";
                cin >> serie_usuario;
                // Se muestran los episodios de la serie seleccionada
                // Sobrecarga de << en la clase Serie
                cout<< series[serie_usuario - 1];
                this_thread::sleep_for(chrono::seconds(1));
            }
            else
            {
                 // En caso de que el usuario no haya cargado el archivo 
                cout << "Debes de cargar el archivo primero " << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }

            break;

        // Case 4. Filtrar películas
        case 4:
            // Condicional para asegurar que el usuario ya cargó el archvo
            if (aux == 1)
            {
                // Declara variable local
                float cal;
                cout << "Filtar películas" << endl
                     << endl;
                // Elección del usuario
                cout << "Ingresa la calificación mínima que deseas que tenga la película (1-7): ";
                cin >> cal;
                if (cal > 7 || cal < 1)
                {
                    // Se verifica que la opción este en el rango
                    cout << " Ingresa una opción válida" << endl;
                    this_thread::sleep_for(chrono::seconds(1));
                }
                else
                {
                    // Recorre el vector
                    for (Video *video : contenido)
                    {
                        // Se asegura de que los obejtos sean de tipo Pelicula
                        Pelicula *pelicula = dynamic_cast<Pelicula *>(video);
                        if (pelicula != nullptr)
                        {
                            // Compara las califiicaciones
                            if (video->getCalificacion() >= cal)
                            {
                                video->mostrarDatos();
                                cout << endl;
                            }
                        }
                    }
                    this_thread::sleep_for(chrono::seconds(1));
                }
            }
            else
            // En caso de que el usuario no haya cargado el archivo 
            {
                cout << "Debes de cargar el archivo primero " << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;

        // Case 5. Calificar contenido
        case 5:
            // Condicional para asegurar que el usuario ya cargó el archvo
            if (aux == 1)
            {
                // Inicialización de variables locales
                string nombreContenido;
                string nombreModificado;
                string nombreComparar;
                float cal;

                // Datos al usuario 
                cout << "Calificar contenido" << endl
                     << endl;
                cout << "Ingresa el nombre de la película o del episodio: ";
                cin >> ws;  // Ignorar espacios en blanco previos
                getline(cin, nombreContenido);
                // Mofificar la cadena para su comparación
                nombreModificado = eliminarEspacios(nombreContenido);
                // Recorre el vector
                for (Video *video : contenido)
                {
                    // Condicional para Pelicula y Episodio
                    Episodio *episodio = dynamic_cast<Episodio *>(video);
                    if (episodio != nullptr)
                    {
                        nombreComparar = episodio->getNombreEp();
                    }
                    Pelicula *pelicula = dynamic_cast<Pelicula *>(video);
                    if (pelicula != nullptr)
                    {
                        nombreComparar = pelicula->getNombre();
                    }
                    // Modifica el nombre para su comparación
                    nombreComparar=eliminarEspacios(nombreComparar);

                    // Se busca si el dato ingresado esta en el nombre del video actual
                    if(nombreComparar.find(nombreModificado) != std::string::npos){
                        // Ciclo do while para que asegurarse que se agrega una calificación válida
                        do{
                            cout<< "Ingresa tu calificacion para " <<video->getNombre() <<": ";
                            cin >>cal;
                        }
                        while(cal>7 || cal<1); // Rango de entre 1 y 7
                        video->setCalificacion(cal);
                        cout <<"Gracias por tu retroalimentación" <<endl <<endl;
                        break;
                    }
                }
            }
            else
            // En caso de que el usuario no haya cargado el archivo 
            {
                cout << "Debes cargar el archivo primero " << endl
                     << endl;
                this_thread::sleep_for(chrono::seconds(1));
            }
            break;

        // Case 6. Salir
        case 6:
            cout << "Saliendo..." << endl;
            this_thread::sleep_for(chrono::seconds(1));

            // menu se vuelve true para terminar el ciclo while
            menu = true;
            break;

        // Opción default
        default:
            cout << "Porfavor ingrese una opción válida" << endl;
            this_thread::sleep_for(chrono::seconds(1));
            menu = true;
            break;
        }
    }
    cout << "GRACIAS" << endl;
    return 0;
}

// Función separar que recibe un string y regresa un vector de tipo string
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

// Funcion CargarArchivo. No recibe parámetros y devuelve un vector de tipo Video
vector<Video *> CargarArchivo()
{
    // Inicialización de variable
    vector<Video *> principal;
    ifstream entrada;
    string nombreArchivo;
    bool archivoValido = false;

    // Ciclo while para asegurar que el archivo es válido
    while (!archivoValido)
    {
        // Datos ingresados por el usuario
        cout << "Ingrese el nombre del archivo a cargar: ";
        cin >> nombreArchivo;

        // Bloque try catch para uso de excepciones
        try
        {
            // Abre el arhivo
            ifstream archivo(nombreArchivo);
            if (archivo.is_open())
            {
                // Cambia archivoValido para termianr el ciclo while
                archivoValido = true;
                // Mensaje para el usuario
                cout << "Archivo cargado exitosamente." << endl
                     << endl;
                
                entrada.open(nombreArchivo);
                string linea;
                int numerolinea = 1;
                // Ciclo anidado while para que se lea línea por línea
                while (getline(entrada, linea))
                {
                    vector<string> datos = separar(linea);
                    separar(linea);
                    // Se quita la primera línea
                    if (numerolinea != 1)
                    {
                        // Estructura if para saber si es una película o un episodio por su longitud
                        if (datos.size() == 6)
                        {
                            // Crea un nuevo Pelicula
                            Pelicula *p = new Pelicula(datos);
                            principal.push_back(p);
                        }
                        else
                        {
                            // Crea un nuevo episodio
                            Episodio *ep = new Episodio(datos);
                            principal.push_back(ep);
                            episodios.push_back(ep);
                        }
                    }
                    // Aumenta el contador
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
                // Excepcion
                throw runtime_error("El archivo no existe.");
            }
        }
        catch (const exception &e)
        {
            cout << "Error: " << e.what() << endl;
            cout << "Por favor, ingrese un nombre de archivo válido." << endl;
        }
    }
    // Regresa un vector de video
    return principal;
}

// Función eliminarEspacios para hacer minúsculas los caracteres, borrar espacios y borrar los "-"
string eliminarEspacios(const std::string &cadena)
{
    // Inicialliza la cadena resultante
    std::string resultado;
    // Recorre toda la cadena
    for (char c : cadena)
    {
        if (!isspace(c) && c != '-')
        {
            resultado += tolower(c);
        }
    }
    // Devuelve la cadena nueva o normalizada
    return resultado;
}

// Función buscarGenero para filtrar si se encuentra el género entre un vector. Devuelve un booleano
bool buscarGenero(const string &generoBuscado, const vector<string> &generos)
{
    // Convertir el género buscado a minúsculas y eliminar espacios
    string generoNormalizado = eliminarEspacios(generoBuscado);
    transform(generoNormalizado.begin(), generoNormalizado.end(), generoNormalizado.begin(), ::tolower);

    // Buscar el género normalizado en el vector de géneros
    for (const string &genero : generos)
    {
        string generoComparar = eliminarEspacios(genero);
        transform(generoComparar.begin(), generoComparar.end(), generoComparar.begin(), ::tolower);
        if (generoComparar == generoNormalizado)
        {
            return true; // El género ha sido encontrado
        }
    }
    return false; // El género no ha sido encontrado
}
