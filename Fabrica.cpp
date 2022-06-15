#include "Fabrica.h"
#include "CUsuario.h"

Fabrica::Fabrica(){}

Fabrica* Fabrica::instancia = NULL;

Fabrica* Fabrica::getInstancia(){
  if (instancia == NULL) {
    instancia = new Fabrica();
  }
  return instancia;
}

ICUsuario* Fabrica::getICUsuario() {
  return new CUsuario();
}

Fabrica::~Fabrica(){}