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

class TreeNode {

	public:
		TreeNode();
		TreeNode(int);
		TreeNode(int, TreeNode*);
		virtual ~TreeNode();
		int key;

		// Fator de balanceamento do n� (altura sub-�rvore esquerda - direita) [-1, 1, 0]
		int balanceFactor;

		// Ponteiros para os  n�s filhos da esquerda e direita e para o n� pai
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;

};

#endif /* TREENODE_H_ */
