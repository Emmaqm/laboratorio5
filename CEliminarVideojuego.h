#ifndef CELIMINARVIDEOJUEGO
#define CELIMINARVIDEOJUEGO

#include "ICEliminarVideojuego.h"
#include "ManejadorVideojuego.h"

#include <list>
#include <string>

using namespace std;

class CEliminarVideojuego:public ICEliminarVideojuego {
  private:
    string nombre;
  public:
    list<string> listarVideojuegos();
    void selectVideojuego(string nombre);
    void eliminarVideojuego();
};

#endif