#include "CSuscripcion.h" 
#include "ManejadorVideojuego.h" 
#include "Sesion.h" 

list<string> CSuscripcion::listarSuscripcionesActivas(){
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

list<string> CSuscripcion::listarSuscripcionesInactivas(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Sesion *sesion = Sesion::getInstancia();

    list<string> suscripciones;
    list<Videojuego*> juegos = manejadorJuego->getVideojuegos();
    list<Videojuego*>::iterator it = juegos.begin();
    while(it != juegos.end()) {
        map<string, Suscripcion*>::iterator iter = (*it)->getSuscripciones().find(sesion->getUsuario()->getEmail());
        if(iter == (*it)->getSuscripciones().end()){
            string suscripcion = (*it)->getNombre() + " ($" + to_string((*it)->getCosto()) + ")";
            suscripciones.push_back(suscripcion);
        }

        it++;
    }
  
    return suscripciones;
}

void CSuscripcion::ingresarMetodoPago(TipoPago tipo){
    this->tipo = tipo;
}

bool CSuscripcion::agregarSuscripcion(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Sesion *sesion = Sesion::getInstancia();

    Videojuego* videojuego = manejadorJuego->getVideojuego(nombreJuego);
    DtFecha *fecha = new DtFecha();

    Suscripcion* suscripcion = new Suscripcion(this->tipo, videojuego->getCosto(), fecha, sesion->getUsuario());
    return videojuego->agregarSuscripcion(suscripcion);
}

bool CSuscripcion::existeSuscripcion(){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Sesion *sesion = Sesion::getInstancia();

    Videojuego* videojuego = manejadorJuego->getVideojuego(this->nombreJuego);

    map<string, Suscripcion*>::iterator iter = videojuego->getSuscripciones().find(sesion->getUsuario()->getEmail());
    if(iter != videojuego->getSuscripciones().end()){
        return true;
    }
    return false;
}

bool CSuscripcion::ingresarVideojuego(string nombre){
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = manejadorJuego->getVideojuego(nombre);
    if(videojuego != NULL) {
        this->nombreJuego = nombre;
        return true;
    }
    return false;
}


