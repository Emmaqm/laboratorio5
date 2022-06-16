sistema: DtUsuario.o ManejadorUsuario.o CUsuario.o CSesion.o Usuario.o Desarrollador.o Jugador.o Sesion.o Fabrica.o main.o
	g++ DtUsuario.o ManejadorUsuario.o CUsuario.o CSesion.o Usuario.o Desarrollador.o Jugador.o Sesion.o Fabrica.o main.o -g -o sistema

DtUsuario.o: DtUsuario.cpp
	g++ -g -c DtUsuario.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp
	g++ -g -c ManejadorUsuario.cpp

CUsuario.o: CUsuario.cpp
	g++ -g -c CUsuario.cpp

CSesion.o: CSesion.cpp
	g++ -g -c CSesion.cpp

Usuario.o: Usuario.cpp
	g++ -g -c Usuario.cpp

Desarollador.o: Desarollador.cpp
	g++ -g -c Desarollador.cpp

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