all: GrafosApp.exe

GrafosApp.exe: Graph.o Edge.o GrafosApp.o Kruskal.o 
	g++ Graph.o Edge.o GrafosApp.o Kruskal.o -o GrafosApp.exe

GrafosApp.o: GrafosApp.cpp
	g++ -c GrafosApp.cpp

Graph.o: ./Graph/Graph.hpp ./Graph/Graph.cpp
	g++ -c ./Graph/Graph.cpp

Edge.o: ./Graph/Edge.hpp ./Graph/Edge.cpp
	g++ -c ./Graph/Edge.cpp

Kruskal.o: ./Kruskal/Kruskal.hpp ./Kruskal/Kruskal.cpp
	g++ -c ./Kruskal/Kruskal.cpp
		
clean:
	rm GrafosApp.exe *.o