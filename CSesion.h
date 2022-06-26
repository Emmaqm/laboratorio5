#ifndef CSESION
#define CSESION
#include "Sesion.h" 
#include "ICSesion.h" 
#include "ManejadorUsuario.h"
#include <list>
#include <string>

using namespace std; 

class CSesion:public ICSesion{
    private:
        string email;
        string password;
    public:
        void ingresarEmail(string email);
        void ingresarPassword(string password);
        bool iniciarSesion();
        bool cerrarSesion();
        void datosUsuario(string &nombre, string &tipo);
        bool esDesarrollador();
        bool esJugador();
        Desarrollador* getDesarrollador();
};

#endif