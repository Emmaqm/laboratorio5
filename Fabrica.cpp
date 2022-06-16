#include "Fabrica.h"

#include "CUsuario.h"
#include "CSesion.h"

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

Fabrica::~Fabrica(){}