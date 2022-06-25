#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Categoria.h"
#include "Suscripcion.h"

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
    public:
        Videojuego();
        Videojuego(string nombre, string descripcion, int costo, map<string, Categoria*> categorias);
        string getNombre();
        string getDescripcion();
        int getCosto();
        map<string, Categoria*> getCategorias();
        map<string, Suscripcion*> getSuscripciones();
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        void setCategorias(map<string, Categoria*> categorias);
        bool agregarSuscripcion(Suscripcion* suscripcion);
        ~Videojuego();
};

#endif