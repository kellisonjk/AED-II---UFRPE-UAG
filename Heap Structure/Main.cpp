/*
* Main.cpp
*
*      Author: Kellison
*		Implementação da classe Heap
*/

#include <iostream>
#include <stdio.h>
#include "Heap.h" 

/* VERIFICAR ESSA DECLARAÇÃO: Necessária aqui?? 
Usei para tirar o bug: 
Error	1	error LNK2019: unresolved external symbol "public: __thiscall Heap<int>::Heap<int>(int,int)"
(??0?$Heap@H@@QAE@HH@Z) referenced in function _main */
#include "Heap.cpp" 

using namespace std;


int menu_incial(){
	int op = -1;
	
	while ((op < 0) || (op > 1)){
		if (op != -1){
			cout << endl << endl;
			cout << " Opcao invalida!" << endl;
		}
		cout << endl << " Escolha o tipo da estrutra desejada: " << endl;
		cout << "  0 - Min Heap" << endl;
		cout << "  1 - Max Heap" << endl;
		cout << "  2 - Cancelar" << endl;
		cout << "  Opcao: ";

		cin >> op;			
		if (op == 2) return 2;

	}

	return op;
}

int main() {
	int a[10] = {4,1,3,2,16,9,10};
	int op_heap;
	
	cout << " Array inicial: " << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << " " << a[i];
		if (i != 6) cout << " -";
	}
	cout << endl;

	// Solicita que o usuário escolha um tipo de Heap
	op_heap = menu_incial();

	if (op_heap != 2){
		Heap<int> heap(a, op_heap, 10, 7);

		cout << endl << endl << " " << heap.typeToString() << " ========================== " << endl;

		cout << "\n Depois do Heap:"<< endl;
		heap.print();

		heap.sort();
		cout << "\n Array ordenado com Heapsort: " << endl;
		for (int i = 0; i < 7; i++)
		{
			cout << " " << a[i];
			if (i != 6) cout << " -";
		}
	}

	//heap.clear();
	//delete heap; 

	cout << "\n\n Pressione <ENTER> para encerrar..." << endl;
	getchar(); 
	getchar();

	return 0;
}





