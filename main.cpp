#include "Fabrica.h"
#include "ICUsuario.h"

#include <stdlib.h>
#include <stdio.h>

using namespace std;

Fabrica *fabrica;

int main() {
    fabrica = Fabrica::getInstancia();
    fabrica->getICUsuario();
}