/*
 * Main.cpp
 *
 *      Author: Kellison
 *		Implementação da classe Tree (árvore AVL)
 */

#include <iostream>
#include <cstdlib>
#include "Tree.h"
using namespace std;

int main() {
	TreeNode *resultadoBusca;
	Tree arvore;
	int key; // usada ´para opção de remoção

	arvore.addNode(2);
	arvore.addNode(3);
	arvore.addNode(4);
	arvore.addNode(3);
	arvore.addNode(5);
	arvore.addNode(9);
	arvore.addNode(0);
	arvore.addNode(6);
	arvore.addNode(-6);
	arvore.addNode(-7);
	arvore.addNode(10);

	cout << "\nRoot:" << arvore.getRoot()->key << endl;
	
	cout << "Maximo:" << arvore.getMaximumNode()->key << endl;
	cout << "Minimo:" << arvore.getMinimumNode()->key << endl;
	cout << endl;
	cout << "Arvore impressa em ordem crescente: ";
	arvore.printInOrder();
	
	cout << endl << "Arvore montada: (balanceamento = " << arvore.getBalance() << ")" << endl;
	arvore.show(arvore.getRoot(), 0);
	cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;


	char a = '1';

	// Repete o processo de remoção enquanto assim desejar o usuário
	while (a == '1'){
		cout << "=====================================" << endl;
		cout << "Remover no da arvore." << endl << endl;
		cout << "- Digite o no a ser removido: ";

		cin >> key;
		cout << endl;
		arvore.removeNode(key);

		cout << endl << "Arvore montada apos remocao do no:  (balanceamento = " << arvore.getBalance() << ")" << endl;
		arvore.show(arvore.getRoot(), 0);
		cout << endl << "No. de elementos: " << arvore.getNElements() << endl << endl;

		cout << endl << " Digite '1' para uma nova remocao, ou qualquer outro caractere para encerrar:  ";
		cin >> a;
	}

	cout << endl;
	system("PAUSE");

    return 0;
}





