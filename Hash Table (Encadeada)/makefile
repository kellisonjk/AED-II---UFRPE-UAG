all: HashTable.exe

HashTable.exe: HashTable.o Data.o Main.o
	g++ HashTable.o Data.o Main.o -o HashTable.exe

Main.o: Main.cpp
	g++ -c Main.cpp

HashTable.o: HashTable.h HashTable.cpp
	g++ -c HashTable.cpp

Data.o: Data.h Data.cpp
	g++ -c Data.cpp
	
clean:
	rm HashTable.exe *.o