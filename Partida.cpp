#include "Partida.h"

Partida::Partida(){}
       
Partida::Partida(int duracion, Usuario* usuario, DtFecha* fecha){
    this->duracion = duracion; 
    this->usuario = usuario;
    this->fecha = fecha;
}

int Partida::getDuracion() {
    return this->duracion;
} 

DtFecha* Partida::getFecha() {
    return this->fecha;
} 

void Partida::setDuracion(int duracion) {
    this->duracion = duracion;
}

Usuario* Partida::getUsuario() {
    return this->usuario;
} 

void Partida::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

void Partida::setFecha(DtFecha* fecha) {
    this->fecha = fecha;
}
 
Partida::~Partida(){}

