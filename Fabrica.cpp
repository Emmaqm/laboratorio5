#include "Fabrica.h"

#include "CUsuario.h"
#include "CSesion.h"
#include "CCategoria.h"
#include "CVideojuego.h"
#include "CEliminarVideojuego.h"
#include "CSuscripcion.h"

Fabrica* Fabrica::instancia = NULL;

Fabrica::Fabrica(){}

Fabrica* Fabrica::getInstancia(){
  if (instancia == NULL) {
    instancia = new Fabrica();
  }
  return instancia;
}

ICUsuario* Fabrica::getICUsuario() {
  return new CUsuario();
}

ICSesion* Fabrica::getICSesion() {
  return new CSesion();
}

ICCategoria* Fabrica::getICCategoria() {
  return new CCategoria();
}

ICVideojuego* Fabrica::getICVideojuego() {
  return new CVideojuego();
}

ICEliminarVideojuego* Fabrica::getICEliminarVideojuego(){
  return new CEliminarVideojuego(); 
}

ICSuscripcion* Fabrica::getICSuscripcion(){
  return new CSuscripcion(); 
}

Fabrica::~Fabrica(){}