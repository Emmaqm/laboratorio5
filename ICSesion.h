#ifndef fICSESION
#define fICSESION

#include <list>
#include <string>

using namespace std;

class ICSesion {
    public:
        virtual void ingresarEmail(string email) = 0;
        virtual void ingresarPassword(string pass) = 0;
        virtual bool iniciarSesion() = 0;
};


#endif