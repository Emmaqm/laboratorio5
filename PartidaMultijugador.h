#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR
#include "Partida.h"

class PartidaMultijugador : public Partida{
    private:
        bool enVivo; 
        int cantJugadores;
    public:
        PartidaMultijugador();
        PartidaMultijugador(int duracion, Usuario* usuario, DtFecha* fecha, bool enVivo, int cantJugadores);
        bool getEnVivo();
        int getCantJugadores();
        void setEnVivo(bool enVivo);
        void setCantJugadores(int cantJugadores);
        int getDuracionTotal();
        ~PartidaMultijugador();
};

#endif