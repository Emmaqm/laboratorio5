#include "CInfoVideojuego.h"

/*list<DtVideojuegoFull*> CInfoVIdeojuego::verInformacionVideojuegos() {
    ManejadorVideojuego* manejador = ManejadorVideojuego::getInstancia();
    list<videojuego*> juegos = manejador->getVideojuegos();    
    list<DtVideojuegoFull*> aux;
    list<videojuego*>::iterator it = juegos.begin();
    while(it != juegos.end()){
        DtVideojuegoFull* dtvideojuegofull = (*it)->getDtVideojuegoFull();
        aux.push_back(dtvideojuegofull);
        it++;
    }
    return aux;
}

*/

list<string> CInfoVideojuego::listarVideojuegos(){
    list <string> tempList;
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();

    list<Videojuego*> lv  = ma->getVideojuegos();
    for(list<Videojuego*>::iterator it = lv.begin(); it != lv.end(); ++it){
            tempList.push_back((*it)->getNombre());
    }
    return tempList;
}

void CInfoVideojuego::selectVideojuego(string nombre) {
    this->nombre = nombre;
}

DtVideojuegoFull* CInfoVideojuego::verInformacionVideojuegos() {
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();
    Videojuego* videojuego = ma->getVideojuego(this->nombre);
    return videojuego->getDtVideojuegoFull();


