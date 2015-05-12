/*
* Data.cpp
*
*  Created on: May 11, 2015
*      - Author: Kellison
*		- Descrição:
*			Implementação de uma Data, usada para armazenar os dados da lista usada na HashTable
*
*/

#include "Data.h"

Data::Data(string name, int age){
	this->name = name;
	this->age = age;
}

string Data::getKey(){
	return this->name;
}

void Data::setKey(string key){
	this->name = key;
}

// Método de cálculo do valor hash. Para essa implementação, foi escolhido o 
// método de multiplicação ( h(k) = (m * (kA(mod 1))) ).
int Data::getHash(int size){
	int str_int = 0;

	for (int i = 0; i < this->getKey().length(); i++){
		str_int += (int)this->getKey()[i];
	}

	return (size *   fmod((str_int * CONST_A), 1));
}

bool Data::operator== (Data data){
	if ((data.name == this->name) && (data.age == this->age))
		return true;

	return false;
}

ostream& operator<< (ostream& out, const Data& obj) {
	out << "Nome.: " << "." << endl << "      Idade: " << obj.age << endl;
	
	return out;
}

string Data::getName(){
	return this->name;
}

int Data::getAge(){
	return this->age;
}

Data::~Data()
{
}
