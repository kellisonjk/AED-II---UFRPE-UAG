/*
* Main.cpp
*
*      Author: Kellison
*
*/

#include <iostream>
#include <stdio.h>
#include "./Dijkstra.hpp" 

using namespace std;

void test(int &c){
	c = 14;
}
int main(int argc, char* argv[]){
	vector<int> a;

	a.push_back(0);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);

	Graph<int> g("new", a);
	g.setDirecionado(true);

	printf("\n %c%c%c%c%c%c%c TRABALHANDO COM GRAFOS - ALG. DE Dijkstra %c%c%c%c%c%c%c \n\n",
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

	g.showAllVertex();

	cout << endl << " Matriz de Adjacencias (com custos, grafo direcionado): " << endl << endl;

	g.setEdge(0, 1, 4);
	g.setEdge(0, 2, 1);
	g.setEdge(1, 2, 3);
	g.setEdge(1, 3, 2);
	g.setEdge(1, 4, 3);
	g.setEdge(2, 4, 3);
	//g.setEdge(2, 3, 4);
	g.setEdge(4, 3, 5);
	g.setEdge(4, 5, 3);
	g.setEdge(5, 3, 2);
	g.setEdge(5, 4, 2);

	g.showMatriz();

	cout << endl << endl << " Algoritmo de Dijkstra:" << endl << endl;

	Dijkstra<int> dist;
	dist.graph = g;
	dist.getDistances(0);
	dist.print();

	cout << endl << endl << " (Pressione <ENTER> para encerrar>" << endl;
	
	return 0;
}
