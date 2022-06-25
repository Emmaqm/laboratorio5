#ifndef ICSUSCRIPCION
#define ICSUSCRIPCION

#include "Suscripcion.h"

using namespace std;

class ICSuscripcion{
    public:
        virtual list<string> listarSuscripcionesActivas() = 0;
        virtual list<string> listarSuscripcionesInactivas() = 0;
        virtual bool ingresarVideojuego(string nombreJuego) = 0;
        virtual void ingresarMetodoPago(TipoPago pago) = 0;
        virtual bool agregarSuscripcion() = 0;
        virtual bool existeSuscripcion() = 0;
        virtual bool eliminarSuscripcion(string nombreJuego) = 0;
};

#endif