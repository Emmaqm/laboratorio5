#include "Jugador.h"

Jugador::Jugador(){}

Jugador::Jugador(string email, string password, string nickname, string descripcion):Usuario(email, password){
    this->nickname = nickname;
    this->descripcion = descripcion;
}

string Jugador::getNickname(){
    return this->nickname;
}

void Jugador::setNickname(string nickname){
    this->nickname = nickname;
}

string Jugador::getDescripcion(){
    return this->descripcion;
}

void Jugador::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}

Jugador::~Jugador(){}