#include "Fabrica.h"
#include "ICUsuario.h"
#include "ICSesion.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Fabrica *fabrica;
ICUsuario *controladorUsuario;
ICSesion *controladorSesion;

void seederUsuario()
{
    controladorUsuario = fabrica->getICUsuario();
    DtUsuario *datosUsuario = new DtUsuario("admin@admin.com", "admin");
    controladorUsuario->datosComunes(datosUsuario);
    controladorUsuario->datosEmpresa("admin");
    controladorUsuario->altaUsuario();
    delete controladorUsuario;
}

void opcionIniciarSesion()
{
    string email, password;
    cout << "Ingrese su email: ";
    cin >> email;
    controladorSesion->ingresarEmail(email);

    cout << "Ingrese su password: ";
    cin >> password;
    controladorSesion->ingresarPassword(password);

    bool logueado = controladorSesion->iniciarSesion();
    if (logueado)
    {
        cout << "Sesión iniciada" << endl;
    }
    else
    {
        cout << "Usuario o password incorrectos" << endl;
    }
}

void opcionCrearUsuario()
{
    string emailUsuario, passwordUsuario;

    cout << "Ingrese el email del usuario: ";
    cin >> emailUsuario;
    cout << "Ingrese el password del usuario: ";
    cin >> passwordUsuario;

    DtUsuario *datosUsuario = new DtUsuario(emailUsuario, passwordUsuario);
    controladorUsuario = fabrica->getICUsuario();
    controladorUsuario->datosComunes(datosUsuario);

    cout << "Ingrese el tipo de usuario: ";
    cout << "(D)esarrollador o (J)ugador" << endl;
    char tipo;
    cin >> tipo;

    if (tipo == 'D' || tipo == 'd')
    {
        cout << "Ingrese el nombre de la empresa: ";
        string nombreEmpresa;
        cin >> nombreEmpresa;
        controladorUsuario->datosEmpresa(nombreEmpresa);
    }
    else if (tipo == 'J' || tipo == 'j')
    {
        cout << "Ingrese el nickname del jugador: ";
        string nickname;
        cin >> nickname;
        cout << "Ingrese la descripcion del jugador: ";
        string descripcion;
        cin >> descripcion;
        controladorUsuario->datosJugador(nickname, descripcion);
    }
    else
    {
        cout << "Tipo de usuario inválido" << endl;
    }

    if (controladorUsuario->altaUsuario())
    {
        cout << "Usuario creado" << endl;
    }
    else
    {
        cout << "Usuario ya existe" << endl;
    }
}

int main()
{
    fabrica = Fabrica::getInstancia();
    controladorSesion = fabrica->getICSesion();

    bool seguir = false;
    string emailUsuario, tipoUsuario;
    int opcion;

    seederUsuario();
    do
    {
        if (emailUsuario.empty())
        {
            cout << "Sesión no iniciada" << endl;
            cout << "Puede iniciar sesión utilizando el usuario administrador:" << endl;
            cout << "Email: admin@admin.com" << endl;
            cout << "Password: admin" << endl;
        }
        else
        {
            cout << "Bienvenido " << emailUsuario << "!"
                 << " [" << tipoUsuario << "]" << endl;
        }

        cout << "Bienvenido!:" << endl;
        cout << "1. Iniciar sesión" << endl;
        cout << "2. Crear usuario" << endl;

        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            opcionIniciarSesion();
        }
        break;
        case 2:
        {
            opcionCrearUsuario();
        }
        break;

        default:
            break;
        }

    } while (seguir);
}