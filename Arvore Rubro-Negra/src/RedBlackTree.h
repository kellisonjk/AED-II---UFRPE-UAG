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
		void removeNode(TreeNode*&);
		void repairNodes(TreeNode*);
		int getColorNode(TreeNode*);
		int blackHeight();
		string colorToString(TreeNode*);
		void show(TreeNode*, int);
		void printNode(TreeNode*, int, int);
		TreeNode* getUncle(TreeNode*);
		TreeNode* getGrandParent(TreeNode*);
		void changeUncleColor(TreeNode*&, int);
		void changeGrandpaColor(TreeNode*&, int);
		virtual ~RedBlackTree();
};

#endif /* REDBLACKTREE_H_ */
