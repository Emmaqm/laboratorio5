#include "DtFecha.h"
#include <stdexcept>

using namespace std;

DtFecha::DtFecha(){};
DtFecha::DtFecha(int dia, int mes, int anio, int hora, int minuto){
    if(dia > 31 || dia < 1 || mes > 12 || mes < 1 || anio < 1900) {
        throw invalid_argument("Fecha invalida");
    }
    if(hora > 23 || hora < 0 || minuto > 59 || minuto < 0) {
        throw invalid_argument("Hora invalida");
    }

    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
    this->hora = hora;
    this->minuto = minuto;
};

int DtFecha::getDia(){
    return this->dia;
};

int DtFecha::getMes(){
    return this->mes;
};

int DtFecha::getAnio(){
    return this->anio;
};

int DtFecha::getHora(){
    return this->hora;
};

int DtFecha::getMinuto(){
    return this->minuto;
};

string DtFecha::format(){
    string dia = to_string(this->getDia());
    if(dia.length() == 1){
        dia = "0" + dia;
    }

    string mes = to_string(this->getMes());
    if(mes.length() == 1){
        mes = "0" + mes;
    }
    
    string hora = to_string(this->getHora());
    if(hora.length() == 1){
        hora = "0" + hora;
    }

    string minutos = to_string(this->getMinuto());
    if(minutos.length() == 1){
        minutos = "0" + minutos;
    }

    string fecha = dia + "/" + mes + "/" + to_string(this->getAnio()) + " " + hora + ":" + minutos;
    return fecha;
}

DtFecha::~DtFecha(){}