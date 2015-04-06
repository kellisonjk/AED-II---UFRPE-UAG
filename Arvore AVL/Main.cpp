/*
 * Main.cpp
 *
 *  Created on: Mar 25, 2015
 *      Author: Kellison
 */

#include <iostream>
#include <cstdlib>
#include "Tree.h"
#include "TreeNode.h"
using namespace std;

int main() {
	TreeNode *resultadoBusca;
	Tree arvore;
	int key;

	arvore.addNode(1);
	arvore.addNode(2);
	arvore.addNode(4);
	arvore.addNode(3);
	arvore.addNode(5);
	arvore.addNode(9);
	arvore.addNode(0);
	arvore.addNode(6);
	arvore.addNode(-6);
	arvore.addNode(-7);

	cout << "\nRoot:" << arvore.getRoot()->key << endl;
	
	cout << "Maximo:" << arvore.getMaximumNode()->key << endl;
	cout << "Minimo:" << arvore.getMinimumNode()->key << endl;
	cout << endl;
	cout << "Arvore impressa em ordem crescente: ";
	arvore.printInOrder();
	
	cout << endl << "Arvore montada:" << endl;
	arvore.show(arvore.getRoot(), 0);
	cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;


	int a = 1;
	while (a == 1){
		cout << "Remover no da arvore." << endl;
		cout << "- Digite o no a ser removido: ";

		cin >> key;
		arvore.removeNode(key);

		cout << endl << "Arvore montada apos remocao do no:" << endl;
		arvore.show(arvore.getRoot(), 0);
		cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;

		cout << endl << "Digite: 1 - Remover outro no, 0 - Encerrar. :  ";
		cin >> a;
	}

	cout << endl;
	system("PAUSE");

    return 0;
}





