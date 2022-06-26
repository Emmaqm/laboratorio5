#ifndef ICINFOVIDEOJUEGO
#define ICINFOVIDEOJUEGO

#include <list>
#include <string>

using namespace std;

class ICInfovideojuego {
  public:
    virtual list<string> listarVideojuegos() = 0;
    virtual void selectVideojuego(string nombre) = 0;
    virtual DtVideojuegoFull* verInformacionVideojuegos() = 0;
};

#endif