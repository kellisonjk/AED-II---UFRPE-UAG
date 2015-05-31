/*
* Main.cpp
*
*      Author: Kellison
*		Implementaзгo da classe Graph
*/

#include <iostream>
#include <stdio.h>
#include "Graph.hpp" 

using namespace std;

int main() {
	char op;
	vector<int> a;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	Graph<int> g("new",a);


	printf("\n %c%c%c%c%c%c%c Trabalhando com Grafos %c%c%c%c%c%c%c \n\n", 
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

	g.showAllVertex();

	cout << endl << " Matriz de Adjacencias (com custos): " << endl << endl;

	g.setEdge(5, 1, 3);
	g.setEdge(1, 3, 5);
	g.setEdge(1, 2, 2);
	g.setEdge(2, 3, 15);
	g.setEdge(2, 4, 2);
	g.setEdge(4, 3, 9);
	g.setEdge(5, 3, 7);

	g.showMatriz();
	cout << endl << endl << " Visualizar o grafo? 1 - SIM: ";
	
	op = cin.get();
	if (op == '1')
		g.showGraphView();

	
	cout << "\n\n\n (Pressione <ENTER> para encerrar...)" << endl;
	cin.get();
	cin.get();

	return 0;
 }