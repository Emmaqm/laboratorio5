main: Usuario.o Desarrollador.o Jugador.o CUsuario.o ManejadorUsuario.o main.o g++
	  Usuario.o Desarrollador.o Jugador.o CUsuario.o ManejadorUsuario.o main.o -g -o -sistema


Usuario.o: Usuario.cpp
	g++ -g -c Usuario.cpp

Desarollador.o: Desarollador.cpp
	g++ -g -c Desarollador.cpp

Jugador.o: Jugador.cpp
	g++ -g -c Jugador.cpp

CUsuario.o: CUsuario.cpp
	g++ -g -c CUsuario.cpp

ManejadorUsuario.o: ManejadorUsuario.cpp
	g++ -g -c ManejadorUsuario.cpp

main.o: main.cpp
	g++ -g -c main.cpp

clear: 
	rm -rf *.o sistema

run: sistema
	./sistema