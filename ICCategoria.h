#ifndef ICCATEGORIA
#define ICCATEGORIA

#include <string>
#include <list>

#include "DtCategoria.h"

using namespace std;

class ICCategoria{
    public:
        virtual void ingresarDatos(string genero, string plataforma, string descripcion) = 0;
        virtual bool agregarCategoria() = 0;
        virtual bool seedCategoria() = 0;
        virtual list<DtCategoria*> listarCategorias() = 0;
};


#endif