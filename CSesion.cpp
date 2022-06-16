#include "CSesion.h"

void CSesion::ingresarEmail(string email) {
    this->email = email;
}

void CSesion::ingresarPassword(string password) {
    this->password = password;
}

bool CSesion::iniciarSesion(){
    Sesion* sesion = Sesion::getInstancia();
    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();

    if(manejadorUsuario->existeUsuario(this->email)) {
        Usuario *usuario = manejadorUsuario->getUsuario(this->email);
        if(usuario->getPassword() == this->password) {
            sesion->setUsuario(usuario);
            return true;
        }
    }

    return false;
}

void CSesion::datosUsuario(string &email, string &tipo) {
    email = "";
    tipo = "";
    Usuario* usuario;
    Sesion* sesion = Sesion::getInstancia();
    if(sesion->getUsuario() != NULL){
        email = sesion->getUsuario()->getEmail();
        usuario = sesion->getUsuario();

        if(Desarrollador* desarrollador = dynamic_cast<Desarrollador*>(usuario)){
            tipo = "Desarrollador";
        } else {
            tipo = "Jugador";
        }
    }
} 


