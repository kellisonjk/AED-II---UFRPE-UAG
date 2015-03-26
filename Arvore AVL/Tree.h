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
		void AddNode(TreeNode*);
		void RemoveNode(TreeNode*);
		TreeNode* SearchNode(TreeNode*, int);
		TreeNode* MaximumNode(TreeNode*);
		TreeNode* MinimumNode(TreeNode*);
		TreeNode* Successor(TreeNode*);
		TreeNode* Predecessor(TreeNode*);
		void PrintInOrder();
		void PrintInOrder(TreeNode*);
		int Root();
		virtual ~Tree();
	private:
		TreeNode *root;
		int height;


};

#endif /* TREE_H_ */
