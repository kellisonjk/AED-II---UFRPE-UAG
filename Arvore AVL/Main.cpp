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
	
	cout << "Procurar por [10]: " << endl;
	resultadoBusca = arvore.searchNode(10);
	cout << " - resultado: ";

	if(resultadoBusca != NULL)
		cout << resultadoBusca->key << endl << endl;
	else
		cout << " Nada encontrado." << endl << endl;

	cout << "Balaceamento: " << arvore.getBalance() << endl;
	
	cout << endl << "Arvore montada:" << endl;
	arvore.show(arvore.getRoot(), 0);

	cout << endl;

	cout << "Pressione <ENTER> para sair..." << endl;
	std::cin.ignore();

    return 0;
}





