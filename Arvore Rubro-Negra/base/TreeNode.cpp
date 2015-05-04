/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descrição:
 *      	Implementação da classe TreeNode
 *
 *			Diferentemente da classe node usada para a árvore AVL, esta clase possui
 *			alguns métodos para manipulação do nó (getUncle, changeGrandpaColor, etc)
 */

#include "TreeNode.h"
#include <iostream>
using namespace std;

// Inicializa um novo nó ligando-o ao nó pai,
// no caso do nó raiz, o valor para "father" deverá ser nulo

TreeNode::TreeNode() {

}
TreeNode::TreeNode(int key, TreeNode* parent) {
	this->key = key;
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
	this->color = RED;
}

// Verifica se o nó é o filho esquerdo de seu pai (caso exista)
bool TreeNode::isLeftChild(){
	if (this->parent != NULL)
		if ((this->parent)->left == this)
			return true;

	return false;
}

// Verifica se o nó é o filho direito de seu pai (caso exista)
bool TreeNode::isRightChild(){
	if (this->parent != NULL)
		if ((this->parent)->right == this)
			return true;

	return false;
}

// Retorna o "avô" do nó 
TreeNode* TreeNode::getGrandParent(){
	if ((this != NULL) && (this->parent != NULL))
		return (this->parent)->parent;

	return NULL;
}

// Retorna o "tio" do nó
TreeNode* TreeNode::getUncle(){
	TreeNode* grandpa = this->getGrandParent();

	// Caso exista um avô,
	if (grandpa != NULL){
		if (grandpa->left == this->parent)
			return grandpa->right;
		else
			return grandpa->left;
	}

	// Se não existe um avô, então também não existe um tio par ao nó
	return NULL;
}

// Retorna o "irmão" do nó
TreeNode* TreeNode::getSibling(){
	TreeNode* parent = this->parent;

	// Caso exista um pai,
	if (parent != NULL){
		if (parent->left == this)
			return parent->right;
		else
			return parent->left;
	}

	// Se não existe um pai, então também não existe um irmão para o nó
	return NULL;
}

// Muda a cor do nó "tio"
void TreeNode::changeUncleColor(int color){
	TreeNode* grandpa = this->getGrandParent();

	// Caso exista um avô e um tio
	if ((grandpa != NULL) && (this->getUncle() != NULL)){
		if (grandpa->left == this->parent)
			((this->parent)->parent)->right->color = color;
		else
			((this->parent)->parent)->left->color = color;
	}
}

// Muda a cor do nó "avô", caso exista
void TreeNode::changeGrandpaColor(int color){
	if (this->getGrandParent() != NULL)
		((this->parent)->parent)->color = color;
}

// Retorna a cor do nó. Caso seja um nó nulo, retorna BLACK (1), caso contrário
// retorna a cor salva no nó passado como parâmetro
int TreeNode::getColor(){
	if (this == NULL){
		return BLACK;
	}
	else{
		return this->color;
	}
}

// Verifica se o nó possui filhos
bool TreeNode::hasChildren(){
	if ((this->left != NULL) || (this->right != NULL))
		return true;

	return false;
}

// Destrutor da classe
TreeNode::~TreeNode() {
	cout << "No removido." << endl;
}