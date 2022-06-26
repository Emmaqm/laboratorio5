#ifndef ICINFOVIDEOJUEGO
#define ICINFOVIDEOJUEGO

#include "DtVideojuegoFull.h"
#include <list>
#include <string>

using namespace std;

class ICInfoVideojuego {
  public:
    virtual list<string> listarVideojuegos() = 0;
    virtual void selectVideojuego(string nombre) = 0;
    virtual DtVideojuegoFull* verInformacionVideojuegos() = 0;
};

#endif