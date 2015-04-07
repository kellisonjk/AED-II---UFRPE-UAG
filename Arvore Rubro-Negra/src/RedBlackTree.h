/*
 * RedBlackTree.h
 *
 *  Created on: Apr 7, 2015
 *      Author: Kellison
 */

#ifndef REDBLACKTREE_H_
#define REDBLACKTREE_H_

class RedBlackTree: public AVLTree {
public:
	RedBlackTree();
	RedBlackTree();
	RedBlackTree(TreeNode*);
	void addNode(TreeNode*&, TreeNode*, int);
	void addNode(int);
	void removeNode(TreeNode*&);
	virtual ~RedBlackTree();
};

#endif /* REDBLACKTREE_H_ */
