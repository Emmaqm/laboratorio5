#ifndef CVIDEOJUEGO
#define CVIDEOJUEGO

#include "ICVideojuego.h"

#include <string>
#include <list>

using namespace std;

class CVideojuego:public ICVideojuego{
    private:
        string nombre;
        string descripcion;
        int costo;
        list<DtCategoria*> categorias;
    public:
        void ingresarDatos(string nombre, string descripcion, int costo);
        void ingresarCategoria(DtCategoria* dtCategoria);
        void agregarJuego();
        void seedJuego();
};

#endif