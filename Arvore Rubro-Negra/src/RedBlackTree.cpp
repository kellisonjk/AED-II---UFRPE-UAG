/*
 * RedBlackTree.cpp
 *
 *  Created on: Apr 7, 2015
 *      - Author: Kellison
 *		- Descrição:
 *			Implementação da árvore rubro-negra com base na classe AVLTree (renomeei para diferenciação) e 
 *		TreeNode (ambos usados na implementação da árvore AVL).
 *		- Adicionais:
 *			Para o bit de cor, temos que red == 0 e black = 1
 *
 *		- Observação: 
 *			Problema após as rotações duplas. O ponteiro "node" é setado como nulo, impossibilitando
 *		referenciá-lo de nenhum modo.
 */

#include <stdio.h>
#include "RedBlackTree.h"

using namespace std;


// Inicializa a árvore
RedBlackTree::RedBlackTree() {
	this->root = NULL;
}

// Inicializa a árvore
RedBlackTree::RedBlackTree(TreeNode* root) {
	this->root = root;
}

void RedBlackTree::addNode(int key){
	TreeNode* parent;
	parent = NULL;
	this->addNode(this->root, parent, key);
}

void RedBlackTree::addNode(TreeNode* &node, TreeNode* parent, int key){
	if (node == NULL){
		node = new TreeNode(key, parent);

		cout << "Added ... " << node->key << endl;

		// Repara os nós da árvore, de acordo com as cores
		this->repairNodes(node);

		this->nElements++;		
	}
	else{
		if (key < node->key){
			addNode(node->left, node, key);
		}
		else if (key >= node->key){
			addNode(node->right, node, key);
		}
	}
}

void RedBlackTree::repairNodes(TreeNode* node){
	TreeNode* grandpa = this->getGrandParent(node);
	TreeNode* aux = node, *parent = node->parent;

	// Caso 1, o nó é preto
	if (this->getColorNode(parent) == BLACK){
		if (parent == NULL)
			node->color = BLACK;
		return;
	}
	// Caso 2, o nó é vermelho
	else{
		TreeNode* uncle = this->getUncle(node);

		// Caso 2.1: O nó tio é vermelho. As cores dos nós (pai, avô e tio) são mudades
		// e o método é chamado recursivamente
		if (this->getColorNode(uncle) == RED){
			node->parent->color = BLACK;
			this->changeUncleColor(node, BLACK);
			this->changeGrandpaColor(node, RED);
			this->repairNodes(grandpa);
		}
		// Caso 2.2: o nó tio é preto
		else{
			// Caso 2.2.1
			if ((node == parent->left) && (parent == grandpa->left)){
				node->parent->color = BLACK;
				this->changeGrandpaColor(node, RED);
				this->rotateRight(grandpa);
			}
			// Caso 2.2.2
			else if ((node == parent->left) && (parent == grandpa->right)){
				node->color = BLACK;
				this->changeGrandpaColor(node, RED);
				this->rotateRight(parent);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.3
			else if ((node == parent->right) && (parent == grandpa->right)){
				node->parent->color = BLACK;
				this->changeGrandpaColor(node, RED);
				this->rotateLeft(grandpa);
			}
			// Caso 2.2.4
			else if ((node == parent->right) && (parent == grandpa->left)){
				node->color = BLACK;
				this->changeGrandpaColor(node, RED);
				this->rotateLeft(parent);
				this->rotateRight(grandpa);
			}
		}
	}
	
}

// Retorna o "avô" do nó passado por parâmetro
TreeNode* RedBlackTree::getGrandParent(TreeNode* node){
	if ((node != NULL) && (node->parent != NULL) )
		return (node->parent)->parent;

	return NULL;
}

// Retorna o "tio" do nó passado por parâmetro
TreeNode* RedBlackTree::getUncle(TreeNode* node){
	TreeNode* grandpa = this->getGrandParent(node);
	
	// Caso exista um avô,
	if (grandpa != NULL){
		if (grandpa->left == node->parent)
			return grandpa->right;
		else
			return grandpa->left;
	}

	// Se não existe um avô, então também não existe um tio par ao nó
	return NULL;
}

// Retorna a cor do nó. Caso seja um nó nulo, retorna BLACK (1), caso contrário
// retorna a cor salva no nó passado como parâmetro
int RedBlackTree::getColorNode(TreeNode* node){
	if (node == NULL){
		return BLACK;
	}
	else{
		return node->color;
	}
}

// Muda a cor do nó "tio"
void RedBlackTree::changeUncleColor(TreeNode* &node, int color){
	TreeNode* grandpa = this->getGrandParent(node);

	// Caso exista um avô e um tio
	if ( (grandpa != NULL) && (this->getUncle(node)!=NULL)){
		if (grandpa->left == node->parent)
			((node->parent)->parent)->right->color = color;
		else
			((node->parent)->parent)->left->color = color;
	}

}

// Muda a cor do nó "avô", caso exista
void RedBlackTree::changeGrandpaColor(TreeNode*& node, int color){
	if (this->getGrandParent(node) != NULL)
		((node->parent)->parent)->color = color;
}

// Imprime a árvore
void RedBlackTree::show(TreeNode *node, int b) {
	if (node == NULL) {
		this->printNode(0, b, 1);
		return;
	}
	this->printNode(node, b, 0);
	this->show(node->right, b + 1);
	this->show(node->left, b + 1);
}

// Imprime o nó junto com a sua cor B(black) ou R (red)
void RedBlackTree::printNode(TreeNode* node, int b, int sep) {
	int i;
	char color = this->getColorNode(node) == BLACK ? 'B' : 'R';

	for (i = 0; i < b; i++) printf(" . . ");
	if (sep == 0){
		if ((node->key < 10) && (node->key >= 0))
			printf(" %d (%c)\n", node->key, color);
		else
			printf("%d (%c)\n", node->key, color);
	}
	else
		printf(" * (%c)\n", color);
}

string RedBlackTree::colorToString(TreeNode* node){
	return this->getColorNode(node) == BLACK ? "Black" : "Red";
}

RedBlackTree::~RedBlackTree() {
	// TODO Auto-generated destructor stub
}

