/*
 * Tree.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 */

#include "Tree.h"
#include "TreeNode.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Inicializa a �rvore
Tree::Tree() {
	this->root = NULL;
}

// Inicializa a �rvore
Tree::Tree(TreeNode* root) {
	this->root = root;
}


void Tree::addNode(int key){
	this->addNode(this->root, NULL, key);
}

void Tree::addNode(TreeNode* &node, TreeNode* parent, int key){
	if (node == NULL){
		if (parent == NULL)
			node = this->root;
		node = new TreeNode(key, parent); 
		cout << "Added ... " << node->key << endl;
	}
	else{
		if (key <= node->key)
			addNode(node->left, node, key);
		else
			addNode(node->right, node, key);
	}

}

// Procura e retorna um n� na �rvore
TreeNode* Tree::searchNode(int key){
	return this->searchNode(this->root, key);
}

TreeNode* Tree::searchNode(TreeNode* node, int key){
	if(node != NULL){
		if(node->key == key){
			//cout << " " << node->key << " ";
			return node;
		}
		if(key < node->key){
			//cout << " " << node->key << " ";
			searchNode(node->left, key);
		}
		else{
			//cout << " " << node->key << " ";
			searchNode(node->right, key);
		}
	}
	else{
		return NULL;
	}
}


// Obtem o n� m�nimo da �rvore
TreeNode* Tree::getMinimumNode(){
	return this->getMinimumNode(this->root);
}

TreeNode* Tree::getMinimumNode(TreeNode* node){
	while (node->left != NULL)
		node = node->left;

	return node;
}

// Obtem o n� m�ximo da �rvore
TreeNode* Tree::getMaximumNode(){
	return this->getMaximumNode(this->root);
}

TreeNode* Tree::getMaximumNode(TreeNode* node){
	while (node->right != NULL)
		node = node->right;

	return node;
}

// Retorna o sucessor do n� passado como como par�metro
TreeNode* Tree::getSuccessor(int key){
	TreeNode* node = this->searchNode(key);
	TreeNode* temp;

	if (node->right != NULL)
		return getMinimumNode(node->right);

	temp = node->parent;

	while ((temp != NULL) && (node == temp->right)){
      node = temp;
      temp = node->parent;
	}

	return temp;
}

// Retorna o antecessor do n� passado como como par�metro
TreeNode* Tree::getPredecessor(int key){
	TreeNode* node = this->searchNode(key);
	TreeNode* temp;

	if (node->left != NULL)
		return getMinimumNode(node->left);

	temp = node->parent;

	while ((temp != NULL) && (node == temp->left)){
      node = temp;
      temp = node->parent;
	}

	return temp;
}

// Imprime a �rvore completa a partir da raiz
void Tree::printInOrder() {
        printInOrder(this->root);

        cout << endl;
}

// Imprime uma sub�rvore X a partir de um n� qualquer
void Tree::printInOrder(TreeNode* node) {
        if (node != NULL){
			printInOrder(node->left);
			cout << node->key << " " ;
			printInOrder(node->right);
        }

}

// Atualiza o fato de balanceamento de cada n� da �rvore
void Tree::updateBalanceFactor(TreeNode* node){
	if (node != NULL){
		node->balanceFactor = this->getBalance(node);
		updateBalanceFactor(node->left);
		updateBalanceFactor(node->right);
	}
}

int Tree::getBalance(){
	return this->getBalance(this->root);
}

int Tree::getBalance(TreeNode* node){
	return getHeight(node->left) - getHeight(node->right);
}

// Calcula a altura da �rvore (ou sub-�rvore)
int Tree::getHeight(TreeNode* node) {

	int left, right;

	if (node == NULL) 
		return -1;

	left = getHeight(node->left);
	right = getHeight(node->right);

	if (left > right) 
		return left + 1;
	else 
		return right + 1;
}

// Retorna o valor ra�z da �rvore
TreeNode* Tree::getRoot(){
	return this->root;
}

// Verifica se a sub-�rvore necessita ser balanceada,
// caso seja necess�rio, realiza o balanceamento
void Tree::verifyBalance(TreeNode* node){
		if (node->balanceFactor == -2){
			if ((node->left != NULL) && (node->left->balanceFactor == -1))
				this->rotateRight(node->right);
			this->rotateLeft(node);
		}
		else if (node->balanceFactor == 2){
			if ((node->right != NULL) && (node->right->balanceFactor == 1))
				this->rotateLeft(node->left);
			this->rotateRight(node);
		}

}

void Tree::rotateLeft(TreeNode* node){
	TreeNode* temp = node;
	TreeNode* aux = temp->right;
	temp->right = aux->left;
	aux->left = temp;
	node = aux;
	this->updateBalanceFactor(temp);
	this->updateBalanceFactor(aux);
}

void Tree::rotateRight(TreeNode* node){
	TreeNode* temp = node;
	TreeNode* aux = temp->left;
	temp->left = aux->right;
	aux->right = temp;
	node = aux;
	this->updateBalanceFactor(temp);
	this->updateBalanceFactor(aux);
}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}



void Tree::show(TreeNode *x, int b) {
	if (x == NULL) {
		printnode(0, b, 1);
		return;
	}
	printnode(x->key, b, 0);
	show(x->right, b + 1);
	show(x->left, b + 1);
}

void Tree::printnode(int c, int b, int sep) {
	int i;
	for (i = 0; i < b; i++) printf(" - ");
		if (sep == 0)
			printf("%d\n", c);
		else
			printf("*\n", c);
}