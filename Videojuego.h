#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Categoria.h"
#include "Suscripcion.h"
#include "Desarrollador.h"
#include "DtVideojuegoFull.h"

#include <string>
#include <list>
#include <map>

using namespace std;

class Videojuego{
    private:
        string nombre;
        string descripcion;
        int costo;
        map<string, Categoria*> categorias;
        map<string, Suscripcion*> suscripciones;
        Desarrollador* desarrollador;
    public:
        Videojuego();
        Videojuego(string nombre, string descripcion, int costo, map<string, Categoria*> categorias, Desarrollador* desarrollador);
        string getNombre();
        string getDescripcion();
        int getCosto();
        map<string, Categoria*> getCategorias();
        map<string, Suscripcion*> getSuscripciones();
        Desarrollador* getDesarrollador();
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setCategorias(map<string, Categoria*> categorias);
        void setDesarrollador(Desarrollador* desarrollador);
        bool agregarSuscripcion(Suscripcion* suscripcion);
        void eliminarSuscripciones();
        DtVideojuegoFull* getDtVideojuegoFull();

        ~Videojuego();
};

#endif