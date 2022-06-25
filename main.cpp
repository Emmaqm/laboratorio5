#include "Fabrica.h"
#include "ICUsuario.h"
#include "ICSesion.h"
#include "ICCategoria.h"
#include "ICVideojuego.h"
#include "ICEliminarVideojuego.h"
#include "ICSuscripcion.h"

#include <stdlib.h>
#include <stdio.h>
#include <iostream>

using namespace std;

Fabrica *fabrica;
ICUsuario *controladorUsuario;
ICSesion *controladorSesion;
ICCategoria *controladorCategoria;
ICVideojuego *controladorVideojuego;
ICEliminarVideojuego* ControladorElimVideojuego;
ICSuscripcion* controladorSuscripcion;

void seederUsuario()
{
    controladorUsuario = fabrica->getICUsuario();
    DtUsuario *datosUsuario = new DtUsuario("admin@admin.com", "admin");
    controladorUsuario->datosComunes(datosUsuario);
    controladorUsuario->datosEmpresa("admin");
    controladorUsuario->altaUsuario();

    DtUsuario *datosUsuarioJ = new DtUsuario("j", "j");
    controladorUsuario->datosComunes(datosUsuarioJ);
    controladorUsuario->datosJugador("nick", "desc");
    controladorUsuario->altaUsuario();

    delete controladorUsuario;
}

void seederCategorias()
{
    controladorCategoria = fabrica->getICCategoria();
    controladorCategoria->ingresarDatos("Deportes", "PS4", "Descripcion");
    controladorCategoria->seedCategoria();

    controladorCategoria->ingresarDatos("Shooter", "PC", "Descripcion");
    controladorCategoria->seedCategoria();

    controladorCategoria->ingresarDatos("Plataforma", "Switch", "Descripcion");
    controladorCategoria->seedCategoria();

    delete controladorCategoria;
}


void seederJuegos()
{
    controladorVideojuego = fabrica->getICVideojuego();

    controladorVideojuego->ingresarDatos("Fifa22", "Descripcion", 60);
    DtCategoria* dtCategoria = new DtCategoria("Deportes-PS4");
    controladorVideojuego->ingresarCategoria(dtCategoria);
    controladorVideojuego->seedJuego();       
        
    controladorVideojuego->ingresarDatos("CSGO", "Descripcion", 5);
    DtCategoria* dtCategoria2 = new DtCategoria("Shooter-PC");
    controladorVideojuego->ingresarCategoria(dtCategoria);
    controladorVideojuego->seedJuego();       

    controladorVideojuego->ingresarDatos("Mario", "Descripcion", 55);
    DtCategoria* dtCategoria3 = new DtCategoria("Plataforma-Switch");
    controladorVideojuego->ingresarCategoria(dtCategoria);
    controladorVideojuego->seedJuego();    

    controladorVideojuego->ingresarDatos("Spyro", "Descripcion", 42);
    DtCategoria* dtCategoria4 = new DtCategoria("Plataforma-Switch");
    controladorVideojuego->ingresarCategoria(dtCategoria);
    controladorVideojuego->seedJuego();       

    delete controladorVideojuego;  
}


void opcionIniciarSesion()
{
    string email, password;

    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "| Iniciar sesión                                            |" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Ingrese su email: ";
    cin >> email;
    controladorSesion->ingresarEmail(email);

    cout << "Ingrese su password: ";
    cin >> password;
    controladorSesion->ingresarPassword(password);

    bool logueado = controladorSesion->iniciarSesion();
    if (logueado)
    {
        cout << "------------------------" << endl;
        cout << "| ✅  Sesión iniciada  |" << endl;
        cout << "------------------------" << endl;
    }
    else
    {
        cout << "---------------------------------------" << endl;
        cout << "| ❌  Usuario o password incorrectos  |" << endl;
        cout << "---------------------------------------" << endl;
    }
}

