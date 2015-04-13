ArvoreRedBlack.exe: RedBlackTree.o Main.o
	g++ Main.o RedBlackTree.o -o ArvoreRedBlack.exe

Main.o: .\src\Main.cpp .\base\AVLTree.cpp
	g++ -c .\src\Main.cpp .\base\AVLTree.cpp

RedBlackTree.o: .\src\RedBlackTree.h .\src\RedBlackTree.cpp .\base\AVLTree.h .\base\AVLTree.cpp
	g++ -c .\src\RedBlackTree.cpp .\base\AVLTree.cpp
