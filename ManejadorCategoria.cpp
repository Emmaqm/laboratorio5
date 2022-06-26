#include "ManejadorCategoria.h"

ManejadorCategoria::ManejadorCategoria(){}

ManejadorCategoria* ManejadorCategoria::instancia = NULL;

ManejadorCategoria*  ManejadorCategoria::getInstancia(){
    if(instancia == NULL) {
        instancia = new ManejadorCategoria();
    }
    return instancia;
}

list<Categoria*> ManejadorCategoria::getCategorias(){
    list<Categoria*> categorias;
    for(map<string, Categoria*>::iterator it = this->colCategorias.begin(); it != this->colCategorias.end(); it++) {
        categorias.push_back(it->second);
    }
    return categorias;
}
 
bool ManejadorCategoria::agregarCategoria(Categoria* categoria){
    pair<map<string, Categoria*>::iterator,bool> it;
    string key = categoria->getGenero() + '-' + categoria->getPlataforma();
    it = this->colCategorias.insert(pair<string, Categoria*> (key, categoria));
    return it.second;
}

Categoria* ManejadorCategoria::getCategoria(string genero, string plataforma){
    Categoria* aux = NULL;
    string key = genero + '-' + plataforma;
    map<string,Categoria*>::iterator it = this->colCategorias.find(key);
    if(it != colCategorias.end()){
        aux = it->second;
    }
    return aux;
}

bool ManejadorCategoria::existeCategoria(string genero, string plataforma){
    string key = genero + '-' + plataforma;
    map<string,Categoria*>::iterator it = this->colCategorias.find(key);    
    return  (it != this->colCategorias.end());
}

void ManejadorCategoria::eliminarCategoria(Categoria* categoria){
    string key = categoria->getGenero() + '-' + categoria->getPlataforma();
    map<string, Categoria*>::iterator it = this->colCategorias.find(key);
    this->colCategorias.erase(it);
}