void opcionCrearUsuario()
{
    string emailUsuario, passwordUsuario;

    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "| Crear usuario                                             |" << endl;
    cout << "-------------------------------------------------------------" << endl;

    cout << "Ingrese el email del usuario: ";
    cin >> emailUsuario;
    cout << "Ingrese el password del usuario: ";
    cin >> passwordUsuario;

    DtUsuario *datosUsuario = new DtUsuario(emailUsuario, passwordUsuario);
    controladorUsuario = fabrica->getICUsuario();
    controladorUsuario->datosComunes(datosUsuario);

    cout << "Ingrese el tipo de usuario " << endl;
    cout << "(D)esarrollador o (J)ugador: ";
   
    
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
        cout << "---------------------------------" << endl;
        cout << "| ❌  Tipo de usuario inválido  |" << endl;
        cout << "---------------------------------" << endl;
        return;
    }

    if (controladorUsuario->altaUsuario())
    {
        cout << "-----------------------" << endl;
        cout << "| ✅  Usuario creado  |" << endl;
        cout << "-----------------------" << endl;
    }
    else
    {
        cout << "--------------------------" << endl;
        cout << "| ❌  Usuario ya existe  |" << endl;
        cout << "--------------------------" << endl;
    }
}

void opcionCerrarSesion()
{
    bool loggedOut = controladorSesion->cerrarSesion();
    cout << endl;
    if (loggedOut)
    {
        cout << "-----------------------" << endl;
        cout << "| ✅  Sesión cerrada  |" << endl;
        cout << "-----------------------" << endl;
    }
    else
    {
        cout << "-------------------------------" << endl;
        cout << "| ❌  No hay sesión iniciada  |" << endl;
        cout << "-------------------------------" << endl;
    }
}

void opcionAgregarCategoria()
{
    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "| Agregar categoría                                         |" << endl;
    cout << "-------------------------------------------------------------" << endl;

    controladorCategoria = fabrica->getICCategoria();
    list<DtCategoria*> categorias = controladorCategoria->listarCategorias();

    if (!categorias.empty())
    {
        cout << endl;
        cout << "Se listan las Categorias existentes (Genero-Plataforma):" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (list<DtCategoria*>::iterator it = categorias.begin(); it != categorias.end(); it++)
        {
            cout << (*it)->getKey() << endl;
        }
        cout << "-------------------------------------------------------------" << endl;

        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| Ingresar categoria                                        |" << endl;
        cout << "-------------------------------------------------------------" << endl;
    }

    string genero, plataforma, descripcion;

    cout << "Ingrese el genero: ";
    cin >> genero;
    cout << "Ingrese la plataforma: ";
    cin >> plataforma;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;

    controladorCategoria->ingresarDatos(genero, plataforma, descripcion);

    cout << "¿Desea agregar la categoria? (s/n): ";
    char confirm;
    cin >> confirm;
    if (confirm == 's' || confirm == 'S')
    {
        try
        {
            if (controladorCategoria->agregarCategoria())
            {
                cout << "---------------------------" << endl;
                cout << "| ✅  Categoria agregada  |" << endl;
                cout << "---------------------------" << endl;
            }
            else
            {
                cout << "----------------------------" << endl;
                cout << "| ❌ Categoria ya existe   |" << endl;
                cout << "----------------------------" << endl;
            }
        }
        catch (invalid_argument ex)
        {
            cout << ex.what() << endl;
        }
    }
    else
    {
        cout << "-----------------------------" << endl;
        cout << "| 🔷 Categoria no agregada  |" << endl;
        cout << "-----------------------------" << endl;
    }
}

