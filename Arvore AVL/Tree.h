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
		Tree(TreeNode root);
		void AddNode(int key, int value);
		void RemoveNode(int key);
		TreeNode SearchNode(int key);

		virtual ~Tree();
	private:
		TreeNode root;
		int height;


};

#endif /* TREE_H_ */
