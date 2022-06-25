#ifndef ICELIMINARVIDEOJUEGO
#define ICELIMINARVIDEOJUEGO

#include <list>
#include <string>

using namespace std;

class ICEliminarVideojuego {
  public:
    virtual list<string> listarVideojuegos() = 0;
    virtual void selectVideojuego(string nombre) = 0;
    virtual void eliminarVideojuego() = 0;
    //virtual void cancelar() = 0;
};

#endif