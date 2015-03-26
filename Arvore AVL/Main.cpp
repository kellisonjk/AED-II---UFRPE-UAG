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
	TreeNode root (20);
	TreeNode node[6]{(8),(4), (10), (12), (14), (22)};

	Tree arvore (&root);
	arvore.AddNode(&node[0]);
	arvore.AddNode(&node[1]);
	arvore.AddNode(&node[2]);
	arvore.AddNode(&node[3]);
	arvore.AddNode(&node[4]);
	arvore.AddNode(&node[5]);

	cout << "\nRoot:" << arvore.Root() << endl;
	cout << "M�ximo:" << arvore.MaximumNode(&root)->key << endl;
	cout << "M�nimo:" << arvore.MinimumNode(&root)->key << endl;

	cout << "\nSucessor do n� [10]: " << arvore.Successor(&node[2])->key << endl;
	cout << "Sucessor do n� [8]: " << arvore.Successor(&node[0])->key << endl;

	cout << "\nAntecessor do n� [22]: " << arvore.Predecessor(&node[5])->key << endl;
	cout << "Antecessor do n� [10]: " << arvore.Predecessor(&node[2])->key << endl;

	cout << endl;
	arvore.PrintInOrder();

    return 0;
}





