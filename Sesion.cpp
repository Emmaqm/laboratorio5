#include "Sesion.h"

Sesion* Sesion::instancia = NULL;

Sesion::Sesion(){}

void Sesion::setUsuario(Usuario* usuario){
    this->usuario = usuario;
}

Usuario* Sesion::getUsuario(){
    return this->usuario;
}

Sesion* Sesion::getInstancia(){
    if(instancia == NULL){
        instancia = new Sesion();
    }
    return instancia;
}

Sesion::~Sesion(){}