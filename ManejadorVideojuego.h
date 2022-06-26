#ifndef MANEJADORVIDEOJUEGO
#define MANEJADORVIDEOJUEGO

#include "Videojuego.h"

#include <map>
#include <list>

using namespace std;

class ManejadorVideojuego{
    private:
        static ManejadorVideojuego* instancia;
        ManejadorVideojuego();
        map<string, Videojuego*> colVideojuegos;
    public:
        static ManejadorVideojuego* getInstancia();
        list<Videojuego*> getVideojuegos();
        Videojuego* getVideojuego(string nombre);
        bool existeVideojuego(string nombre);
        bool agregarVideojuego(Videojuego* videojuego);
        void removerVideojuego(Videojuego* videojuego);
};

#endif