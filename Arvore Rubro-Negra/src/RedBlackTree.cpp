/*
* RedBlackTree.cpp
*
*  Created on: Apr 7, 2015
*      - Author: Kellison
*		- Descri��o:
*			Implementa��o da �rvore rubro-negra com base na classe AVLTree (renomeei para diferencia��o) e
*		TreeNode (ambos usados na implementa��o da �rvore AVL) (alterado ap�s avalia��o da classe e m�todos
*		relacionados a mesma).
*			� m�todo removeNode() realiza o mesmo processo feito na �rvore AVL, com a diferen�a que n�o h�
*		o m�todo verifyBalance() nesta classe, similar a funcionalidade deste, existe o m�todo repairTreeDelete()
*		- Adicionais:
*			Para o bit de cor, temos que red = 0 e black = 1
*
*/

#include <stdio.h>
#include <iostream>
#include "RedBlackTree.h"

using namespace std;

// Inicializa a �rvore
RedBlackTree::RedBlackTree() {
	this->root = NULL;
}

// Inicializa a �rvore
RedBlackTree::RedBlackTree(TreeNode* root) {
	this->root = root;
}

void RedBlackTree::addNode(int key) {
	TreeNode* parent;
	parent = NULL;
	this->addNode(this->root, parent, key);
}

void RedBlackTree::addNode(TreeNode* &node, TreeNode* parent, int key) {
	if (node == NULL) {
		node = new TreeNode(key, parent);

		cout << "Added ... " << node->key << endl;

		// Repara os n�s da �rvore, de acordo com as cores
		this->repairTree(node);

		this->nElements++;
	}
	else {
		if (key < node->key) {
			addNode(node->left, node, key);
		}
		else if (key >= node->key) {
			addNode(node->right, node, key);
		}
	}
}

// Executa a remo��o do n� (retornado por uma busca) a partir do valor da chave
void RedBlackTree::removeNode(int key) {
	TreeNode* node = this->searchNode(key);
	int anterior = node->getColor();
	this->removeNode(node);

	this->repairTreeDelete(node, anterior);
}

void RedBlackTree::removeNode(TreeNode* &node) {
	TreeNode* aux;
	int anterior = node->getColor();

	if (node != NULL) {
		bool leftChildExists = (node->left != NULL);
		bool rightChildExists = (node->right != NULL);

		// Caos n�o possua nenhuma filho, seta os ponteiros filhos do pai como null
		if (!(node->hasChildren())) {
			// Se n�o for a raiz
			if (node->parent != NULL) {
				if (node->key >= node->parent->key)
					(node->parent)->right = NULL;
				else
					(node->parent)->left = NULL;
			}
			else {
				this->root = NULL;
			}

		}
		// Se possuir apenas um �nico filho
		else if (leftChildExists != rightChildExists) {

			if (leftChildExists && !rightChildExists)
				aux = node->left;
			else if (!leftChildExists && rightChildExists)
				aux = node->right;

			// Caso nao seja raiz, realiza a devida atribui��o pai - filho
			if (node->parent != NULL) {
				aux->parent = node->parent;
				if (node->isRightChild())
					(node->parent)->right = aux;
				else
					(node->parent)->left = aux;

				node = aux;
				/*
				delete aux; */
			}
			// Se for raiz, o filho �nico passa a ser a nova raiz
			else {
				aux->parent = NULL;
				this->root = aux;
			}
		}
		// Para o caso em que o n� possui os dois filhos 
		else {
			// Captura o sucessor do n� a ser retirado para sua subsitui��o 
			TreeNode* sucessor = this->getSuccessor(node);

			// Atribui o valor do n� sucessor para o n� a ser retirado, e
			// remove o n� sucessor
			int key = sucessor->key;
			int color = sucessor->getColor();
			this->removeNode(sucessor);
			node->key = key;
			node->color = color;
		}

		this->nElements--;
	}
	else {
		cout << "Nada encontrado" << endl;
	}
}

