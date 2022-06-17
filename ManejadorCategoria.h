#ifndef MANEJADORCATEGORIA
#define MANEJADORCATEGORIA
#include "Categoria.h"
#include <map>
#include <list>

class ManejadorCategoria{
    private: 
        static ManejadorCategoria* instancia;
        ManejadorCategoria();
        map<string, Categoria*> colCategorias;
    public:
        static ManejadorCategoria* getInstancia();
        list<Categoria*> getCategorias();
        Categoria* getCategoria(string genero, string plataforma);
        bool agregarCategoria(Categoria* categoria);
        void eliminarCategoria(Categoria* categoria);
        bool existeCategoria(string genero, string plataforma);
        ~ManejadorCategoria();
};
#endif