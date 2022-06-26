#include "DtVideojuegoFull.h"

DtVideojuegoFull::DtVideojuegoFull() {}

DtVideojuegoFull::DtVideojuegoFull(string nombre, string descripcion, int costo, list<DtCategoria*> categorias, string empresa) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->categorias = categorias;
    this->empresa = empresa;
}

string DtVideojuegoFull::getNombre() {
    return this->nombre;
}

string DtVideojuegoFull::getDescripcion() {
    return this->descripcion;
}

int DtVideojuegoFull::getCosto() {
    return this->costo;
}

list<DtCategoria*> DtVideojuegoFull::getCategorias() {
    return this->categorias;
}
string DtVideojuegoFull::getEmpresa() {
    return this->empresa;
}

DtVideojuegoFull::~DtVideojuegoFull(){}