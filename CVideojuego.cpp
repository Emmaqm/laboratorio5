#include "CVideojuego.h"
#include "Fabrica.h"
#include "ManejadorCategoria.h"
#include "ManejadorVideojuego.h"
#include "ManejadorUsuario.h"
#include <stdexcept>

void CVideojuego::ingresarDatos(string nombre, string descripcion, int costo) {
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo = costo;
}

void CVideojuego::ingresarCategoria(DtCategoria* dtCategoria) {
    this->categorias.push_back(dtCategoria);
}

void CVideojuego::agregarJuego() {
    Fabrica* fabrica = Fabrica::getInstancia();
    ICSesion* controladorSesion = fabrica->getICSesion();
    Desarrollador* desarrollador = controladorSesion->getDesarrollador();

    ManejadorCategoria* manejadorCategoria = ManejadorCategoria::getInstancia();
    map<string, Categoria*> aux;
    list<DtCategoria*>::iterator it = this->categorias.begin();
    while (it != this->categorias.end())
    {
        string genero = (*it)->getGenero();
        string plataforma = (*it)->getPlataforma();

        Categoria* categoria = manejadorCategoria->getCategoria(genero, plataforma);
        if(categoria != NULL) {
            aux.insert(pair<string, Categoria*> (categoria->getDtCategoria()->getKey(), categoria));
        }
        
        it++;
    }

    Videojuego* videojuego = new Videojuego(this->nombre, this->descripcion, this->costo, aux, desarrollador);
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    manejadorJuego->agregarVideojuego(videojuego);   
}

void CVideojuego::seedJuego() {
    ManejadorCategoria* manejadorCategoria = ManejadorCategoria::getInstancia();
    map<string, Categoria*> aux;
    list<DtCategoria*>::iterator it = this->categorias.begin();
    while (it != this->categorias.end())
    {
        string genero = (*it)->getGenero();
        string plataforma = (*it)->getPlataforma();

        Categoria* categoria = manejadorCategoria->getCategoria(genero, plataforma);
        if(categoria != NULL) {
            aux.insert(pair<string, Categoria*> (categoria->getDtCategoria()->getKey(), categoria));
        }
        
        it++;
    }

    ManejadorUsuario* manejadorUsuario = ManejadorUsuario::getInstancia();
    Usuario* usuario = manejadorUsuario->getUsuario("admin@admin.com");
    Desarrollador* desarrollador = dynamic_cast<Desarrollador *>(usuario);

    Videojuego* videojuego = new Videojuego(this->nombre, this->descripcion, this->costo, aux, desarrollador);
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    manejadorJuego->agregarVideojuego(videojuego);   
}