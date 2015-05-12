/*
* Main.cpp
*
*      Author: Kellison
*		Implementaзгo da classe Hash Table
*/

#include "HashTable.h" 


using namespace std;


int main() {
	
	HashTable<Data, string> hashtbl(10);

	hashtbl.insert(Data("Kellison", 22));
	hashtbl.insert(Data("Kelly", 22));
	hashtbl.insert(Data("Klebson", 19));
	hashtbl.insert(Data("Clovis", 50));
	hashtbl.insert(Data("Zelia", 30));
	hashtbl.insert(Data("Maria Joaquina", 42));

	cout <<  endl << " Hash Table (Encadeada) " << endl << endl;


	hashtbl.printHash();

	cout << "\n\n (Pressione <ENTER> para encerrar...)" << endl;
	getchar();

	return 0;
}




