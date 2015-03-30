/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descrição:
 *      	Implementação da classe TreeNode
 */

#include "TreeNode.h"
#include <cstdlib>
using namespace std;

// Inicializa um novo nó ligando-o ao nó pai,
// no caso do nó raiz, o valor para "father" deverá ser nulo
TreeNode::TreeNode(int key) {
	this->key = key;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
	this->balanceFactor = 0;
}

TreeNode::TreeNode(int key, TreeNode* parent) {
	this->key = key;
	this->parent = parent;
	this->left = NULL;
	this->right = NULL;
	this->balanceFactor = 0;
}

TreeNode::TreeNode() {
	this->key = NULL;
	this->parent = NULL;
	this->left = NULL;
	this->right = NULL;
	this->balanceFactor = 0;
}

TreeNode::~TreeNode() {

}

