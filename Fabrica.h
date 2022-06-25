#ifndef FABRICA
#define FABRICA

#include "ICUsuario.h"
#include "ICSesion.h"
#include "ICCategoria.h"
#include "ICVideojuego.h"
#include "ICEliminarVideojuego.h"
#include "ICSuscripcion.h"

class Fabrica{
    private:
        static Fabrica* instancia;
        Fabrica();
    public:
        static Fabrica* getInstancia();
        ICUsuario* getICUsuario();
        ICSesion* getICSesion();
        ICCategoria* getICCategoria();
        ICVideojuego* getICVideojuego();
        ICEliminarVideojuego* getICEliminarVideojuego();
        ICSuscripcion* getICSuscripcion();
        
        ~Fabrica();
};

#endif