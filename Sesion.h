#ifndef SESION
#define SESION
#include "Usuario.h"


using namespace std;

class Sesion{
    private: 
        Usuario* usuario = NULL;
        static Sesion* instancia;
        Sesion();
    public:
        void setUsuario(Usuario* usuario);
        Usuario* getUsuario();
        static Sesion* getInstancia();
        ~Sesion();
};


#endif