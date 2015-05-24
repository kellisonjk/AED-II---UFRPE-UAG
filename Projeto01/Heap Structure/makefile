all: Heap.exe

Heap.exe: Heap.o Main.o
	g++ Heap.o Main.o -o Heap.exe

Main.o: Main.cpp
	g++ -c Main.cpp

Heap.o: Heap.h Heap.cpp
	g++ -c Heap.cpp
	
clean:
	rm Heap.exe *.o