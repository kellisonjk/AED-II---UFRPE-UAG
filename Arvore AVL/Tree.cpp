/*
 * Tree.cpp
 *
 *  Created on: Mar 24, 2015
 *      Author: Kellison
 *      Descri��o:
 *      	Implementa��o da classe Tree, uma �rvore AVL, com os m�todos:
 *			- inser��o, procura, m�nimo e m�ximo, exibi��o da �rvore, altura, predecessor, antecessor, 
 *            impress�o em ordem crescente
 *          - Falta implementar: remo��o
 */

#include "Tree.h"
#include "TreeNode.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Inicializa a �rvore
Tree::Tree() {
	this->root = NULL;
}

// Inicializa a �rvore
Tree::Tree(TreeNode* root) {
	this->root = root;
}


void Tree::addNode(int key){
	TreeNode* parent;
	parent = NULL;
	this->addNode(this->root, parent, key);
}

void Tree::addNode(TreeNode* &node, TreeNode* parent, int key){	
	if (node == NULL){
		node = new TreeNode(key, parent);
		cout << "Added ... " << node->key << endl;
		this->nElements++;
		this->verifyBalance(node, "add");
	}
	else{
		if (key < node->key){
			addNode(node->left, node, key);
		}
		else if (key >= node->key){
			addNode(node->right, node, key);
		}
	}
	
}

// Procura e retorna um n� na �rvore
TreeNode* Tree::searchNode(int key){
	return this->searchNode(this->root, key);
}

TreeNode* Tree::searchNode(TreeNode* node, int key){
	if(node != NULL){
		if(node->key == key){
			return node;
		}
		if(key < node->key){
			searchNode(node->left, key);
		}
		else{
			searchNode(node->right, key);
		}
	}
	else{
		return NULL;
	}
}

// Realiza a remo;�o de um n� a partir do resultado da busca pela chave informada
void Tree::removeNode(int key){
	TreeNode* node = this->searchNode(key);
	this->removeNode(node);
}

void Tree::removeNode(TreeNode* &node){
	TreeNode* temp = node, *aux;
	
	if (node != NULL){
		bool leftChildExists = (node->left != NULL);
		bool rightChildExists = (node->right != NULL);
		bool zeroChild = (node->left == NULL) && (node->right == NULL);

		// Caos n�o possua nenhuma filho, seta os ponteiros filhos do pai como null
		if (zeroChild){
			if (node->key > node->parent->key){
				(node->parent)->right = NULL;
			}
			else{
				(node->parent)->left = NULL;
			}
		}
		// Se possuir apenas um �nico filho
		else if (leftChildExists != rightChildExists){
			/*
			Aqui s[o funciona caso o no nao seja a raiz, FIX IT!!!!
			*/

			if (leftChildExists && !rightChildExists)
				aux = node->left;
			else if (!leftChildExists && rightChildExists)
				aux = node->right;

			if (node->key > node->parent->key){
				aux->parent = node->parent;
				(node->parent)->right = aux;
			}
			else{
				aux->parent = node->parent;
				(node->parent)->left = aux;
			}
		}
		// Para o caso em que o n� possui os dois filhos 
		else{

		}

		//free(node);
		this->nElements--;

		this->verifyBalance(temp, "remove");
	}
	else{
		cout << "Nada encontrado" << endl;
	}
}


// Obtem o n� m�nimo da �rvore
TreeNode* Tree::getMinimumNode(){
	return this->getMinimumNode(this->root);
}

TreeNode* Tree::getMinimumNode(TreeNode* node){
	while (node->left != NULL)
		node = node->left;

	return node;
}

// Obtem o n� m�ximo da �rvore
TreeNode* Tree::getMaximumNode(){
	return this->getMaximumNode(this->root);
}

TreeNode* Tree::getMaximumNode(TreeNode* node){
	while (node->right != NULL)
		node = node->right;

	return node;
}

// Retorna o sucessor do n� passado como como par�metro
TreeNode* Tree::getSuccessor(int key){
	TreeNode* node = this->searchNode(key);
	TreeNode* temp;
	if (node != NULL){
		if (node->right != NULL)
			return getMinimumNode(node->right);

		temp = node->parent;

		while ((temp != NULL) && (node == temp->right)){
			node = temp;
			temp = node->parent;
		}
	}
	return temp;
}

// Retorna o antecessor do n� passado como como par�metro
TreeNode* Tree::getPredecessor(int key){
	TreeNode* node = this->searchNode(key);
	TreeNode* temp;

	if (node->left != NULL)
		return getMinimumNode(node->left);

	temp = node->parent;

	while ((temp != NULL) && (node == temp->left)){
      node = temp;
      temp = node->parent;
	}

	return temp;
}

// Imprime a �rvore completa a partir da raiz
void Tree::printInOrder() {
        printInOrder(this->root);

        cout << endl;
}