void RedBlackTree::repairTree(TreeNode* node) {
	TreeNode* grandpa = node->getGrandParent();
	TreeNode* aux = node, *parent = node->parent;

	// Caso 1, o n� � preto
	if (parent->getColor() == BLACK) {
		if (parent == NULL)
			node->color = BLACK;
		return;
	}
	// Caso 2, o n� � vermelho
	else {
		TreeNode* uncle = node->getUncle();

		// Caso 2.1: O n� tio � vermelho. As cores dos n�s (pai, av� e tio) s�o mudades
		// e o m�todo � chamado recursivamente
		if (uncle->getColor() == RED) {
			node->parent->color = BLACK;
			node->changeUncleColor(BLACK);
			node->changeGrandpaColor(RED);
			this->repairTree(grandpa);
		}
		// Caso 2.2: o n� tio � preto
		else {
			// Caso 2.2.1
			if ((node == parent->left) && (parent == grandpa->left)) {
				node->parent->color = BLACK;
				node->changeGrandpaColor(RED);
				this->rotateRight(grandpa);
			}
			// Caso 2.2.2
			else if ((node == parent->left) && (parent == grandpa->right)) {
				node->color = BLACK;
				node->changeGrandpaColor(RED);
				this->rotateRight(parent);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.3
			else if ((node == parent->right) && (parent == grandpa->right)) {
				node->parent->color = BLACK;
				node->changeGrandpaColor(RED);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.4
			else if ((node == parent->right) && (parent == grandpa->left)) {
				node->color = BLACK;
				node->changeGrandpaColor(RED);
				this->rotateLeft(parent);
				this->rotateRight(grandpa);
			}
		}
	}

}

void RedBlackTree::repairTreeDelete(TreeNode* node, int corRemovido) {
	if (node != NULL) {
		// Situa��o 1
		if ((corRemovido == RED) && (node->getColor() == RED)) {
			return;
		}
		else {
			if (corRemovido == BLACK) {
				// Situa��o 2
				if (node->getColor() == RED)
					node->color = BLACK;
				// Situa��o 3
				else if (node->getColor() == BLACK) {
					// Caso 1
					if ((node->getSibling()->getColor() == RED)
						&& (node->parent->getColor() == BLACK)) {
						node->getSibling()->color = BLACK;
						node->parent->color = RED;
						if (node->isLeftChild())
							this->rotateLeft(node->parent);
						else
							this->rotateRight(node->parent);
					}
					if (node->getSibling()->getColor() == BLACK) {
						TreeNode* sibling = node->getSibling();
						// Caso 2a
						if ((node->getSibling()->left->getColor() == BLACK)
							&& (node->getSibling()->right->getColor() == BLACK)) {

							node->getSibling()->color = RED;

							//Caso 2b
							if (node->parent->getColor() == RED)
								node->parent->color = BLACK;
						}
						if ((node->getSibling()->left->getColor() == RED)
							&& (node->getSibling()->right->getColor() == BLACK)) {

							node->getSibling()->color = RED;
							node->getSibling()->left->color = BLACK;
							this->rotateLeft(sibling);
						}
						else {
							node->getSibling()->color =	node->parent->getColor();
							node->parent->color = BLACK;
							node->getSibling()->right->color = BLACK;
							this->rotateLeft(node->parent);
						}

					}
				}
			}
		}
	}
}

// Imprime a �rvore
void RedBlackTree::show(TreeNode *node, int b) {
	if (node == NULL) {
		this->printNode(0, b, 1);
		return;
	}
	this->printNode(node, b, 0);
	this->show(node->right, b + 1);
	this->show(node->left, b + 1);
}

// Imprime o n� junto com a sua cor B(black) ou R (red)
void RedBlackTree::printNode(TreeNode* node, int b, int sep) {
	int i;
	char color = node->getColor() == BLACK ? 'B' : 'R';

	for (i = 0; i < b; i++)
		printf(" . . ");
	if (sep == 0) {
		if ((node->key < 10) && (node->key >= 0))
			printf(" %d (%c)\n", node->key, color);
		else
			printf("%d (%c)\n", node->key, color);
	}
	else
		printf(" * (%c)\n", color);
}

RedBlackTree::~RedBlackTree() {
	cout << "�rvore removida." << endl;
}
