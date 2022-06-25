#include "Videojuego.h"

Videojuego::Videojuego(){}

Videojuego::Videojuego(string nombre, string descripcion, int costo, map<string, Categoria*> categorias){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->categorias = categorias;
}

string Videojuego::getNombre(){
    return this->nombre;
}

string Videojuego::getDescripcion(){
    return this->descripcion;
}

int Videojuego::getCosto(){
    return this->costo;
}

map<string, Categoria*> Videojuego::getCategorias(){
    return this->categorias;
}

map<string, Suscripcion*> Videojuego::getSuscripciones(){
    return this->suscripciones;
}

void Videojuego::setNombre(string nombre){
    this->nombre = nombre;
}

void Videojuego::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

void Videojuego::setCosto(int costo){
    this->costo = costo;
}

void Videojuego::setCategorias(map<string, Categoria*> categorias){
    this->categorias = categorias;
}

bool Videojuego::agregarSuscripcion(Suscripcion* suscripcion){
    pair<map<string, Suscripcion*>::iterator,bool> it;
    it = this->suscripciones.insert(pair<string, Suscripcion*> (suscripcion->getUsuario()->getEmail(), suscripcion));
    return it.second;
}

Videojuego::~Videojuego(){}



