#ifndef SUSCRIPCION
#define SUSCRIPCION
#include "TipoPago.h"
#include "DtFecha.h"
#include "Usuario.h"


class Suscripcion{
    private:
        TipoPago tipoPago;
        int costo;
        DtFecha fecha;
        Usuario* usuario;
    public:
        Suscripcion();
        Suscripcion(TipoPago tipoPago, int costo, DtFecha fecha, Usuario* usuario);
        TipoPago getTipoPago();
        int getCosto();
        DtFecha getFecha();
        Usuario* getUsuario();
        void setTipoPago(TipoPago);
        void setCosto(int);
        void setFecha(DtFecha);
        void setUsuario(Usuario*);
        ~Suscripcion();
};

#endif