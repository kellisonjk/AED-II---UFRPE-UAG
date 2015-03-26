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
Tree::Tree(TreeNode *root) {
	this->root = root;
}

// Adiciona um novo n� � �rvore
void Tree::AddNode(TreeNode *node){
	TreeNode *temp = this->root;
	TreeNode *ant = NULL;

	while (temp != NULL){
		ant = temp;

		if (node->key < temp->key)
			temp = temp->left;
		else
			temp = temp->right;
	}

	node->parent = ant;

	if(ant == NULL){
		this->root = node;
		cout << "Added ... " << node->key << endl;
	}
	else{
		if (node->key < ant->key){
			ant->left = node;
		}
		else{
			ant->right = node;
		}

		cout << "Added ... " << node->key << endl;
	}
}

// Procura e retorna um n� na �rvore
TreeNode* Tree::SearchNode(TreeNode *node, int key){
	if(node != NULL){
		if(node->key == key){
			cout << " " << node->key << " ";
			return node;
		}
		if(key < node->key){
			cout << " " << node->key << " ";
			SearchNode(node->left, key);
		}
		else{
			cout << " " << node->key << " ";
			SearchNode(node->right, key);
		}
	}
	else{
		return NULL;
	}
}

// Remove um n� da �rvore atrav�s da chave passada como par�metro
void Tree::RemoveNode(TreeNode *node){

}

// Obtem o n� m�nimo da �rvore
TreeNode* Tree::MinimumNode(TreeNode *node){
	while (node->left != NULL)
		node = node->left;

	return node;
}

// Obtem o n� m�ximo da �rvore
TreeNode* Tree::MaximumNode(TreeNode *node){
	while (node->right != NULL)
		node = node->right;

	return node;
}

// Retorna o sucessor do n� passado como como par�metro
TreeNode* Tree::Successor(TreeNode *node){
	TreeNode *temp;

	if (node->right != NULL)
		return MinimumNode(node->right);

	temp = node->parent;

	while ((temp != NULL) && (node == temp->right)){
      node = temp;
      temp = node->parent;
	}

	return temp;
}

// Retorna o antecessor do n� passado como como par�metro
TreeNode* Tree::Predecessor(TreeNode *node){
	TreeNode *temp;

	if (node->left != NULL)
		return MinimumNode(node->left);

	temp = node->parent;

	while ((temp != NULL) && (node == temp->left)){
      node = temp;
      temp = node->parent;
	}

	return temp;
}

// Imprime a �rvore completa a partir da raiz
void Tree::PrintInOrder() {
        PrintInOrder(this->root);

        cout << endl;
}

// Imprime uma sub�rvore X a partir de um n� qualquer
void Tree::PrintInOrder(TreeNode *node) {
        if (node != NULL){
			PrintInOrder(node->left);
			cout << node->key << " " ;
			PrintInOrder(node->right);
        }

}

// Retorna o valor ra�z da �rvore
int Tree::Root(){
	return this->root->key;
}

Tree::~Tree() {
	// TODO Auto-generated destructor stub
}

