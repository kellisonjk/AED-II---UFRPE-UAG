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

#define RED 0
#define BLACK 1
#define colorToString(color) ( (color == 0) ? "RED" : "BLACK")

class TreeNode {

public:
	TreeNode();
	TreeNode(int, TreeNode*);
	// Usados para verificar se ó nó é filho esquerdo ou direito
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
	int color = RED;

	// Ponteiros para os  nós filhos da esquerda e direita e para o nó pai
	TreeNode* left;
	TreeNode* right;
	TreeNode* parent;

};

#endif /* TREENODE_H_ */
