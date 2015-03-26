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
	TreeNode root (20), *resultadoBusca;
	TreeNode node[6]{(8),(12), (10), (4), (14), (22)};
	Tree arvore (&root);

	cout << "\nRoot:" << arvore.Root() << endl;

	arvore.AddNode(&node[0]);
	arvore.AddNode(&node[1]);
	arvore.AddNode(&node[2]);
	arvore.AddNode(&node[3]);
	arvore.AddNode(&node[4]);
	arvore.AddNode(&node[5]);

	cout << "Máximo:" << arvore.MaximumNode(&root)->key << endl;
	cout << "Mínimo:" << arvore.MinimumNode(&root)->key << endl;

	cout << "\nSucessor do nó [10]: " << arvore.Successor(&node[2])->key << endl;
	cout << "Sucessor do nó [8]: " << arvore.Successor(&node[0])->key << endl;

	cout << "\nAntecessor do nó [22]: " << arvore.Predecessor(&node[5])->key << endl;
	cout << "Antecessor do nó [10]: " << arvore.Predecessor(&node[2])->key << endl;

	cout << endl;
	cout << "Árvore impressa em ordem crescente: ";
	arvore.PrintInOrder();

	cout << "Procurar por [10]: " << endl;
	cout << " - caminho na árvore: ";
	resultadoBusca = arvore.SearchNode(&root, 10);
	cout << "\n - resultado: ";

	if(resultadoBusca != NULL)
		cout << resultadoBusca->key << endl;
	else
		cout << " Nada encontrado." << endl;

    return 0;
}