void opcionAgregarVideojuego() {
    controladorVideojuego = fabrica->getICVideojuego();
    controladorCategoria = fabrica->getICCategoria();
    list<DtCategoria*> categorias = controladorCategoria->listarCategorias();

    string nombre, descripcion, keyCategoria;
    int costo;

    cout << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "| Ingresar videojuego                                       |" << endl;
    cout << "-------------------------------------------------------------" << endl;
    cout << "Ingrese el nombre: ";
    cin >> nombre;
    cout << "Ingrese la descripcion: ";
    cin >> descripcion;
    cout << "Ingrese el costo: ";
    cin >> costo;

    controladorVideojuego->ingresarDatos(nombre, descripcion, costo);

    if (!categorias.empty())
    {
        cout << "Se listan las Categorias disponibles (Genero-Plataforma):" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (list<DtCategoria*>::iterator it = categorias.begin(); it != categorias.end(); it++)
        {
            cout << (*it)->getKey() <<  endl;
        }
        cout << "-------------------------------------------------------------" << endl;

        bool seguirC = true;
        while (seguirC) {
            cout << "Ingrese una de las categorías disponibles: ";
            cin >> keyCategoria;

            try
            {
                DtCategoria* dtCategoria = new DtCategoria(keyCategoria);
                controladorVideojuego->ingresarCategoria(dtCategoria);

                char confirm;
                cout << "Desea seguir ingresando categorias (s/n): ";
                cin >> confirm;
                if (confirm == 'n' || confirm == 'N')
                {
                    cout << "Confirma agregar el videojuego (s/n): ";
                    cin >> confirm;

                    if (confirm == 's' || confirm == 'S'){
                        controladorVideojuego->agregarJuego();
                        cout << "----------------------------" << endl;
                        cout << "| ✅  Videojuego agregado  |" << endl;
                        cout << "----------------------------" << endl;
                        seguirC = false;
                    }else {
                        cout << "------------------------------" << endl;
                        cout << "| 🔷 Videojuego no agregado  |" << endl;
                        cout << "------------------------------" << endl;
                        seguirC = false;
                    }
                }        
            }
            catch(invalid_argument ex)
            {
                cout << ex.what() << endl;
            }
        }
    } 
    else
    {
        cout << "-----------------------------------------------------------------" << endl;
        cout << "| ❌ No hay categorias creadas.                                 |" << endl;
        cout << "|    Para ingresar un juego primero debes crear categorías.     |" << endl;
        cout << "-----------------------------------------------------------------" << endl;
    }
}

void opcionSuscribirseVideojuego(){
    controladorSuscripcion = fabrica->getICSuscripcion();
    try
    {
        list<string> suscripcionesActivas = controladorSuscripcion->listarSuscripcionesActivas();
        list<string> suscripcionesInactivas = controladorSuscripcion->listarSuscripcionesInactivas();

        cout << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "| Suscribirse a videojuego                                  |" << endl;
        cout << "-------------------------------------------------------------" << endl;

        cout << "Se listan las suscripciones activas:" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (list<string>::iterator it = suscripcionesActivas.begin(); it != suscripcionesActivas.end(); it++)
        {
            cout << (*it) <<  endl;
        }

        cout << endl;
        cout << "Se listan las suscripciones inactivas:" << endl;
        cout << "-------------------------------------------------------------" << endl;
        for (list<string>::iterator it = suscripcionesInactivas.begin(); it != suscripcionesInactivas.end(); it++)
        {
            cout << (*it) <<  endl;
        }

        string nombre;
        cout << endl;
        cout << "Ingresar datos para suscribirse:" << endl;
        cout << "-------------------------------------------------------------" << endl;
        cout << "Ingrese el nombre del videojuego: ";
        cin >> nombre;

        bool ingresado = controladorSuscripcion->ingresarVideojuego(nombre);

        if(ingresado == false) {
            cout << "------------------------------------" << endl;
            cout << "| ❌ El juego ingresado no existe  |" << endl;
            cout << "------------------------------------" << endl;
        }else {
            if(controladorSuscripcion->existeSuscripcion()) {
                cout << "--------------------------------------------------------" << endl;
                cout << "| ❌ Ya tienes una suscripción activa para este juego  |" << endl;
                cout << "--------------------------------------------------------" << endl;
            } else {
                char tipo;
                TipoPago tipoPago;
                cout << "Ingrese su método de pago:" << endl;
                cout << "(C)rédito o (D)ébito: ";
                cin >> tipo;
                if(tipo == 'C' || tipo == 'c') {
                    tipoPago = CREDITO;
                } else if (tipo == 'D' || tipo == 'd') {
                    tipoPago = DEBITO;
                } else {
                    cout << "-------------------------------" << endl;
                    cout << "| ❌ Método de pago inválido  |" << endl;
                    cout << "-------------------------------" << endl;
                    return;
                }

                controladorSuscripcion->ingresarMetodoPago(tipoPago);

                char confirm;
                cout << "Confirma la compra de esta suscripción (s/n): ";
                cin >> confirm;

                if (confirm == 's' || confirm == 'S'){
                    if(controladorSuscripcion->agregarSuscripcion()) {
                        cout << "------------------------------" << endl;
                        cout << "| ✅  Suscripción adquirida  |" << endl;
                        cout << "------------------------------" << endl;
                    }else {
                        cout << "--------------------------------------" << endl;
                        cout << "| ❌  Error al adquirir suscripción  |" << endl;
                        cout << "--------------------------------------" << endl;
                    }
                }else {
                    cout << "-----------------------------" << endl;
                    cout << "| 🔷 Suscripción cancelada  |" << endl;
                    cout << "-----------------------------" << endl;
                }

            }
        }
    }
    catch(invalid_argument ex)
    {
        cout << ex.what() << endl;
    }
}

