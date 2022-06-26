#include "Suscripcion.h"

Suscripcion::Suscripcion(){}

Suscripcion::Suscripcion(TipoPago tipoPago, int costo, DtFecha* fecha, Usuario* usuario){
    this->tipoPago = tipoPago;
    this->costo = costo;
    this->fecha = fecha;
    this->usuario = usuario;
}

TipoPago Suscripcion::getTipoPago(){
    return this->tipoPago;
}

int Suscripcion::getCosto(){
    return this->costo;
}

DtFecha* Suscripcion::getFecha(){
    return this->fecha;
}

Usuario* Suscripcion::getUsuario(){
    return this->usuario;
}

void Suscripcion::setTipoPago(TipoPago tipoPago) {
    this->tipoPago = tipoPago;
}

void Suscripcion::setCosto(int costo) {
    this->costo = costo;
}

void Suscripcion::setFecha(DtFecha* Fecha) {
    this->fecha = fecha;
}

void Suscripcion::setUsuario(Usuario* usuario) {
    this->usuario = usuario;
}

Suscripcion::~Suscripcion(){}