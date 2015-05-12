/*
* Main.cpp
*
*      Author: Kellison
*		Implementaзгo da classe Hash Table
*/

#include "HashTable.h" 

using namespace std;

int main() {
	
	HashTable<Data, string> hashtbl(10);
	char op;
	string nome;
	int idade;

	cout << endl << " Hash Table (Encadeada) " << endl << endl;

	do{
		cout << " Novo registro: " << endl;
		cout << "  Nome.: " ;
		getline(cin, nome);

		cout << "  Idade: ";
		cin >> idade;

		hashtbl.insert(Data(nome, idade));

		cout << endl << " Exibir HashTable? 1 - SIM: ";
		cin >> op;
		getchar();

		if (op == '1'){
			hashtbl.printHash();
		}

		cout << endl << " Adicionar novo registro? 1 - SIM: ";
		cin >> op;
		getchar();
	} while (op == '1');
	

	cout << endl << " Hash Table finalizada: " << endl;
	hashtbl.printHash();

	cout << " Deseja pesquisar por algum registro? 1 - SIM: ";
	cin >> op;
	getchar();

	if (op == '1'){
		cout << "  Digite o valor (nome) para pesquisa: ";
		getline(cin, nome);

		Data result = hashtbl.search(nome);

		cout << endl << "  Resultado da pesquisa: " << endl << "   " << result << endl;
	}

	
	cout << "\n\n (Pressione <ENTER> para encerrar...)" << endl;
	getchar();

	return 0;
}




