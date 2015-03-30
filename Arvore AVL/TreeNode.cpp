/*
 * TreeNode.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descri��o:
 *      	Implementa��o da classe TreeNode
 */

#include "TreeNode.h"
#include <cstdlib>
using namespace std;

// Inicializa um novo n� ligando-o ao n� pai,
// no caso do n� raiz, o valor para "father" dever� ser nulo
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

