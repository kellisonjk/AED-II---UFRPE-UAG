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

	arvore.addNode(20);
	arvore.addNode(8);
	arvore.addNode(12);
	arvore.addNode(10);
	arvore.addNode(4);
	arvore.addNode(14);
	arvore.addNode(22);

	cout << "\nRoot:" << arvore.getRoot()->key << endl;
	
	cout << "Maximo:" << arvore.getMaximumNode()->key << endl;
	cout << "Minimo:" << arvore.getMinimumNode()->key << endl;
	
	
	cout << "\nSucessor do no [10]: " << arvore.getSuccessor(10)->key << endl;
	cout << "Sucessor do no [8]: " << arvore.getSuccessor(8)->key << endl;
	
	cout << "\nAntecessor do no [22]: " << arvore.getPredecessor(22)->key << endl;
	cout << "Antecessor do no [10]: " << arvore.getPredecessor(10)->key << endl;
	
	cout << endl;
	cout << "Arvore impressa em ordem crescente: ";
	arvore.printInOrder();
	
	cout << "Procurar por [10]: " << endl;
	//cout << " - caminho na arvore: ";
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

	system("PAUSE");
    return 0;
}





