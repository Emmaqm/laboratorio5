#include "Categoria.h"

Categoria::Categoria() {}

Categoria::Categoria(string genero, string plataforma, string descripcion){
    this->genero = genero;
    this->plataforma = plataforma;
    this->descripcion = descripcion;
}

string Categoria::getGenero() {
    return this->genero;
}

string Categoria::getPlataforma() {
    return this->plataforma;
}

string Categoria::getDescripcion() {
    return this->descripcion;
}

DtCategoria* Categoria::getDtCategoria() {
    DtCategoria* dtCategoria = new DtCategoria(this->genero, this->plataforma, this->descripcion);
    return dtCategoria;
}

void Categoria::setGenero(string genero) {
    this->genero = genero;
}

void Categoria::setPlataforma(string plataforma) {
    this->plataforma = plataforma;
}

void Categoria::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

Categoria::~Categoria(){}