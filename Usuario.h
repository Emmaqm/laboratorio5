#ifndef USUARIO
#define USUARIO
#include <string>

using namespace std;

class Usuario {
    private:
        string email;
        string password;
    public:
        Usuario();
        Usuario(string email, string password);
        string getEmail();
        string getPassword();
        void setEmail(string email);
        void setPassword(string password);
        virtual ~Usuario() = 0;
};

#endif