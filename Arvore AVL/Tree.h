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
		void removeNode(TreeNode*); // Nao implementado ainda
		TreeNode* searchNode(int);
		TreeNode* searchNode(TreeNode*, int);
		TreeNode* getMaximumNode();
		TreeNode* getMinimumNode();
		TreeNode* getMaximumNode(TreeNode*);
		TreeNode* getMinimumNode(TreeNode*);
		TreeNode* getSuccessor(int);
		TreeNode* getPredecessor(int);
		void verifyBalance(TreeNode*, std::string); 
		void doBalance(TreeNode*);
		void printInOrder();
		void printInOrder(TreeNode*);
		void rotateRight(TreeNode*&); 
		void rotateLeft(TreeNode*&); 
		int getBalance();
		int getBalance(TreeNode*);
		int getHeight(TreeNode*);
		TreeNode* getRoot(); 
		void printNode(int, int, int);
		void show(TreeNode*, int);
		virtual ~Tree();
	private:
		TreeNode* root;
		int nElements;


};

#endif /* TREE_H_ */
