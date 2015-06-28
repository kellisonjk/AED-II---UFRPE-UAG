all: AppDijkstra.exe

AppDijkstra.exe: Dijkstra.o Graph.o Edge.o Main.o Heap.o
	g++ Dijkstra.o Graph.o Edge.o Main.o Heap.o -o AppDijkstra.exe		

Graph.o: ../Graph/Graph.hpp ../Graph/Graph.cpp
	g++ -c ../Graph/Graph.cpp

Edge.o: ../Graph/Edge.hpp ../Graph/Edge.cpp
	g++ -c ../Graph/Edge.cpp

Heap.o: ./Heap/Heap.h ./Heap/Heap.cpp
	g++ -c ./Heap/Heap.cpp

Dijkstra.o: Dijkstra.hpp Dijkstra.cpp
	g++ -c Dijkstra.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
		
clean:
	rm *.o