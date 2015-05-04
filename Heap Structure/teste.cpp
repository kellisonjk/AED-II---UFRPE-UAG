#include <iostream>

using namespace std;

template <class T>
class TreeNode
{
public:
	TreeNode(T t);

	T data;
	TreeNode *left;
	TreeNode *rigth;
	TreeNode *parent;

	bool maior(TreeNode);
};

template <class T>
TreeNode<T>::TreeNode(T t)
{
	data = t;
}

template <class T>
bool TreeNode<T>::maior(TreeNode n)
{
	return (data > n.data);
}

class Homem
{
public:
	int idade;

	Homem(int i=0) : idade(i){}

	bool operator>(Homem h)
	{
		return (idade > h.idade);
	}
};


int maion()
{
	TreeNode<int> n1(7);
	TreeNode<int> n2(6);
	
	cout << n1.maior(n2) << endl;

	Homem h1(0);
	Homem h2(10);

	cout << (h1 > h2) << endl;

	TreeNode<Homem> n3(h1);
	TreeNode<Homem> n4(h2);
	cout << n3.maior(n4) << endl; int a;
	cin >> a;
	return 0;
}
	