void opcionEliminarVideojuego(){
    bool salir = false; 
    string opcion;
    ControladorElimVideojuego = fabrica->getICEliminarVideojuego();

    if(controladorSesion->esDesarrollador()){
        list<string> videojuegos = ControladorElimVideojuego->listarVideojuegos();

        if(!videojuegos.empty()){
            cout<< "Videojuegos disponibles:"<< endl;
            for(list<string>::iterator it = videojuegos.begin(); it != videojuegos.end(); ++it ){
                    cout<< (*it) << endl;
            }
            do{
                 cout << endl << " Ingrese el nombre del videojuego que desea eliminar: " << endl;
                 cin >> opcion;  
                 for(list<string>::iterator iter = videojuegos.begin(); iter != videojuegos.end(); ++iter){
                    if(*iter == opcion){
                        salir=true;
                    }
                    if(!salir){
                            cout<<" _________________________________________________"<<endl;
                            cout<<"|                                                 |"<<endl;
                            cout<<"|  ❌ El nombre del videojuego es incorrecto      |"<<endl;
                            cout<<"|                                                 |"<<endl;
                            cout<<"|_________________________________________________|"<<endl;
                    }



                 }

            }while( !salir );

        }
    
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
    seederCategorias();
    seederJuegos();
    
    do
    {
        controladorSesion->datosUsuario(emailUsuario, tipoUsuario);
        if (emailUsuario.empty())
        {
            cout << "-------------------------------------------------------------" << endl;
            cout << "|                       Bienvenido!                         |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| Puede iniciar sesión utilizando el usuario administrador: |" << endl;
            cout << "| Email: admin@admin.com                                    |" << endl;
            cout << "| Password: admin                                           |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| Opciones:                                                 |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| (1) Iniciar sesión                                        |" << endl;
            cout << "| (2) Crear usuario                                         |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "| (0) Salir                                                 |" << endl;
            cout << "-------------------------------------------------------------" << endl;
            cout << "Ingrese una opción: ";
            cin >> opcion;

            switch (opcion)
            {
            case 0:
            {
                seguir = false;
            }
            break;
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
            if(tipoUsuario == "Desarrollador") {
                cout << endl;
                cout << "Bienvenido " << emailUsuario << "!" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| Opciones:                                                 |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| (1) Crear usuario                                         |" << endl;
                cout << "| (2) Agregar categoria                                     |" << endl;
                cout << "| (3) Agregar videojuego                                    |" << endl;
                cout << "| (9) Cerrar sesión                                         |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| (0) Salir                                                 |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "Ingrese una opción: ";    
                cin >> opcion;

                switch (opcion)
                {
                case 0:
                {
                    seguir = true;
                }
                break;
                case 1:
                {
                    opcionCrearUsuario();
                }
                break;
                case 2:
                {
                    opcionAgregarCategoria();
                }
                break;
                case 3:
                {
                    opcionAgregarVideojuego();
                }
                break;
                case 9:
                {
                    opcionCerrarSesion();
                }
                break;
                default:
                    break;
                }
            } else {
                cout << endl;
                cout << "Bienvenido " << emailUsuario << "!" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| Opciones:                                                 |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| (1) Crear usuario                                         |" << endl;
                cout << "| (2) Suscribirse a videojuego                              |" << endl;
                cout << "| (9) Cerrar sesión                                         |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "| (0) Salir                                                 |" << endl;
                cout << "-------------------------------------------------------------" << endl;
                cout << "Ingrese una opción: ";    
                cin >> opcion;

                 switch (opcion)
                {
                case 0:
                {
                    seguir = true;
                }
                break;
                case 1:
                {
                    opcionCrearUsuario();
                }                
                break;
                case 2:
                {
                    opcionSuscribirseVideojuego();
                }                
                break;
                case 9:
                {
                    opcionCerrarSesion();
                }
                break;
                default:
                    break;
                }
            }
        
        
        }

    } while (seguir);
}