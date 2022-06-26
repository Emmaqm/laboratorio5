#ifndef CSUSCRIPCION
#define CSUSCRIPCION

#include <string>
#include <list>
#include <map>

#include "ICSuscripcion.h"

using namespace std;

class CSuscripcion:public ICSuscripcion{
    private:
        string nombreJuego;
        TipoPago tipo;
    public:
        list<string> listarSuscripcionesActivas();
        list<string> listarSuscripcionesInactivas();
        bool ingresarVideojuego(string nombreJuego);
        void ingresarMetodoPago(TipoPago pago);
        bool existeSuscripcion();
        bool agregarSuscripcion();
};

#endif