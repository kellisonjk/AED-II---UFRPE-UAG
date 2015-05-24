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

#define colorToString(color) ( (color == 0) ? "RED" : "BLACK")

class TreeNode {

public:
	TreeNode();
	TreeNode(int, TreeNode*);
	// Usados para verificar se � n� � filho esquerdo ou direito
	bool isLeftChild();
	bool isRightChild();
	bool hasChildren();

	TreeNode* getUncle();
	TreeNode* getGrandParent();
	TreeNode* getSibling();
	void changeUncleColor(int);
	void changeGrandpaColor(int);
	int getColor();

	virtual ~TreeNode();
	
	int key;
	int color;

	// Ponteiros para os  n�s filhos da esquerda e direita e para o n� pai
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

	const int static red = 1;
	const int static black = 0;

};

#endif /* TREENODE_H_ */
