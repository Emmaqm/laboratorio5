#ifndef PARTIDA
#define PARTIDA

#include "Usuario.h"
#include "DtFecha.h"

class Partida{
    private:
        int duracion; 
        Usuario* usuario;
        DtFecha* fecha;
    public:
        Partida();
        Partida(int duracion, Usuario* Usuario, DtFecha* fecha);
        void setDuracion(int duracion);
        void setUsuario(Usuario* usuario);
        void setFecha(DtFecha* fecha);
        int getDuracion();
        Usuario* getUsuario();
        DtFecha* getFecha();
        virtual int getDuracionTotal() = 0;
        ~Partida();
};

#endif