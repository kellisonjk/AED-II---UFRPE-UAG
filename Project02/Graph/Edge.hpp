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
	TVertex getVertexU();
	TVertex getVertexV();
	double getCost();

	//friend ostream& operator<< <>(ostream&, Edge<TVertex>&);
	bool operator== (Edge<TVertex> data);
	bool operator> (Edge<TVertex> data);
	bool operator< (Edge<TVertex> data);
	//friend ostream& operator<< (ostream&, Edge<TVertex>&);

private:
	TVertex vert_u;
	TVertex vert_v;
	double cost;

};


#endif /* Edge_HPP_ */