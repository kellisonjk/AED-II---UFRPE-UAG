/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descri��o:
 *      	Implementa��o da classe TreeNode
 *
 *			Diferentemente da classe node usada para a �rvore AVL, esta clase possui
 *			alguns m�todos para manipula��o do n� (getUncle, changeGrandpaColor, etc)
 */

#include "TreeNode.h"
#include <iostream>
using namespace std;

// Inicializa um novo n� ligando-o ao n� pai,
// no caso do n� raiz, o valor para "father" dever� ser nulo

TreeNode::TreeNode() {

}
TreeNode::TreeNode(int key, TreeNode* parent) {
	this->key = key;
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
	this->color = RED;
}

// Verifica se o n� � o filho esquerdo de seu pai (caso exista)
bool TreeNode::isLeftChild(){
	if (this->parent != NULL)
		if ((this->parent)->left == this)
			return true;

	return false;
}

// Verifica se o n� � o filho direito de seu pai (caso exista)
bool TreeNode::isRightChild(){
	if (this->parent != NULL)
		if ((this->parent)->right == this)
			return true;

	return false;
}

// Retorna o "av�" do n� 
TreeNode* TreeNode::getGrandParent(){
	if ((this != NULL) && (this->parent != NULL))
		return (this->parent)->parent;

	return NULL;
}

// Retorna o "tio" do n�
TreeNode* TreeNode::getUncle(){
	TreeNode* grandpa = this->getGrandParent();

	// Caso exista um av�,
	if (grandpa != NULL){
		if (grandpa->left == this->parent)
			return grandpa->right;
		else
			return grandpa->left;
	}

	// Se n�o existe um av�, ent�o tamb�m n�o existe um tio par ao n�
	return NULL;
}

// Retorna o "irm�o" do n�
TreeNode* TreeNode::getSibling(){
	TreeNode* parent = this->parent;

	// Caso exista um pai,
	if (parent != NULL){
		if (parent->left == this)
			return parent->right;
		else
			return parent->left;
	}

	// Se n�o existe um pai, ent�o tamb�m n�o existe um irm�o para o n�
	return NULL;
}

// Muda a cor do n� "tio"
void TreeNode::changeUncleColor(int color){
	TreeNode* grandpa = this->getGrandParent();

	// Caso exista um av� e um tio
	if ((grandpa != NULL) && (this->getUncle() != NULL)){
		if (grandpa->left == this->parent)
			((this->parent)->parent)->right->color = color;
		else
			((this->parent)->parent)->left->color = color;
	}
}

// Muda a cor do n� "av�", caso exista
void TreeNode::changeGrandpaColor(int color){
	if (this->getGrandParent() != NULL)
		((this->parent)->parent)->color = color;
}

// Retorna a cor do n�. Caso seja um n� nulo, retorna BLACK (1), caso contr�rio
// retorna a cor salva no n� passado como par�metro
int TreeNode::getColor(){
	if (this == NULL){
		return BLACK;
	}
	else{
		return this->color;
	}
}

// Verifica se o n� possui filhos
bool TreeNode::hasChildren(){
	if ((this->left != NULL) || (this->right != NULL))
		return true;

	return false;
}

// Destrutor da classe
TreeNode::~TreeNode() {
	cout << "No removido." << endl;
}