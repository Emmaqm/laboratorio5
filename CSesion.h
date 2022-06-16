#ifndef CSESION
#define CSESION
#include "Sesion.h" 
#include "ICSesion.h" 
#include "Desarrollador.h" 
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
        void datosUsuario(string &nombre, string &tipo);
};

#endif