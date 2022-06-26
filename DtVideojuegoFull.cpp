#include "DtVideojuegoFull.h"

DtVideojuegoFull::DtVideojuegoFull() {}

DtVideojuegoFull::DtVideojuegoFull(string nombre, string descripcion, int costo, list<DtCategoria*> categorias, string empresa, int duracionTotal) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->categorias = categorias;
    this->empresa = empresa;
    this->duracionTotal = duracionTotal;
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

int DtVideojuegoFull::getDuracionTotal() {
    return this->duracionTotal;
}

DtVideojuegoFull::~DtVideojuegoFull(){}