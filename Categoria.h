#ifndef CATEGORIA
#define CATEGORIA
#include <string>

using namespace std;

class Categoria {
    private:
        string genero;
        string plataforma;
        string descripcion;
    public:
        Categoria();
        Categoria(string genero, string plataforma, string descripcion);
        string getGenero();
        string getPlataforma();
        string getDescripcion();
        void setGenero(string genero);
        void setPlataforma(string plataforma);
        void setDescripcion(string descripcion);
        ~Categoria();
};

#endif