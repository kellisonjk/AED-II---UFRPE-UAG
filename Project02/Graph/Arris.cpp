#include "Arris.hpp"

template class Arris<int>;
using namespace std;

template <class Tpl>
Arris<Tpl>::Arris(){
}

template <class Tpl>
Arris<Tpl>::Arris(Tpl u, Tpl v, double cost){
	this->u = u;
	this->v = v;
	this->cost = cost;
}

template <class Tpl>
Tpl Arris<Tpl>::getU(){
	return this->u;
}

template <class Tpl>
Tpl Arris<Tpl>::getV(){
	return this->v;
}

template <class Tpl>
double Arris<Tpl>::getCost(){
	return this->cost;
}