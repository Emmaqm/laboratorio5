#ifndef DTVIDEOJUEGOFULL
#define DTVIDEOJUEGOFULL
#include <string>
#include <list>
#include "DtCategoria.h"

using namespace std;

class DtVideojuegoFull {
    private:
        string nombre;
        string descripcion;
        int costo;
        list<DtCategoria*> categorias;
        string empresa;
    public:
        DtVideojuegoFull();
        DtVideojuegoFull(string nombre, string descripcion, int costo, list<DtCategoria*> categorias, string empresa);
        string getNombre();
        string getDescripcion();
        int getCosto();
        list<DtCategoria*> getCategorias();
        string getEmpresa();
        ~DtVideojuegoFull();
};

#endif