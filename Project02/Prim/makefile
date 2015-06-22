all: AppPrim.exe

AppPrim.exe: Prim.o Graph.o Edge.o Main.o Heap.o
	g++ Prim.o Graph.o Edge.o Main.o Heap.o -o AppPrim.exe		

Graph.o: ../Graph/Graph.hpp ../Graph/Graph.cpp
	g++ -c ../Graph/Graph.cpp

Edge.o: ../Graph/Edge.hpp ../Graph/Edge.cpp
	g++ -c ../Graph/Edge.cpp

Heap.o: ../lib/Heap/Heap.h ../lib/Heap/Heap.cpp
	g++ -c ../lib/Heap/Heap.cpp

Prim.o: Prim.hpp Prim.cpp
	g++ -c Prim.cpp

Main.o: Main.cpp
	g++ -c Main.cpp
		
clean:
	rm *.o