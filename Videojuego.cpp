#include "Videojuego.h"

Videojuego::Videojuego() {}

Videojuego::Videojuego(string nombre, string descripcion, int costo, DtCategoria categoria){
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
    this->categoria = categoria;
}

string Videojuego::getNombre() {
    return this->nombre;
}

string Videojuego::getDescripcion() {
    return this->descripcion;
}

int Videojuego::getCosto() {
    return this->costo;
}

DtCategoria Videojuego::getCategoria() {
    return this->categoria;
}

void Videojuego::setNombre(string nombre) {
    this->nombre = nombre;
}

void Videojuego::setDescripcion(string descripcion) {
    this->descripcion = descripcion;
}

void Videojuego::setCosto(int costo) {
    this->costo = costo;
}

void Videojuego::setCategoria(DtCategoria categoria) {
    this->categoria = categoria;
}

Videojuego::~Videojuego(){}