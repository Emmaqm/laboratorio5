#include "Fabrica.h"
#include "ICUsuario.h"
#include "ICSesion.h"
#include "ICCategoria.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Fabrica *fabrica;
ICUsuario *controladorUsuario;
ICSesion *controladorSesion;
ICCategoria *controladorCategoria;

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

void opcionCerrarSesion()
{
    bool loggedOut = controladorSesion->cerrarSesion();
    if (loggedOut)
    {
        cout << "Sesión cerrada" << endl;
    }
    else
    {
        cout << "No hay sesión iniciada" << endl;
    }
}

void opcionAgregarCategoria()
{
    controladorCategoria = fabrica->getICCategoria();
    list<string> categorias = controladorCategoria->listarCategorias();

    if (!categorias.empty())
    {
        cout << "Se listan las Categorias disponibles" << endl;
        for (list<string>::iterator it = categorias.begin(); it != categorias.end(); it++)
        {
            cout << (*it) << endl;
        }
    }
    else
    {
        cout << "No hay categorias disponibles" << endl;
    }

    string genero, plataforma, descripcion;

    cout << "Ingresar categoria: " << endl;
    cout << "Ingrese el genero: " << endl;
    cin >> genero;
    cout << "Ingrese la plataforma: " << endl;
    cin >> plataforma;
    cout << "Ingrese la descripcion: " << endl;
    cin >> descripcion;

    controladorCategoria->ingresarDatos(genero, plataforma, descripcion);

    cout << "¿Desea agregar la categoria? (s/n)" << endl;
    char confirm;
    cin >> confirm;
    if (confirm == 's' || confirm == 'S') {
        if (controladorCategoria->agregarCategoria()) {
            cout << "Categoria agregada" << endl;
        } else {
            cout << "Categoria ya existe" << endl;
        }
    } else {
        cout << "Categoria no agregada" << endl;
    }
}

int main()
{
    fabrica = Fabrica::getInstancia();
    controladorSesion = fabrica->getICSesion();

    bool seguir = true;
    string emailUsuario, tipoUsuario;
    int opcion;

    seederUsuario();
    do
    {
        controladorSesion->datosUsuario(emailUsuario, tipoUsuario);
        if (emailUsuario.empty())
        {
            cout << "Bienvenido!:" << endl;
            cout << "Puede iniciar sesión utilizando el usuario administrador:" << endl;
            cout << "Email: admin@admin.com" << endl;
            cout << "Password: admin" << endl;

            cout << "Opciones:" << endl;
            cout << "1. Iniciar sesión" << endl;
            cout << "2. Crear usuario" << endl;
            cout << "Ingrese una opción:" << endl;
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
        }
        else
        {
            cout << "Bienvenido " << emailUsuario << "!"
                 << " [" << tipoUsuario << "]" << endl;

            cout << "Opciones:" << endl;
            cout << "1. Crear usuario" << endl;
            cout << "2. Agregar categoria" << endl;
            cout << "0. Cerrar sesión" << endl;
            cout << "Ingrese una opción:" << endl;
            cin >> opcion;

            switch (opcion)
            {
            case 0:
            {
                opcionCerrarSesion();
            }
            case 1:
            {
                opcionCrearUsuario();
            }
            case 2:
            {
                opcionAgregarCategoria();
            }
            break;
            default:
                break;
            }
        }

    } while (seguir);
}