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
        int duracionTotal;
    public:
        DtVideojuegoFull();
        DtVideojuegoFull(string nombre, string descripcion, int costo, list<DtCategoria*> categorias, string empresa, int duracionTotal);
        string getNombre();
        string getDescripcion();
        int getCosto();
        list<DtCategoria*> getCategorias();
        string getEmpresa();
        int getDuracionTotal();
        ~DtVideojuegoFull();
};

#endif