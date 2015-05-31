all: Kruskal.o Graph.o Edge.o
	
Graph.o: ../Graph/Graph.hpp ../Graph/Graph.cpp
	g++ -c ../Graph/Graph.cpp

Edge.o: ../Graph/Edge.hpp ../Graph/Edge.cpp
	g++ -c ../Graph/Edge.cpp

Kruskal.o: Kruskal.hpp Kruskal.cpp
	g++ -c Kruskal.cpp

		
clean:
	rm *.o