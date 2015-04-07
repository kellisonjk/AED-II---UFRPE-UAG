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
		TreeNode(int, TreeNode*);
		virtual ~TreeNode();
		int key;

		// Ponteiros para os  nós filhos da esquerda e direita e para o nó pai
		TreeNode *left;
		TreeNode *right;
		TreeNode *parent;
		enum Color {red, black};
		Color color;

};

#endif /* TREENODE_H_ */
