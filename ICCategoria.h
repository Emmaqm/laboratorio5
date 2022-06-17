#ifndef ICCATEGORIA
#define ICCATEGORIA

#include <string>
#include <list>

using namespace std;

class ICCategoria{
    public:
        virtual void ingresarDatos(string genero, string plataforma, string descripcion) = 0;
        virtual bool agregarCategoria() = 0;
        virtual list<string> listarCategorias() = 0;
};


#endif