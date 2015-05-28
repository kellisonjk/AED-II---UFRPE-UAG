all: Graph.exe

Graph.exe: Graph.o Arris.o Main.o
	g++ Graph.o Arris.o Main.o -o Graph.exe

Main.o: Main.cpp
	g++ -c Main.cpp

Graph.o: Graph.hpp Graph.cpp
	g++ -c Graph.cpp

Arris.o: Arris.hpp Arris.cpp
	g++ -c Arris.cpp
		
clean:
	rm Graph.exe *.o