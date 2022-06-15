#ifndef FABRICA
#define FABRICA

#include "ICUsuario.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        ICUsuario* getICUsuario();
        ~Fabrica();
};

#endif