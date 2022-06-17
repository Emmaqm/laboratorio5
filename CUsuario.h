#ifndef CUSUARIO
#define CUSUARIO

#include "ICUsuario.h"
#include "TipoUsuario.h"
#include "Desarrollador.h"
#include "Jugador.h"
#include "ManejadorUsuario.h"

using namespace std;

class CUsuario:public ICUsuario {
    private:
        DtUsuario* dtUsuario;
        string empresa;
        string nickname;
        string descripcion;
        TipoUsuario tipoUsuario;
    public:
        void datosComunes(DtUsuario* dtUsuario);
        void datosEmpresa(string empresa);
        void datosJugador(string nickname, string descripcion);
        void ingresarNickname(string nickname);
        bool altaUsuario();
        void cancelar();
};

#endif