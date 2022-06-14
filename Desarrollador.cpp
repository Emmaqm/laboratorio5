#include "Desarrollador.h"

Desarrollador::Desarrollador(){}

Desarrollador::Desarrollador(string email, string password, string empresa):Usuario(email, password){
    this->empresa = empresa;
}

string Desarrollador::getEmpresa(){
    return this->empresa;
}

void Desarrollador::setEmpresa(string empresa){
    this->empresa = empresa;
}

Desarrollador::~Desarrollador(){}