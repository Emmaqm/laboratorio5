#include "CUsuario.h"

void CUsuario::datosComunes(DtUsuario *dtUsuario) {
    this->dtUsuario = dtUsuario;
}

void CUsuario::datosEmpresa(string empresa) {
    this->empresa = empresa;
}

void CUsuario::datosJugador(string nickname, string descripcion) {
    this->nickname = nickname;
    this->descripcion = descripcion;
}

void CUsuario::ingresarNickname(string nickname) {
    this->nickname = nickname;
}

void CUsuario::altaUsuario() {
    
}

void cancelar();