#ifndef DTFECHA
#define DTFECHA

#include <string>

using namespace std;

class DtFecha{
    private:
        int dia;
        int mes;
        int anio;
        int hora;
        int minuto;
    public:
        DtFecha();
        DtFecha(int dia, int mes, int anio, int hora, int minuto);
        int getDia();
        int getMes();
        int getAnio();
        int getHora();
        int getMinuto();
        string format();
        ~DtFecha();
};


#endif