#include "PartidaMultijugador.h"
#include "Usuario.h"



PartidaMultijugador::PartidaMultijugador(){}
PartidaMultijugador::PartidaMultijugador(int duracion, Usuario* usuario, DtFecha* fecha, bool enVivo, int cantJugadores):Partida(duracion, usuario, fecha){
    this->enVivo = enVivo;
    this->cantJugadores = cantJugadores;
}

bool PartidaMultijugador::getEnVivo() {
    return this->enVivo;
}

int PartidaMultijugador::getCantJugadores(){
    return this->cantJugadores;    
}

void PartidaMultijugador::setEnVivo(bool enVivo){
    this->enVivo = enVivo; 
}
    
void PartidaMultijugador::setCantJugadores(int cantJugadores){
    this->cantJugadores = cantJugadores;
}

int PartidaMultijugador::getDuracionTotal() {
    return this->cantJugadores * this->getDuracion();
}


PartidaMultijugador::~PartidaMultijugador(){}