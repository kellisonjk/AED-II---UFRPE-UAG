all: Graph.exe

Graph.exe: Graph.o Edge.o Main.o 
	g++ Graph.o Edge.o Main.o -o Graph.exe

Main.o: Main.cpp
	g++ -c Main.cpp

Graph.o: Graph.hpp Graph.cpp
	g++ -c Graph.cpp

Edge.o: Edge.hpp Edge.cpp
	g++ -c Edge.cpp
			
clean:
	rm Graph.exe *.o