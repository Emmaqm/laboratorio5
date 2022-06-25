#include "CVideojuego.h"
#include "Fabrica.h"
#include "ManejadorCategoria.h"
#include "ManejadorVideojuego.h"
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
    string emailUsuario, tipoUsuario;
    controladorSesion->datosUsuario(emailUsuario, tipoUsuario);

    if (emailUsuario.empty()) {
        throw invalid_argument("Usuario no logueado");
    }

    if (tipoUsuario != "Desarrollador") {
        throw invalid_argument("Usuario no es desarrollador");
    }


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

    Videojuego* videojuego = new Videojuego(this->nombre, this->descripcion, this->costo, aux);
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

    Videojuego* videojuego = new Videojuego(this->nombre, this->descripcion, this->costo, aux);
    ManejadorVideojuego* manejadorJuego = ManejadorVideojuego::getInstancia();
    manejadorJuego->agregarVideojuego(videojuego);   
}