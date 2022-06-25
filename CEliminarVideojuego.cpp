#include "CEliminarVideojuego.h"


list<string> CEliminarVideojuego::listarVideojuegos(){
    list <string> tempList;
    ManejadorVideojuego *ma = ManejadorVideojuego::getInstancia();
   /* list<Videojuego*> lv  = ma->getVideojuegos();
    for(list<Videojuego*>::iterator it = lv.begin(); it != lv.end(); ++it){
        
        tempList.push_back((*it)->getNombre());
    }*/

    return tempList;
}