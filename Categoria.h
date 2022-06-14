#ifndef CATEGORIA
#define CATEGORIA
#include <string>

using namespace std;

class Categoria {
    private:
        string tipoGenero;
        string tipoPlataforma;
        string descripcion;
    public:
        Categoria();
        Categoria(string tipoGenero, string tipoPlataforma, string descripcion);
        string getTipoGenero();
        string getTipoPlataforma();
        string getDescripcion();
        void setTipoGenero(string tipoGenero);
        void setTipoPlataforma(string tipoPlataforma);
        void setDescripcion(string descripcion);
        virtual ~Categoria() = 0;
};

#endif