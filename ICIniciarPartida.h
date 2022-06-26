#ifndef ICINICIARPARTIDA
#define ICINICIARPARTIDA

#include <list>
#include <string>

using namespace std;

class ICIniciarPartida {
    public:
        list<string> listarSuscripcionesActivas();
        virtual void seleccionarVideojuego(string nombre) = 0;
        virtual void datosPartidaIndividual(bool continuaPartida, int duracion) = 0;
        virtual void datosPartidaMultijugador(bool enVivo, int cantJugadores, int duracion) = 0;
        virtual void ingresarPartida() = 0;
};


#endif