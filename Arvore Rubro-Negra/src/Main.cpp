/*
 * Main.cpp
 *
 *      Author: Kellison
 *		Implementa��o da classe RedBlackTree
 */

#include <iostream>
#include <cstdlib>
#include "RedBlackTree.h"

using namespace std;

int main() {
	RedBlackTree arvore;
	int key; // usada para op��o de remo��o

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
	
	
	char a = '1';

	// Repete o processo de remo��o enquanto assim desejar o usu�rio
	while (a == '1'){
		cout << "=====================================" << endl;
		cout << "Remover no da arvore." << endl << endl;
		cout << "- Digite o no a ser removido: ";

		cin >> key;
		cout << endl;
		arvore.removeNode(key);

		cout << endl << "Arvore montada apos remocao do no: " << key << endl;
		arvore.show(arvore.getRoot(), 0);
		cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;

		cout << endl << " Digite '1' - nova remocao, ou qualquer outro caractere para encerrar: ";
		cin >> a;
	}

	cout << endl;
	system("PAUSE");

    return EXIT_SUCCESS;
}




