all: AppKruskal.exe

AppKruskal.exe: Graph.o Edge.o Main.o Kruskal.o 
	g++ Main.o Kruskal.o Graph.o Edge.o -o AppKruskal.exe

Main.o: Main.cpp
	g++ -c Main.cpp

Graph.o: ../Graph/Graph.hpp ../Graph/Graph.cpp
	g++ -c ../Graph/Graph.cpp

Edge.o: ../Graph/Edge.hpp ../Graph/Edge.cpp
	g++ -c ../Graph/Edge.cpp

Kruskal.o: Kruskal.hpp Kruskal.cpp
	g++ -c Kruskal.cpp
		
clean:
	rm GrafosApp.exe *.o