#ifndef DTCATEGORIA
#define DTCATEGORIA
#include <string>

using namespace std;

class DtCategoria {
    private:
        string genero;
        string plataforma;
        string descripcion;
    public:
        DtCategoria();
        DtCategoria(string key);
        DtCategoria(string genero, string plataforma, string descripcion);
        string getGenero();
        string getPlataforma();
        string getDescripcion();
        string getKey();
        ~DtCategoria();
};

#endif