/*
* Main.cpp
*
*      Author: Kellison
*		Implementaзгo da classe Heap
*/

#include <iostream>
#include <stdio.h>
#include "Heap.h" 


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
	int a[10] = { 4, 1, 3, 2, 16, 9, 10 };
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
		int size, novo;
		Heap<int> heap(a, op_heap, 10, 7);
		
		string tipo = (op_heap == 0) ? "menor" : "maior";

		cout << endl << endl << " " << heap.typeToString() << " ========================== " << endl;

		cout << "\n   Apos a 'heapficacao': " << endl;
		cout << "   ";
		heap.print();

		cout << "\n   Adicionando um novo elemento: " << endl;
		cout << "       Digite um numero inteiro: ";
		cin >> novo;

		heap.insert(novo);

		cout << "       Apos insercao: " << endl;
		cout << "      ";
		heap.print();

		cout << endl << "   Extraindo o " << tipo << " elemento:" << endl;
		cout << "      Elemento extraido:" << heap.extract() << endl;
		cout << "\n      Apos extracao:" << endl;
		cout << "      ";
		heap.print();


		size = heap.getSize();
		heap.sort();

		cout << "\n   Array ordenado com Heapsort: " << endl;
		cout << "   ";
		for (int i = 0; i < size; i++)
		{
			cout << " " << a[i];
			if (i != size - 1) cout << " -";
		}
	}

	//heap.clear();
	//delete heap; 

	cout << "\n\n\n (Pressione <ENTER> para encerrar...)" << endl;
	getchar();
	getchar();

	return 0;
}




