ArvoreAVL.exe: Tree.o TreeNode.o Main.o
	g++ Main.o Tree.o TreeNode.o -o ArvoreAVL.exe

Main.o: Main.cpp
	g++ -c Main.cpp

Tree.o: Tree.h Tree.cpp
	g++ -c Tree.cpp

TreeNode.o: TreeNode.h TreeNode.cpp
	g++ -c TreeNode.cpp