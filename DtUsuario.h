#ifndef DTUSUARIO
#define DTUSUARIO
#include <string>

using namespace std;

class DtUsuario {
    private:
        string email;
        string password;
    public:
        DtUsuario();
        DtUsuario(string email, string password);
        string getEmail();
        string getPassword();
        ~DtUsuario();
};

#endif