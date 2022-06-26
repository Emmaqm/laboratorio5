#ifndef FABRICA
#define FABRICA

#include "ICUsuario.h"
#include "ICSesion.h"
#include "ICCategoria.h"
#include "ICVideojuego.h"
#include "ICEliminarVideojuego.h"
#include "ICSuscripcion.h"
#include "ICInfoVideojuego.h"
#include "ICIniciarPartida.h"

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
        ICInfoVideojuego* getICInfoVideojuego();
        ICIniciarPartida* getICIniciarPartida();
        ~Fabrica();
};

#endif