#include "CIniciarPartida.h" 
#include "ManejadorVideojuego.h" 
#include "Sesion.h" 

list<string> CIniciarPartida::listarSuscripcionesActivas(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Sesion *sesion = Sesion::getInstancia();
    
    list<string> suscripcionesActivas;
    list<Videojuego*> juegos = manejadorJuego->getVideojuegos();
    list<Videojuego*>::iterator it = juegos.begin();
    while(it != juegos.end()) {
        map<string, Suscripcion*>::iterator iter = (*it)->getSuscripciones().find(sesion->getUsuario()->getEmail());
        if(iter != (*it)->getSuscripciones().end()){
            string suscripcion = (*it)->getNombre() + " ($" + to_string((*it)->getCosto()) + ")";
            suscripcionesActivas.push_back(suscripcion);
        }
        it++;
    }
  
    return suscripcionesActivas;
}