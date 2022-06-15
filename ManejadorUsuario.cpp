#include "ManejadorUsuario.h"

ManejadorUsuario::ManejadorUsuario(){}

ManejadorUsuario* ManejadorUsuario::instancia = NULL;

ManejadorUsuario* ManejadorUsuario::getInstancia(){
    if(instancia == NULL) {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}

Usuario* ManejadorUsuario::getUsuario(string email){
    Usuario* usu = NULL; 
    map<string, Usuario*>::iterator iter = this->colUsuarios.find(email);
    if(iter != colUsuarios.end()){
        usu = iter->second;
    }
    return usu;
}

void ManejadorUsuario::removerUsuario(Usuario* usuario){
    map<string, Usuario*>::iterator iter = this->colUsuarios.find(usuario->getEmail());
    this->colUsuarios.erase(iter);
}

bool ManejadorUsuario::existeUsuario(string email){
    map<string,Usuario*>::iterator iter = this->colUsuarios.find(email);
    return (iter != this->colUsuarios.end());
}

bool ManejadorUsuario::agregarUsuario(Usuario* usuario){
    pair<map<string, Usuario*>::iterator, bool> iter;
    iter = this->colUsuarios.insert(pair<string, Usuario*> (usuario->getEmail(), usuario));
    return iter.second;
}

ManejadorUsuario::~ManejadorUsuario(){}

