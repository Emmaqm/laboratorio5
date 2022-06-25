#include "CCategoria.h"
#include "Fabrica.h"
#include "ICSesion.h"
#include <stdexcept>

void CCategoria::ingresarDatos(string genero, string plataforma, string descripcion){
    this->genero = genero;
    this->plataforma = plataforma;
    this->descripcion = descripcion;
}

bool CCategoria::agregarCategoria() {
    Fabrica* fabrica = Fabrica::getInstancia();
    ICSesion* controladorSesion = fabrica->getICSesion();
    string emailUsuario, tipoUsuario;
    controladorSesion->datosUsuario(emailUsuario, tipoUsuario);

    if (emailUsuario.empty()) {
        throw invalid_argument("Usuario no logueado");
    }

    if (tipoUsuario != "Desarrollador") {
        throw invalid_argument("Usuario no es desarrollador");
    }

    Categoria* categoria = new Categoria(this->genero, this->plataforma, this->descripcion);
    ManejadorCategoria* manejadorCategoria = ManejadorCategoria::getInstancia();
    return manejadorCategoria->agregarCategoria(categoria);
}

bool CCategoria::seedCategoria() {
    Fabrica* fabrica = Fabrica::getInstancia();
    Categoria* categoria = new Categoria(this->genero, this->plataforma, this->descripcion);
    ManejadorCategoria* manejadorCategoria = ManejadorCategoria::getInstancia();
    return manejadorCategoria->agregarCategoria(categoria);
}

list<DtCategoria*> CCategoria::listarCategorias() {
    ManejadorCategoria* manejador = ManejadorCategoria::getInstancia();
    list<Categoria*> categorias = manejador->getCategorias();    
    list<DtCategoria*> aux;
    list<Categoria*>::iterator it = categorias.begin();
    while(it != categorias.end()){
        DtCategoria* dtCategoria = (*it)->getDtCategoria();
        aux.push_back(dtCategoria);
        it++;
    }
    return aux;
}