#include "CEliminarVideojuego.h"
#include "Fabrica.h"
#include "CSuscripcion.h"

list<string> CEliminarVideojuego::listarVideojuegos(){
    list <string> tempList;
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();

    Fabrica* fabrica = Fabrica::getInstancia();
    ICSesion* controladorSesion = fabrica->getICSesion();
    Desarrollador* desarrollador = controladorSesion->getDesarrollador();

    list<Videojuego*> lv  = ma->getVideojuegos();
    for(list<Videojuego*>::iterator it = lv.begin(); it != lv.end(); ++it){
        if((*it)->getDesarrollador()->getEmail() == desarrollador->getEmail()) {
            tempList.push_back((*it)->getNombre());
        }
    }
    return tempList;
}

void CEliminarVideojuego::selectVideojuego(string nombre) {
    this->nombre = nombre;
}

void CEliminarVideojuego::eliminarVideojuego() {
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = ma->getVideojuego(this->nombre);
    ma->removerVideojuego(videojuego);

    
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();
    map<string, Suscripcion*> ::iterator it = videojuego->getSuscripciones(); 
    //    map<string, Categoria*>::iterator it = this->colCategorias.find(key);

    //falta eliminar partida
}