ArvoreRedBlack.exe: AVLTree.o TreeNode.o RedBlackTree.o Main.o
	g++ Main.o RedBlackTree.o AVLTree.o TreeNode.o -o ArvoreRedBlack.exe

Main.o: ./src/Main.cpp
	g++ -c ./src/Main.cpp

RedBlackTree.o: ./src/RedBlackTree.h ./src/RedBlackTree.cpp
	g++ -c ./src/RedBlackTree.cpp ./base/AVLTree.cpp

AVLTree.o: ./base/AVLTree.h ./base/AVLTree.cpp
	g++ -c ./base/AVLTree.cpp

TreeNode.o: ./base/TreeNode.h ./base/TreeNode.cpp
	g++ -c ./base/TreeNode.cpp