#include "CCategoria.h"

void CCategoria::ingresarDatos(string genero, string plataforma, string descripcion){
    this->genero = genero;
    this->plataforma = plataforma;
    this->descripcion = descripcion;
}

bool CCategoria::agregarCategoria() {
    Categoria* categoria = new Categoria(this->genero, this->plataforma, this->descripcion);
    ManejadorCategoria* manejadorCategoria = ManejadorCategoria::getInstancia();
    return manejadorCategoria->agregarCategoria(categoria);
}

list<string> CCategoria::listarCategorias() {
    ManejadorCategoria* manejador = ManejadorCategoria::getInstancia();
    list<Categoria*> categorias = manejador->getCategorias();    
    list<string> aux;
    list<Categoria*>::iterator it = categorias.begin();
    while(it != categorias.end()){
        string key = (*it)->getGenero() + '-' + (*it)->getPlataforma();
        aux.push_back(key);
        it++;
    }
    return aux;
}