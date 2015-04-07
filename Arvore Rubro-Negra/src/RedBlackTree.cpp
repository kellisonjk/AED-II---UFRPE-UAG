/*
 * RedBlackTree.cpp
 *
 *  Created on: Apr 7, 2015
 *      Author: Kellison
 */

#include "RedBlackTree.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

// Inicializa a árvore
RedBlackTree::RedBlackTree() {
	this->root = NULL;
}

// Inicializa a árvore
RedBlackTree::RedBlackTree(TreeNode* root) {
	this->root = root;
}

void RedBlackTree::addNode(TreeNode* &node, TreeNode* parent, int key){
	if (node == NULL){
		node = new TreeNode(key, parent);
		cout << "Added ... " << node->key << endl;
		this->nElements++;
		this->verifyBalance(node, "add");
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

RedBlackTree::~RedBlackTree() {
	// TODO Auto-generated destructor stub
}

