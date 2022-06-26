#ifndef ICSESION
#define ICSESION

#include <list>
#include <string>
#include "Jugador.h"
#include "Desarrollador.h"

using namespace std;

class ICSesion {
    public:
        virtual void ingresarEmail(string email) = 0;
        virtual void ingresarPassword(string pass) = 0;
        virtual bool iniciarSesion() = 0;
        virtual bool cerrarSesion() = 0;
        virtual void datosUsuario(string &nombre, string &tipo) = 0;
        virtual bool esDesarrollador() = 0;
        virtual bool esJugador() = 0;
        virtual Desarrollador* getDesarrollador() = 0;
};


#endif