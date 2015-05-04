/*
 * RedBlackTree.h
 *
 *  Created on: Apr 7, 2015
 *      Author: Kellison
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

#include "../base/AVLTree.h"
#include <iostream>
#include <string>

using namespace std;

class RedBlackTree: public AVLTree {
	public:
		RedBlackTree();
		RedBlackTree(TreeNode*);
		void addNode(TreeNode*&, TreeNode*, int);
		void addNode(int);
		void removeNode(int key);
		void removeNode(TreeNode*&);
		int blackHeight(); // Nao implementado
		void show(TreeNode*, int);
		void printNode(TreeNode*, int, int);
		virtual ~RedBlackTree();
	private:
		void repairTree(TreeNode*);
		void repairTreeDelete(TreeNode*, int); // Nao implementado
};

#endif /* REDBLACKTREE_H_ */
