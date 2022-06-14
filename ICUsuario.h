#ifndef ICUSUARIO
#define ICUSUARIO

#include "DtUsuario.h"
#include <string>

using namespace std;

class ICUsuario {
    public:
        virtual void datosComunes(DtUsuario* dtUsuario) = 0;
        virtual void datosEmpresa(string empresa) = 0;
        virtual void datosJugador(string nickname, string descripcion) = 0;
        virtual void ingresarNickname(string nickname) = 0;
        virtual void altaUsuario() = 0;
        virtual void cancelar() = 0;
};

#endif