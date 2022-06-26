#include "CIniciarPartida.h" 
#include "ManejadorVideojuego.h" 
#include "Sesion.h"
#include "PartidaMultijugador.h"
#include "PartidaIndividual.h"


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

void CIniciarPartida::seleccionarVideojuego(string nombre) {
    this->nombre = nombre;
}

void CIniciarPartida::datosPartidaIndividual(bool continuaPartida, int duracion) {
    this->continuaPartida = continuaPartida;
    this->duracion = duracion;
    this->tipoPartida = INDIVIDUAL;
}

void CIniciarPartida::datosPartidaMultijugador(bool enVivo, int cantJugadores, int duracion) {
    this->enVivo = enVivo;
    this->cantJugadores = cantJugadores;
    this->duracion = duracion;
    this->tipoPartida = MULTIJUGADOR;
}

bool CIniciarPartida::iniciarPartida() {
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = manejadorJuego->getVideojuego(this->nombre);
    Sesion *sesion = Sesion::getInstancia();

    if(videojuego == NULL) {
        return false;
    }

    DtFecha* fecha = new DtFecha();

    if(this->tipoPartida == INDIVIDUAL) {
        PartidaIndividual* partida = new PartidaIndividual(this->duracion, sesion->getUsuario(), fecha, this->continuaPartida);
        return videojuego->agregarPartida(partida);

    } else if (this->tipoPartida == MULTIJUGADOR) {
        PartidaMultijugador* partida = new PartidaMultijugador(this->duracion, sesion->getUsuario(), fecha, this->enVivo, this->cantJugadores);
        return videojuego->agregarPartida(partida);
    }

    return false;
}