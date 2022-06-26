#ifndef CINFOVIDEOJUEGO
#define CINFOVIDEOJUEGO


#include "ManejadorVideojuego.h"
#include "DtVideojuegoFull.h"
#include "ICInfoVideojuego.h"

#include <list>
#include <string>

using namespace std;

class CInfoVideojuego:public ICInfoVideojuego {
  private:
    string nombre;
  public:
    list<string> listarVideojuegos();
    void selectVideojuego(string nombre);
    DtVideojuegoFull* verInformacionVideojuegos();
};

#endif