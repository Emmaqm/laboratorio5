#include "PartidaIndividual.h"
#include "Usuario.h"

PartidaIndividual::PartidaIndividual(){}
       
PartidaIndividual::PartidaIndividual(int duracion, Usuario* usuario, DtFecha* fecha, bool continuaPartida):Partida(duracion, usuario, fecha){
    this->continuaPartida = continuaPartida; 
}

bool PartidaIndividual::getContinuaPartida() {
    return this->continuaPartida;
}

void PartidaIndividual::setContinuaPartida(bool continuaPartida) {
    this->continuaPartida = continuaPartida;
}
 
int PartidaIndividual::getDuracionTotal() {
    return this->getDuracion();
}

PartidaIndividual::~PartidaIndividual(){}

