/*
 * Tree.cpp
 *
 *      Author: Kellison
 *      Descrição:
 *      	Classe Tree, uma árvore AVL, com os métodos:
 *			- inserção, procura, mínimo e máximo, exibição da árvore, altura, predecessor, antecessor, 
 *            impressão em ordem crescente, e remoção de um nó (para os 3 casos possíveis)
 *		Status: perto da conclusão
 *		    - Motivo: verificar método de remoção quando o nó possuir 2 filhos (troca de valores + remoção 
 *					  do sucessor  ou trocar ponteiros
 *			- Usar free() ou não é necessário ?
 */

#include "AVLTree.h"
#include "TreeNode.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Inicializa a árvore
AVLTree::AVLTree() {
	this->root = NULL;
}

// Inicializa a árvore
AVLTree::AVLTree(TreeNode* root) {
	this->root = root;
}


void AVLTree::addNode(int key){
	TreeNode* parent;
	parent = NULL;
	this->addNode(this->root, parent, key);
}

void AVLTree::addNode(TreeNode* &node, TreeNode* parent, int key){	
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

// Procura e retorna um nó na árvore
TreeNode* AVLTree::searchNode(int key){
	return this->searchNode(this->root, key);
}

TreeNode* AVLTree::searchNode(TreeNode* node, int key){
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

// Realiza a remo;áo de um nó a partir do resultado da busca pela chave informada
void AVLTree::removeNode(int key){
	TreeNode* node = this->searchNode(key);
	this->removeNode(node);
}

void AVLTree::removeNode(TreeNode* &node){
	TreeNode* temp = node, *aux;
	
	if (node != NULL){
		bool leftChildExists = (node->left != NULL);
		bool rightChildExists = (node->right != NULL);
		bool zeroChild = (node->left == NULL) && (node->right == NULL);

		// Caos náo possua nenhuma filho, seta os ponteiros filhos do pai como null
		if (zeroChild){
			// Se não for a raiz
			if (node->parent != NULL){
				if (node->key >= node->parent->key){
					(node->parent)->right = NULL;
				}
				else{
					(node->parent)->left = NULL;
				}
			}
			else{
				this->root = NULL;
			}
		}
		// Se possuir apenas um único filho
		else if (leftChildExists != rightChildExists){
			// Salva em uma variavel auxiliar o nó filho (esquerda ou direita)
			if (leftChildExists && !rightChildExists)
				aux = node->left;
			else if (!leftChildExists && rightChildExists)
				aux = node->right;

			// Caso nao seja raiz, realiza a devida atribuição pai - filho
			if (node->parent != NULL){
				if (node->key >= node->parent->key){
					aux->parent = node->parent;
					(node->parent)->right = aux;
				}
				else{
					aux->parent = node->parent;
					(node->parent)->left = aux;
				}
			}
			// Se for raiz, o filho único passa a ser a nova raiz
			else{
				aux->parent = NULL;
				this->root = aux;
			}
		}
		// Para o caso em que o nó possui os dois filhos 
		else{
			// Captura o sucessor do nó a ser retirado para sua subsituição 
			TreeNode* sucessor = this->getSuccessor(node); 

			// Atribui o valor do nó sucessor para o nó a ser retirado, e
			// remove o nó sucessor
			int key = sucessor->key;
			this->removeNode(sucessor);
			this->nElements++; // Devido a remoção do sucessor (tiraria 2 elementos do contador)
			node->key = key;

		}

		//free(node);
		this->nElements--;
		this->verifyBalance(temp, "remove");
	}
	else{
		cout << "Nada encontrado" << endl;
	}
}


// Obtem o nó mínimo da árvore
TreeNode* AVLTree::getMinimumNode(){
	return this->getMinimumNode(this->root);
}

TreeNode* AVLTree::getMinimumNode(TreeNode* node){
	while (node->left != NULL)
		node = node->left;

	return node;
}

// Obtem o nó máximo da árvore
TreeNode* AVLTree::getMaximumNode(){
	return this->getMaximumNode(this->root);
}

TreeNode* AVLTree::getMaximumNode(TreeNode* node){
	while (node->right != NULL)
		node = node->right;

	return node;
}

// Retorna o sucessor do nó passado como como parâmetro
TreeNode* AVLTree::getSuccessor(int key){
	return this->getSuccessor(this->searchNode(key));
}

TreeNode* AVLTree::getSuccessor(TreeNode* node){
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

// Retorna o antecessor do nó passado como como parâmetro
TreeNode* AVLTree::getPredecessor(int key){
	return this->getPredecessor(this->searchNode(key));
}

TreeNode* AVLTree::getPredecessor(TreeNode* node){
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

// Imprime a árvore completa a partir da raiz
void AVLTree::printInOrder() {
        printInOrder(this->root);

        cout << endl;
}

// Imprime uma subárvore X a partir de um nó qualquer
void AVLTree::printInOrder(TreeNode* node) {
        if (node != NULL){
			printInOrder(node->left);
			cout << node->key << " " ;
			printInOrder(node->right);
        }
}

// Verifica o valor do fator de balanceamento a partir da raiz
int AVLTree::getBalance(){
	return this->getBalance(this->root);
}

// Verifica o valor do fator de balanceamento a partir de um nó qualquer
int AVLTree::getBalance(TreeNode* node){
	if (node != NULL)
	return getHeight(node->left) - getHeight(node->right);
}

// Calcula a altura da árvore (ou sub-árvore)
int AVLTree::getHeight(TreeNode* node) {
	int left, right;
	if (node == NULL) 
		return -1;

	// Pega o maior entre as alturas da esquerda e direta e soma com 1
	return max(getHeight(node->left), getHeight(node->right)) + 1;
}

// Retorna o valor raíz da árvore
TreeNode* AVLTree::getRoot(){
	return this->root;
}

// Verifica se a sub-arvore necessita ser balanceada,
// caso seja necessario, realiza o balanceamento
void AVLTree::verifyBalance(TreeNode* node, std::string typeOperation){

	if ((node == NULL) || (typeOperation == "stop")){
		return;
	}

	// Caso haja desbalanceamento no nó 
	if ((this->getBalance(node) < -1) || (this->getBalance(node) > 1)){

		// Chama a função responsável por realizar o balanceamento (escolhendo 
		// a rotação esquerda, direita ou duplas
		this->doBalance(node);

		// Caso esse tenha sido um processo de inserção, cancela a verificação
		if (typeOperation == "add")
			this->verifyBalance(node->parent, "stop");
	} 
	else{
		// Continua verificando
		this->verifyBalance(node->parent, "continue");
	}
	
}

// Realiza o balanceamento da árvore
void AVLTree::doBalance(TreeNode* node){
	TreeNode* aux;

	// sub-arvore esquerda é maior que a direita
	if (this->getBalance(node) == -2){
		aux = node->right;
		// Realiza a rotação direita - esquerda
		if (this->getBalance(aux) == 1){
			cout << node->right->key << node->key << endl;
			this->rotateRight(aux);
			cout << node->right->key << node->key << endl;
		}
		this->rotateLeft(node);
	}
	// sub-arvore esquerda é maior que a direita
	else if (this->getBalance(node) == 2){
		aux = node->left;
		// Realiza a rotação esquerda - direita
		if (this->getBalance(aux) == -1){
			this->rotateLeft(aux);
		}
		this->rotateRight(node); 
	}
}

// Realiza a rotação esquerda
void AVLTree::rotateLeft(TreeNode* &node) {
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

	// Atribiui o pai do nó da direita ao nó da esquerda (pai nó da esquerda unsigned)
	if (aux->right != NULL)
		(aux->left)->parent = aux;

	// Caso o nó balanceado seja a raiz, realzia a devida atualização
	if (aux->parent == NULL)
		this->root = aux;

	node = aux;
}

// Realiza a rotação direita
void AVLTree::rotateRight(TreeNode* &node) {
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

	// Atribiui o pai do nó da esquerda ao nó da direita (pai nó da direita unsigned)
	if (aux->left != NULL)
		(aux->right)->parent = aux;
	
	if (aux->parent == NULL)
		this->root = aux;

	node = aux;
}

int AVLTree::getNElements(){
	return this->nElements;
}

// Imprime a árvore
void AVLTree::show(TreeNode *node, int b) {
	if (node == NULL) {
		this->printNode(0, b, 1);
		return;
	}
	this->printNode(node->key, b, 0);
	this->show(node->right, b + 1);
	this->show(node->left, b + 1);
}

void AVLTree::printNode(int key, int b, int sep) {
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


AVLTree::~AVLTree() {
	// TODO Auto-generated destructor stub
}
