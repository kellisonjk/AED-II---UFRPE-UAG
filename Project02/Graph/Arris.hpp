/*
* Arris.h
*
*  Created on: May 27, 2015
*      Author: Kellison
*/

#ifndef ARRIS_HPP_
#define ARRIS_HPP_

#include <iostream>
#include <stdlib.h>

using namespace std;

template <class Tpl>
class Arris{
public:
	Arris();
	Arris(Tpl, Tpl, double);
	Tpl getU();
	Tpl getV();
	double getCost();

	//friend ostream& operator<< (ostream&, Arris<Tpl>&);

private:
	Tpl u;
	Tpl v;
	double cost;

};


#endif /* ARRIS_HPP_ */