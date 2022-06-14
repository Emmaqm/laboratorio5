#include "DtUsuario.h"

DtUsuario::DtUsuario() {}

DtUsuario::DtUsuario(string email, string password) {
    this->email = email;
    this->password = password;
}

string DtUsuario::getEmail() {
    return this->email;
}

string DtUsuario::getPassword() {
    return this->password;
}

DtUsuario::~DtUsuario(){}