#ifndef DESARROLLADORH
#define DESARROLLADORH

#include "Usuario.h"

using namespace std;

class Desarrollador:public Usuario {
    private:
        string empresa;
    public:
        Desarrollador();
        Desarrollador(string email, string password, string empresa);
        string getEmpresa();
        void setEmpresa(string empresa);
        ~Desarrollador();
};

#endif