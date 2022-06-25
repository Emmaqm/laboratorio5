#include "CSesion.h"

void CSesion::ingresarEmail(string email)
{
    this->email = email;
}

void CSesion::ingresarPassword(string password)
{
    this->password = password;
}

bool CSesion::iniciarSesion()
{
    Sesion *sesion = Sesion::getInstancia();
    ManejadorUsuario *manejadorUsuario = ManejadorUsuario::getInstancia();

    if (manejadorUsuario->existeUsuario(this->email))
    {
        Usuario *usuario = manejadorUsuario->getUsuario(this->email);
        if (usuario->getPassword() == this->password)
        {
            sesion->setUsuario(usuario);
            return true;
        }
    }

    return false;
}

bool CSesion::cerrarSesion()
{
    Sesion *sesion = Sesion::getInstancia();
    if (sesion->getUsuario() != NULL)
    {
        sesion->setUsuario(NULL);
        return true;
    }
    return false;
}

void CSesion::datosUsuario(string &email, string &tipo)
{
    email = "";
    tipo = "";
    Usuario *usuario;
    Sesion *sesion = Sesion::getInstancia();
    if (sesion->getUsuario() != NULL)
    {
        email = sesion->getUsuario()->getEmail();
        usuario = sesion->getUsuario();

        if (Desarrollador *desarrollador = dynamic_cast<Desarrollador *>(usuario))
        {
            tipo = "Desarrollador";
        }
        else
        {
            tipo = "Jugador";
        }
    }
}


bool CSesion::esDesarrollador(){
    bool aux=false;
    Sesion* sesionActual = Sesion::getInstancia();
    if(sesionActual->getUsuario()!=NULL){
        if(Desarrollador* developer = dynamic_cast<Desarrollador*>(sesionActual->getUsuario())){
            aux=true;
        }

    }
    return aux;
}

bool CSesion::esJugador(){
    bool aux=false;
    Sesion* sesionActual = Sesion::getInstancia();
    if(sesionActual->getUsuario()!=NULL){
        if(Jugador* jugador = dynamic_cast<Jugador*>(sesionActual->getUsuario())){
            aux=true;
        }

    }
    return aux;
}


Jugador* CSesion::getJugador(){
    Sesion* sesionActual = Sesion::getInstancia();
    if(sesionActual->getUsuario() != NULL){
        Jugador* jugador = dynamic_cast<Jugador*>(sesionActual->getUsuario());
        if(jugador != NULL){
            return jugador;
        }
    }
    return NULL;
}


