/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descri��o:
 *      	Implementa��o da classe TreeNode
 */

#include "TreeNode.h"

// Inicializa um novo n� ligando-o ao n� pai,
// no caso do n� raiz, o valor para "father" dever� ser nulo
TreeNode::TreeNode(int key, int value, TreeNode parent) {
	this->key = key;
	this->value = value;
	this->parent = parent;
	this->left = nullptr;
	this->right = nullptr;
}

TreeNode::~TreeNode() {

}

