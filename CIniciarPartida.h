#ifndef CINICIARPARTIDA
#define CINICIARPARTIDA

#include <list>
#include <string>

#include "ICIniciarPartida.h"

using namespace std;

class CIniciarPartida: public ICIniciarPartida {
    private:
        string nombre;
        bool continuaPartida;
        int duracion;
        bool enVivo;
        int cantJugadores;
    public:
        list<string> listarSuscripcionesActivas();
        void seleccionarVideojuego(string nombre);
        void datosPartidaIndividual(bool continuaPartida, int duracion);
        void datosPartidaMultijugador(bool enVivo, int cantJugadores, int duracion);
        void ingresarPartida();
};


#endif