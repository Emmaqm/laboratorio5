sistema: DtUsuario.o ManejadorUsuario.o ManejadorCategoria.o ManejadorVideojuego.o CSuscripcion.o CVideojuego.o CInfoVideojuego.o CEliminarVideojuego.o CCategoria.o CUsuario.o CSesion.o Suscripcion.o Videojuego.o Categoria.o DtVideojuegoFull.o DtFecha.o DtCategoria.o Usuario.o Desarrollador.o Jugador.o Sesion.o Fabrica.o main.o
	g++ DtUsuario.o ManejadorUsuario.o ManejadorCategoria.o ManejadorVideojuego.o CSuscripcion.o CVideojuego.o CInfoVideojuego.o CEliminarVideojuego.o CCategoria.o CUsuario.o CSesion.o Suscripcion.o Videojuego.o Categoria.o DtVideojuegoFull.o DtFecha.o DtCategoria.o Usuario.o Desarrollador.o Jugador.o Sesion.o Fabrica.o main.o -g -o sistema

DtUsuario.o: DtUsuario.cpp
	g++ -g -c DtUsuario.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp
	g++ -g -c ManejadorUsuario.cpp
	
ManejadorCategoria.o: ManejadorCategoria.cpp
	g++ -g -c ManejadorCategoria.cpp

ManejadorVideojuego.o: ManejadorVideojuego.cpp
	g++ -g -c ManejadorVideojuego.cpp

CSuscripcion.o: CSuscripcion.cpp
	g++ -g -c CSuscripcion.cpp

CVideojuego.o: CVideojuego.cpp
	g++ -g -c CVideojuego.cpp

CInfoVideojuego.o: CInfoVideojuego.cpp
	g++ -g -c CInfoVideojuego.cpp

CEliminarVideojuego.o: CEliminarVideojuego.cpp
	g++ -g -c CEliminarVideojuego.cpp

CCategoria.o: CCategoria.cpp
	g++ -g -c CCategoria.cpp

CUsuario.o: CUsuario.cpp
	g++ -g -c CUsuario.cpp

CSesion.o: CSesion.cpp
	g++ -g -c CSesion.cpp

Suscripcion.o: Suscripcion.cpp
	g++ -g -c Suscripcion.cpp

Videojuego.o: Videojuego.cpp
	g++ -g -c Videojuego.cpp

Categoria.o: Categoria.cpp
	g++ -g -c Categoria.cpp

DtVideojuegoFull.o: DtVideojuegoFull.cpp
	g++ -g -c DtVideojuegoFull.cpp

DtFecha.o: DtFecha.cpp
	g++ -g -c DtFecha.cpp

DtCategoria.o: DtCategoria.cpp
	g++ -g -c DtCategoria.cpp

Usuario.o: Usuario.cpp
	g++ -g -c Usuario.cpp

Desarrollador.o: Desarrollador.cpp
	g++ -g -c Desarrollador.cpp

Jugador.o: Jugador.cpp
	g++ -g -c Jugador.cpp

Sesion.o: Sesion.cpp
	g++ -g -c Sesion.cpp

Fabrica.o: Fabrica.cpp
	g++ -g -c Fabrica.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clear: 
	rm -rf *.o sistema

run: sistema
	./sistema