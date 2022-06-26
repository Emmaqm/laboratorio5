#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "Partida.h"

class PartidaIndividual : public Partida{
    private:
        bool continuaPartida; 
    public:
        PartidaIndividual();
        PartidaIndividual(int duracion, Usuario* usuario, DtFecha* fecha, bool continuaPartida);
        bool getContinuaPartida();
        void setContinuaPartida(bool continuaPartida);
        int getDuracionTotal();
        ~PartidaIndividual();
};

#endif