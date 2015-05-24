/*
 * Tree.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 */

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include "TreeNode.h"
#include <string>

class AVLTree {
	public:
		AVLTree();
		AVLTree(TreeNode*);
		void addNode(int);
		void addNode(TreeNode*&, TreeNode*, int);
		void removeNode(int);
		void removeNode(TreeNode*&);
		TreeNode* searchNode(int);
		TreeNode* searchNode(TreeNode*, int);
		TreeNode* getMaximumNode();
		TreeNode* getMinimumNode();
		TreeNode* getMaximumNode(TreeNode*);
		TreeNode* getMinimumNode(TreeNode*);
		TreeNode* getSuccessor(int);
		TreeNode* getSuccessor(TreeNode*);
		TreeNode* getPredecessor(int);
		TreeNode* getPredecessor(TreeNode*);
		void printInOrder();
		void printInOrder(TreeNode*); 
		int getBalance();
		int getBalance(TreeNode*);
		int getHeight(TreeNode*);
		TreeNode* getRoot(); 
		int getNElements();
		void printNode(int, int, int);
		void show(TreeNode*, int);
		virtual ~AVLTree();
	protected:
		void verifyBalance(TreeNode*, std::string);
		void doBalance(TreeNode*);
		void rotateRight(TreeNode*&);
		void rotateLeft(TreeNode*&);
		TreeNode* root;
		int nElements; // Número de elementos da árvore


};

#endif /* AVLTREE_H_ */
