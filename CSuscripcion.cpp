#include "CSuscripcion.h" 
#include "ManejadorVideojuego.h" 
#include "Fabrica.h" 

list<string> CSuscripcion::listarSuscripcionesActivas(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Fabrica* fabrica = Fabrica::getInstancia();

    ICSesion* controladorSesion = fabrica->getICSesion();
    Jugador* jugador = controladorSesion->getJugador();
    if(jugador == NULL) {
        throw invalid_argument("El usuario logueado no es un jugador");
    }

    list<string> suscripcionesActivas;
    list<Videojuego*> juegos = manejadorJuego->getVideojuegos();
    list<Videojuego*>::iterator it = juegos.begin();
    while(it != juegos.end()) {
        map<string, Suscripcion*>::iterator iter = (*it)->getSuscripciones().find(jugador->getNickname());
        if(iter != (*it)->getSuscripciones().end()){
            string suscripcion = (*it)->getNombre() + " ($" + to_string((*it)->getCosto()) + ")";
            suscripcionesActivas.push_back(suscripcion);
        }

        it++;
    }
  
    return suscripcionesActivas;
}

list<string> CSuscripcion::listarSuscripcionesInactivas(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Fabrica* fabrica = Fabrica::getInstancia();

    ICSesion* controladorSesion = fabrica->getICSesion();
    Jugador* jugador = controladorSesion->getJugador();
    if(jugador == NULL) {
        throw invalid_argument("El usuario logueado no es un jugador");
    }

    list<string> suscripciones;
    list<Videojuego*> juegos = manejadorJuego->getVideojuegos();
    list<Videojuego*>::iterator it = juegos.begin();
    while(it != juegos.end()) {
        map<string, Suscripcion*>::iterator iter = (*it)->getSuscripciones().find(jugador->getNickname());
        if(iter == (*it)->getSuscripciones().end()){
            string suscripcion = (*it)->getNombre() + " ($" + to_string((*it)->getCosto()) + ")";
            suscripciones.push_back(suscripcion);
        }

        it++;
    }
  
    return suscripciones;
}

bool CSuscripcion::agregarSuscripcion(){
    return true;
}

bool CSuscripcion::existeSuscripcion(){
    return true;
}
