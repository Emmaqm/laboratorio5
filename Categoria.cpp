#include "Categoria.h"

Categoria::Categoria() {}

Categoria::Categoria(string tipoGenero, string tipoPlataforma, string descripcion){
    this->tipoGenero;
    this->tipoPlataforma;
    this->descripcion;
}

string Categoria::getTipoGenero() {
    return this->tipoGenero;
}

string Categoria::getTipoPlataforma() {
    return this->tipoPlataforma;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}

void Categoria::setTipoGenero(string tipoGenero) {
    this->tipoGenero = tipoGenero;
}

void Categoria::setTipoPlataforma(string tipoPlataforma) {
    this->tipoPlataforma = tipoPlataforma;
}

void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

Categoria::~Categoria(){}