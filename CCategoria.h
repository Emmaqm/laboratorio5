#ifndef CCATEGORIA
#define CCATEGORIA

#include "ICCategoria.h"
#include "ManejadorCategoria.h"
#include <list>
#include <string>

using namespace std;

class CCategoria:public ICCategoria {
    private:
        string genero;
        string plataforma;
        string descripcion;
    public:
        void ingresarDatos(string genero, string plataforma, string descripcion);
        bool agregarCategoria();
        bool seedCategoria();
        list<DtCategoria*> listarCategorias();
};

#endif