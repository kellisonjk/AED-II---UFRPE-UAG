/*
 * Main.cpp
 *
 *      Author: Kellison
 *		Implementação da classe RedBlackTree
 */

#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include "RedBlackTree.h"

using namespace std;

int main() {
	RedBlackTree arvore;

	arvore.addNode(2);
	arvore.addNode(4);
	arvore.addNode(3);
	arvore.addNode(3);
	arvore.addNode(10);
	arvore.addNode(66);
	arvore.addNode(-1);
	arvore.addNode(7);
	arvore.addNode(100);
	arvore.addNode(15);
	arvore.addNode(8);
	arvore.addNode(9);
	arvore.addNode(16);
	arvore.addNode(68);

	cout << "\nRoot:" << arvore.getRoot()->key << endl;

	cout << endl << "Arvore montada: " << endl;
	arvore.show(arvore.getRoot(), 0);
	cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;
	
	cout << endl;
	cout << "\n\n (Pressione <ENTER> para encerrar...)" << endl;
	getchar();

    return EXIT_SUCCESS;
}





