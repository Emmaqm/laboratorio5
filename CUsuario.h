#ifndef CUSUARIO
#define CUSUARIO

#include "ICUsuario.h"
#include <string>

using namespace std;

class CUsuario:public ICUsuario {
    private:
        DtUsuario* dtUsuario;
        string empresa;
        string nickname;
        string descripcion;
    public:
        void datosComunes(DtUsuario* dtUsuario);
        void datosEmpresa(string empresa);
        void datosJugador(string nickname, string descripcion) ;
        void ingresarNickname(string nickname) ;
        void altaUsuario();
        void cancelar();
};

#endif