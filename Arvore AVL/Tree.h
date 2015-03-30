/*
 * Tree.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 */

#ifndef TREE_H_
#define TREE_H_

#include "TreeNode.h"

class Tree {
	public:
		Tree();
		Tree(TreeNode*);
		void addNode(int);
		void addNode(TreeNode* &node, TreeNode*, int);
		void removeNode(TreeNode*); // Nao implementado
		TreeNode* searchNode(int);
		TreeNode* searchNode(TreeNode*, int);
		TreeNode* getMaximumNode();
		TreeNode* getMinimumNode();
		TreeNode* getMaximumNode(TreeNode*);
		TreeNode* getMinimumNode(TreeNode*);
		TreeNode* getSuccessor(int);
		TreeNode* getPredecessor(int);
		void updateBalanceFactor(TreeNode*);
		void printInOrder();
		void printInOrder(TreeNode*);
		void rotateRight(TreeNode*); // Ainda nao funcinal
		void rotateLeft(TreeNode*); // Ainda nao funcinal
		int getBalance();
		int getBalance(TreeNode*);
		int getHeight(TreeNode*);
		TreeNode* getRoot(); 
		void printnode(int, int, int);
		void show(TreeNode*, int);
		void verifyBalance(TreeNode*); // Ainda nao funcinal
		virtual ~Tree();
	private:
		TreeNode* root;
		int nElements;


};

#endif /* TREE_H_ */
