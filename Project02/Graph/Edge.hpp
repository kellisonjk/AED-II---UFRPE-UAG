/*
* Edge.hpp
*
*  Created on: May 27, 2015
*      Author: Kellison
*/

#ifndef EDGE_HPP_
#define EDGE_HPP_

#include <iostream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

template <class TVertex>
class Edge{
public:
	Edge();
	Edge(TVertex, TVertex, double);

	TVertex vertexSource();
	void vertexSource(TVertex);
	
	TVertex vertexTarget();
	void vertexTarget(TVertex);
	
	double cost();
	void cost(double);

	bool operator== (Edge<TVertex> data);
	bool operator> (Edge<TVertex> data);
	bool operator< (Edge<TVertex> data);
	//friend ostream& operator<< (ostream&, Edge<TVertex>&);

private:
	TVertex v_source;
	TVertex v_target;
	double e_cost;

};


#endif /* Edge_HPP_ */