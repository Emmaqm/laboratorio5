#ifndef VIDEOJUEGO
#define VIDEOJUEGO
#include <string>

using namespace std;

class Videojuego {
    private:
        string nombre;
        string descripcion;
        int costo;
        DtCategoria categoria;
    public:
        Videojuego();
        Videojuego(string nombre, string descripcion, int costo, DtCategoria categoria);
        string getNombre();
        string getDescripcion();
        int getCosto();
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setCosto(int costo);
        ~Videojuego();
};

#endif