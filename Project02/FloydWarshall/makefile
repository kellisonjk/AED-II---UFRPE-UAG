all: AppFloyd.exe

AppFloyd.exe: FloydWarshall.o Graph.o Edge.o Main.o
	g++ FloydWarshall.o Graph.o Edge.o Main.o -o AppFloyd.exe		

Graph.o: ../Graph/Graph.hpp ../Graph/Graph.cpp
	g++ -c ../Graph/Graph.cpp

Edge.o: ../Graph/Edge.hpp ../Graph/Edge.cpp
	g++ -c ../Graph/Edge.cpp

FloydWarshall.o: FloydWarshall.hpp FloydWarshall.cpp
	g++ -c FloydWarshall.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
		
clean:
	rm *.o