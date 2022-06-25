#include "DtCategoria.h"
#include <stdexcept>

DtCategoria::DtCategoria() {}

DtCategoria::DtCategoria(string key) {
    string delimiter = "-";
    string genero = key.substr(0, key.find(delimiter));
    string plataforma = key.substr(key.find(delimiter) + 1, string::npos);
    
    if(genero.empty() || plataforma.empty()) {
        throw invalid_argument("Formato de categoria incorrecto");
    }

    this->genero = genero;
    this->plataforma = plataforma;
}

DtCategoria::DtCategoria(string genero, string plataforma, string descripcion){
    this->genero = genero;
    this->plataforma = plataforma;
    this->descripcion = descripcion;
}

string DtCategoria::getGenero(){
    return this->genero;
}

string DtCategoria::getPlataforma(){
    return this->plataforma;
}

string DtCategoria::getDescripcion(){
    return this->descripcion;
}

string DtCategoria::getKey(){
    return this->genero + "-" + this->plataforma;
}

DtCategoria::~DtCategoria(){}