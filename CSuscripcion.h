#ifndef CSUSCRIPCION
#define CSUSCRIPCION

#include <list>
#include <map>

#include "ICSuscripcion.h"

class CSuscripcion:public ICSuscripcion{
    private:

    public:
        list<string> listarSuscripcionesActivas();
        list<string> listarSuscripcionesInactivas();
        bool agregarSuscripcion();
        bool existeSuscripcion();
};

#endif