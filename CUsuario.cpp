#include "CUsuario.h"

void CUsuario::datosComunes(DtUsuario *dtUsuario) {
    this->dtUsuario = dtUsuario;
}

void CUsuario::datosEmpresa(string empresa) {
    this->empresa = empresa;
    this->tipoUsuario = DESARROLLADOR;
}

void CUsuario::datosJugador(string nickname, string descripcion) {
    this->nickname = nickname;
    this->descripcion = descripcion;
    this->tipoUsuario = JUGADOR;
}

void CUsuario::ingresarNickname(string nickname) {
    this->nickname = nickname;
}

bool CUsuario::altaUsuario() {
    bool usu = false;
    if(this->tipoUsuario == JUGADOR) {
        Jugador* jugador = new Jugador(this->dtUsuario->getEmail(), this->dtUsuario->getPassword(), nickname, descripcion);
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        usu = mu->agregarUsuario(jugador);
    } else if (this->tipoUsuario == DESARROLLADOR) {
        Desarrollador* desarrollador = new Desarrollador(this->dtUsuario->getEmail(), this->dtUsuario->getPassword(), empresa);
        ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
        usu = mu->agregarUsuario(desarrollador);
    }
    return usu;
}

void cancelar();