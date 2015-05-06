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
		cout << endl << " Escolha o tipo da estrutra desejada (tbm usada na demonstracao do Heapsort): " << endl;
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
	int op_heap;
	vector<int> vetor, vetor_ordenado;

	// Preenche o vetor com 15 valores aleatórios
	for (int i = 1; i <= 15; i++){
		vetor.push_back(rand() % 100);
	}

	cout << " Array inicial: " << vetor.size() << endl;
	
	for (int i = 0; i < vetor.size(); i++)
	{
		cout << " " << vetor[i];
		if (i != vetor.size() - 1) cout << " -";
	}

	cout << endl;

	// Solicita que o usuário escolha um tipo de Heap
	op_heap = menu_incial();

	if (op_heap != 2){
		int elemento, op;
		bool result;
		Heap<int> h;
		h.extract();
		Heap<int> heap(vetor, op_heap, 20, 15);

		string tipo = (op_heap == 0) ? "menor" : "maior";

		cout << endl << endl << " " << heap.typeToString() << " ========================== " << endl;

		cout << "\n   Apos a 'heapficacao': " << endl;

		heap.printArray(4);
		cout << endl;
		heap.printTree(4);

		////////////// Adição de elementos do Heap //////////////
		cout << "\n   Adicionar um novo elemento? Digite '1' para SIM : ";
		cin >> op;

		while (op == 1){
			cout << "      Digite um numero inteiro: ";
			cin >> elemento;

			heap.insert(elemento);

			cout << "      Apos insercao: " << endl;
			heap.printArray(8);
			cout << endl;
			heap.printTree(8);
			cout << "\n   Adicionar outro ? Digite '1' para SIM : ";
			cin >> op;
		}
		

		////////////// Remoção de elementos do Heap //////////////
		cout << endl << "\n   Remover um elemento? Digite '1' para SIM : ";
		cin >> op;

		while (op == 1){
			cout << "      Digite o elemento a ser removido: ";
			cin >> elemento;

			result = heap.remove(elemento);

			if (!result)
				cout << endl << "      Falha ao tentar remover: " << elemento << endl << endl;
			else{
				cout << endl << "      Apos Remocao: " << endl;
				heap.printArray(8);
				cout << endl;
				heap.printTree(8);
			}

			cout << "\n   Remover outro ? Digite '1' para SIM : ";
			cin >> op;
		}

		////////////// Demonstração do Heapsort //////////////
		

		cout << endl << endl << " Demostracao do Heapsort ========================== " << endl;

		Heap<int>::sort(vetor, op_heap);
		cout << "\n   Array original ordenado com Heapsort:";
		cout << (op_heap == 1 ? "(MAX HEAP)" : "(MIN HEAP)") << endl;

		cout << "  ";
		for (int i = 0; i < vetor.size(); i++)
		{
			cout << " " << vetor[i];
			if (i != vetor.size() - 1) cout << " -";
		}

		cout << endl << "\n   Heap (construido nessa execução) ordenado com Heapsort:" << endl;
		vector<int> novo_vetor = heap.sort();
		cout << "  ";
		for (int i = 0; i < novo_vetor.size(); i++)
		{
			cout << " " << novo_vetor.at(i);
			if (i != novo_vetor.size() - 1) cout << " -";
		}
	}
	

	cout << "\n\n\n (Pressione <ENTER> para encerrar...)" << endl;
	getchar();
	getchar();

	return 0;
}




