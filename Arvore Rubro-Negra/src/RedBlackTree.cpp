/*
* RedBlackTree.cpp
*
*  Created on: Apr 7, 2015
*      - Author: Kellison
*		- Descri��o:
*			Implementa��o da �rvore rubro-negra com base na classe AVLTree (renomeei para diferencia��o) e
*		TreeNode (ambos usados na implementa��o da �rvore AVL) (alterado ap�s avalia��o da classe e m�todos
*		relacionados a mesma).
*		- Adicionais:
*			Para o bit de cor, temos que red = 0 e black = 1
*			
*		(Segundo o que foi dito em sala, o algoritmo de remo��o n�o ser� necess�rio para esta implementa��o.)
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

void RedBlackTree::repairTree(TreeNode* node) {
	TreeNode* grandpa = node->getGrandParent();
	TreeNode* aux = node, *parent = node->parent;

	// Caso 1, o n� � preto
	if (parent->getColor() == TreeNode::black) {
		if (parent == NULL)
			node->color = TreeNode::black;
		return;
	}
	// Caso 2, o n� � vermelho
	else {
		TreeNode* uncle = node->getUncle();

		// Caso 2.1: O n� tio � vermelho. As cores dos n�s (pai, av� e tio) s�o mudades
		// e o m�todo � chamado recursivamente
		if (uncle->getColor() == TreeNode::red) {
			node->parent->color = TreeNode::black;
			node->changeUncleColor(TreeNode::black);
			node->changeGrandpaColor(TreeNode::red);
			this->repairTree(grandpa);
		}
		// Caso 2.2: o n� tio � preto
		else {
			// Caso 2.2.1
			if ((node == parent->left) && (parent == grandpa->left)) {
				node->parent->color = TreeNode::black;
				node->changeGrandpaColor(TreeNode::red);
				this->rotateRight(grandpa);
			}
			// Caso 2.2.2
			else if ((node == parent->left) && (parent == grandpa->right)) {
				node->color = TreeNode::black;
				node->changeGrandpaColor(TreeNode::red);
				this->rotateRight(parent);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.3
			else if ((node == parent->right) && (parent == grandpa->right)) {
				node->parent->color = TreeNode::black;
				node->changeGrandpaColor(TreeNode::red);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.4
			else if ((node == parent->right) && (parent == grandpa->left)) {
				node->color = TreeNode::black;
				node->changeGrandpaColor(TreeNode::red);
				this->rotateLeft(parent);
				this->rotateRight(grandpa);
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

// Imprime o n� junto com a sua cor black ou red
void RedBlackTree::printNode(TreeNode* node, int b, int sep) {
	int i; 
	char color = node->getColor() == TreeNode::black ? 'B' : 'R';

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
}