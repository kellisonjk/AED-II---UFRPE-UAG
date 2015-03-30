/*
 * TreeNode.h
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Description:
 *      	Classe equivalente à um nó da árvore, possuindo os ponteiros para
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

		// Fator de balanceamento do nó (altura sub-árvore esquerda - direita) [-1, 1, 0]
		int balanceFactor;

		// Ponteiros para os  nós filhos da esquerda e direita e para o nó pai
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;

};

#endif /* TREENODE_H_ */
