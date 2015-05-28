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

	Graph<int> g(a);

	cout << endl << " Matriz de Adjacencias: " << endl;
	g.setArris(0, 4, 1);
	g.setArris(4, 0, 3);
	g.setArris(0, 2, 5);
	g.setArris(0, 1, 2);
	g.setArris(1, 2, 15);
	g.setArris(1, 3, 2);
	g.setArris(3, 2, 9);
	g.setArris(4, 2, 7);

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