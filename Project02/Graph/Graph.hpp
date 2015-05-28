/*
* Gaph.hpp
*
*  Created on: May 26, 2015
*      Author: Kellison
*
*	Observacoes:
*		- Para que a visaliza��o do grafo funcione a partir do console, � necess�rio
*		  que o valor <CAMINHO> da constante GRAPHVIEW seja alterada para o caminho
*		  da pasta "Project02" na m�quina em que a aplica��o est� sendo executada.
*
*/

#ifndef GRAPH_HPP_
#define GRAPH_HPP_

#include <string>
#include <vector>
#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <fstream>
#include <Windows.h>
#include "Arris.hpp"

#define GRAPHVIEW "<CAMINHO>/Project02/Graph/view/index.html"

using namespace std;

template <class Tpl>
class Graph{
public:
	Graph();
	Graph(vector<Tpl>);
	Arris<Tpl> getArris(Tpl, Tpl);
	void setArris(Tpl, Tpl, double);
	Tpl getVertice(int);
	vector< Arris<Tpl> > getAdjacents(Tpl);
	void saveFile(Tpl, Tpl, double);
	void showMatriz();
	void showGraphView();

	virtual ~Graph();
private:
	vector<Tpl> vertices;
	vector< vector<Tpl> > adjacencyMatriz;
	ofstream outfile;
};


#endif /* GRAPH_HPP_ */
