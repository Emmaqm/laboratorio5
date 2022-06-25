#ifndef ICSUSCRIPCION
#define ICSUSCRIPCION

#include "Suscripcion.h"

class ICSuscripcion{
    public:
        virtual list<string> listarSuscripcionesActivas() = 0;
        virtual list<string> listarSuscripcionesInactivas() = 0;
        virtual bool agregarSuscripcion() = 0;
        virtual bool existeSuscripcion() = 0;
};

#endif