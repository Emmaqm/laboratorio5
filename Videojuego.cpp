#include "Videojuego.h"
#include "DtVideojuegoFull.h"
Videojuego::Videojuego(){}

Videojuego::Videojuego(string nombre, string descripcion, int costo, map<string, Categoria*> categorias, Desarrollador* desarrollador){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->categorias = categorias;
    this->desarrollador = desarrollador;
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

Desarrollador* Videojuego::getDesarrollador() {
    return this->desarrollador;    
}

DtVideojuegoFull* Videojuego::getDtVideojuegoFull() {
    string empresa = this->desarrollador->getEmpresa(); 
    list<DtCategoria*> aux;

    map<string, Categoria*>::iterator it = this->categorias.begin();
    while(it != this->categorias.end()){
        DtCategoria* dtCategoria = (it->second)->getDtCategoria();
        aux.push_back(dtCategoria);
        it++;
    }

    int duracionTotal = 0;
    map<int, Partida*>::iterator itP = this->partidas.begin();
    while(itP != this->partidas.end()){  
        duracionTotal = duracionTotal + itP->second->getDuracionTotal();
        itP++;
    }

    DtVideojuegoFull* dtvideojuegofull = new DtVideojuegoFull(this->nombre, this->descripcion, this->costo, aux, empresa, duracionTotal);
    return dtvideojuegofull;
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

void Videojuego::setDesarrollador(Desarrollador* desarrollador) {
    this->desarrollador = desarrollador;
}

bool Videojuego::agregarSuscripcion(Suscripcion* suscripcion){
    pair<map<string, Suscripcion*>::iterator,bool> it;
    it = this->suscripciones.insert(pair<string, Suscripcion*> (suscripcion->getUsuario()->getEmail(), suscripcion));
    return it.second;
}

void Videojuego::eliminarSuscripciones(){
    for(map<string, Suscripcion*>::iterator it = this->suscripciones.begin(); it != this->suscripciones.end(); it++) {
        this->suscripciones.erase(it);
    }
}

void Videojuego::eliminarPartidas(){
    for(map<int, Partida*>::iterator it = this->partidas.begin(); it != this->partidas.end(); it++) {
        this->partidas.erase(it);
    }
}

bool Videojuego::agregarPartida(Partida* partida) {
    pair<map<int, Partida*>::iterator,bool> it;
    it = this->partidas.insert(pair<int, Partida*> (this->partidas.size(), partida));
    return it.second;
}

Videojuego::~Videojuego() {};