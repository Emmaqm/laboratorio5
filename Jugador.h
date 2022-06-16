#ifndef JUGADORH
#define JUGADORH

#include "Usuario.h"

using namespace std;

class Jugador:public Usuario {
    private:
        string nickname;
        string descripcion;
    public:
        Jugador();
        Jugador(string email, string password, string nickname, string descripcion);
        string getNickname();
        void setNickname(string nickname);
        string getDescripcion();
        void setDescripcion(string descripcion);
        ~Jugador();
};

#endif