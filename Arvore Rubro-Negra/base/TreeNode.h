/*
 * TreeNode.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Description:
 *      	Classe equivalente � um n� da �rvore, possuindo os ponteiros para
 *      	os filhos e para o pai.
 */

#ifndef TREENODE_H_
#define TREENODE_H_

#define RED 0
#define BLACK 1

class TreeNode {

public:
	TreeNode();
	TreeNode(int, TreeNode*);
		virtual ~TreeNode();
		int key;

		// Ponteiros para os  n�s filhos da esquerda e direita e para o n� pai
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;
		int color = RED;

};

#endif /* TREENODE_H_ */
