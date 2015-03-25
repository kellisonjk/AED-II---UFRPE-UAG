/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descrição:
 *      	Implementação da classe TreeNode
 */

#include "TreeNode.h"

// Inicializa um novo nó ligando-o ao nó pai,
// no caso do nó raiz, o valor para "father" deverá ser nulo
TreeNode::TreeNode(int key, int value, TreeNode parent) {
	this->key = key;
	this->value = value;
	this->parent = parent;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::~TreeNode() {

}

