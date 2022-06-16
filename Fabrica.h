#ifndef FABRICA
#define FABRICA

#include "ICUsuario.h"
#include "ICSesion.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        ICUsuario* getICUsuario();
        ICSesion* getICSesion();
        ~Fabrica();
};

#endif