/*
 * Tree.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 */

#ifndef TREE_H_
#define TREE_H_

#include "TreeNode.h"
#include <string>

class Tree {
	public:
		Tree();
		Tree(TreeNode*);
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
		virtual ~Tree();
	private:
		void verifyBalance(TreeNode*, std::string);
		void doBalance(TreeNode*);
		void rotateRight(TreeNode*&);
		void rotateLeft(TreeNode*&);
		TreeNode* root;
		int nElements = 0; // Número de elementos da árvore


};

#endif /* TREE_H_ */
