#include "ManejadorVideojuego.h"

ManejadorVideojuego::ManejadorVideojuego(){}

ManejadorVideojuego* ManejadorVideojuego::instancia = NULL;

ManejadorVideojuego* ManejadorVideojuego::getInstancia(){
    if (instancia == NULL){
        instancia = new ManejadorVideojuego();
    }
    return instancia;
}

list<Videojuego*> ManejadorVideojuego::getVideojuegos(){
    list<Videojuego*> juegos;
    for(map<string, Videojuego*>::iterator it = this->colVideojuegos.begin(); it != this->colVideojuegos.end(); it++)
        juegos.push_back(it->second);
    return juegos;
}

Videojuego* ManejadorVideojuego::getVideojuego(string nombre){
    Videojuego* videojuego = NULL;
    map<string, Videojuego*>::iterator iter = this->colVideojuegos.find(nombre);
    if(iter != colVideojuegos.end()){
        videojuego = iter->second;
    }
    return videojuego;
}

bool ManejadorVideojuego::agregarVideojuego(Videojuego* videojuego){
    pair<map<string, Videojuego*>::iterator, bool> iter;
    iter = this->colVideojuegos.insert(pair<string, Videojuego*> (videojuego->getNombre(), videojuego));
    return iter.second;
}

void ManejadorVideojuego::removerVideojuego(Videojuego* videojuego){
    map<string, Videojuego*>::iterator iter = this->colVideojuegos.find(videojuego->getNombre());
    this->colVideojuegos.erase(iter);
}