#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO
#include "Usuario.h"
#include <map>
#include <list>


class ManejadorUsuario{
    private:
        static ManejadorUsuario* instancia;
        ManejadorUsuario();
        map <string, Usuario*> colUsuarios;
    public:
        static ManejadorUsuario* getInstancia();
        list<Usuario*> getUsuarios();
        Usuario* getUsuario(string email);
        bool agregarUsuario(Usuario*);
        bool existeUsuario(string email);
        void removerUsuario(Usuario*);
        ~ManejadorUsuario();
};  


#endif