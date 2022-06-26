#ifndef CINFOVIDEOJUEGO
#define CINFOVIDEOJUEGO


#include "ICInfoVideojuego.h"
#include "ManejadorVideojuego.h"

#include <list>
#include <string>

using namespace std;

class CInfoVideojuego:public ICInfovideojuego {
  private:
    string nombre;
  public:
    list<string> listarVideojuegos();
    void selectVideojuego(string nombre);
    DtVideojuegoFull* verInformacionVideojuegos();
};

#endif