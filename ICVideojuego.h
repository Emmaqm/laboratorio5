#ifndef ICVIDEOJUEGO
#define ICVIDEOJUEGO

#include "DtCategoria.h"

#include <string>

using namespace std;

class ICVideojuego{
    public:
        virtual void ingresarDatos(string nombre, string descripcion, int costo) = 0;
        virtual void ingresarCategoria(DtCategoria* dtCategoria) = 0;
        virtual void agregarJuego() = 0;
        virtual void seedJuego() = 0;
};

#endif