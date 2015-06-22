/*
* Main.cpp
*
*      Author: Kellison
*
*/

#include <iostream>
#include <stdio.h>
#include "./Prim.hpp" 

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

	printf("\n %c%c%c%c%c%c%c TRABALHANDO COM GRAFOS - ALG. DE PRIM %c%c%c%c%c%c%c \n\n",
		205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205);

	g.showAllVertex();

	cout << endl << " Matriz de Adjacencias (com custos): " << endl << endl;

	g.setEdge(0, 1, 5);
	g.setEdge(0, 2, 6);
	g.setEdge(0, 3, 4);
	g.setEdge(1, 2, 1);
	g.setEdge(1, 3, 2);
	g.setEdge(2, 3, 2);
	g.setEdge(2, 5, 3);
	g.setEdge(2, 4, 6);
	g.setEdge(3, 5, 4);
	g.setEdge(4, 5, 4);

	g.showMatriz();

	cout << endl << endl << " Algoritmo de PRIM:" << endl << endl;

	Prim<int> prim;
	prim.graph = g;
	prim.createMST();

	prim.printMST();
	prim.saveEdgesFile();
	
	cout << endl << endl << " (Pressione <ENTER> para encerrar>" << endl;
	
	return 0;
}