// Imprime uma sub�rvore X a partir de um n� qualquer
void Tree::printInOrder(TreeNode* node) {
        if (node != NULL){
			printInOrder(node->left);
			cout << node->key << " " ;
			printInOrder(node->right);
        }
}

// Verifica o valor do fator de balanceamento a partir da raiz
int Tree::getBalance(){
	return this->getBalance(this->root);
}

// Verifica o valor do fator de balanceamento a partir de um n� qualquer
int Tree::getBalance(TreeNode* node){
	if (node != NULL)
	return getHeight(node->left) - getHeight(node->right);
}

// Calcula a altura da �rvore (ou sub-�rvore)
int Tree::getHeight(TreeNode* node) {
	int left, right;
	if (node == NULL) 
		return -1;

	// Pega o maior entre as alturas da esquerda e direta e soma com 1
	return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Retorna o valor ra�z da �rvore
TreeNode* Tree::getRoot(){
	return this->root;
}

// Verifica se a sub-arvore necessita ser balanceada,
// caso seja necessario, realiza o balanceamento
void Tree::verifyBalance(TreeNode* node, std::string typeOperation){

	if ((node == NULL) || (typeOperation == "stop")){
		return;
	}

	// Caso haja desbalanceamento no n� 
	if ((this->getBalance(node) < -1) || (this->getBalance(node) > 1)){

		// Chama a fun��o respons�vel por realizar o balanceamento (escolhendo 
		// a rota��o esquerda, direita ou duplas
		this->doBalance(node);

		// Caso esse tenha sido um processo de inser��o, cancela a verifica��o
		if (typeOperation == "add")
			this->verifyBalance(node->parent, "stop");
	} 
	else{
		// Continua verificando
		this->verifyBalance(node->parent, "continue");
	}
	
}

// Realiza o balanceamento da �rvore
void Tree::doBalance(TreeNode* node){
	TreeNode* aux;

	// sub-arvore esquerda � maior que a direita
	if (this->getBalance(node) == -2){
		aux = node->right;
		// Realiza a rota��o direita - esquerda
		if (this->getBalance(aux) == 1){
			cout << node->right->key << node->key << endl;
			this->rotateRight(aux);
			cout << node->right->key << node->key << endl;
		}
		this->rotateLeft(node);
	}
	// sub-arvore esquerda � maior que a direita
	else if (this->getBalance(node) == 2){
		aux = node->left;
		// Realiza a rota��o esquerda - direita
		if (this->getBalance(aux) == -1){
			this->rotateLeft(aux);
		}
		this->rotateRight(node); 
	}
}

// Realiza a rota��o esquerda
void Tree::rotateLeft(TreeNode* &node) {
	TreeNode* aux;
	aux = node->right;
	node->right = aux->left;
	
	// Aponta para o pai correto 
	if (aux->left != NULL) {
		(aux->left)->parent = node;
	}

	if (node->parent != NULL) 
	{
		if ((node->parent)->right == node){
			(node->parent)->right = aux;
		}
		else{
			(node->parent)->left = aux;
		}
	}

	aux->left = node;
	aux->parent = node->parent;
	node->parent = aux;

	// Atribiui o pai do n� da direita ao n� da esquerda (pai n� da esquerda unsigned)
	if (aux->right != NULL)
		(aux->left)->parent = aux;

	// Caso o n� balanceado seja a raiz, realzia a devida atualiza��o
	if (aux->parent == NULL)
		this->root = aux;

	node = aux;
}

// Realiza a rota��o direita
void Tree::rotateRight(TreeNode* &node) {
	TreeNode* aux;
	aux = node->left;
	node->left = aux->right;

	// Aponta para o pai correto 
	if (aux->right != NULL) {
		(aux->right)->parent = node;
	}

	if (node->parent != NULL)
	{
		if ((node->parent)->left == node){
			(node->parent)->left = aux;
		}
		else{
			(node->parent)->right = aux;
		}
	}

	aux->right = node;
	aux->parent = node->parent;
	node->parent = aux; 

	// Atribiui o pai do n� da esquerda ao n� da direita (pai n� da direita unsigned)
	if (aux->left != NULL)
		(aux->right)->parent = aux;
	
	if (aux->parent == NULL)
		this->root = aux;

	node = aux;
}

int Tree::getNElements(){
	return this->nElements;
}

// Imprime a �rvore
void Tree::show(TreeNode *node, int b) {
	if (node == NULL) {
		this->printNode(0, b, 1);
		return;
	}
	this->printNode(node->key, b, 0);
	this->show(node->right, b + 1);
	this->show(node->left, b + 1);
}

void Tree::printNode(int key, int b, int sep) {
	int i;

	for (i = 0; i < b; i++) printf(" . ");
	if (sep == 0){
		if ((key < 10) && (key >= 0))
			printf(" %d\n",key);
		else
			printf("%d\n", key);
	}
	else
			printf(" *\n");
}


Tree::~Tree() {
	// TODO Auto-generated destructor stub
}