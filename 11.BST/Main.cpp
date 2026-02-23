#include "Container/BinarySearchTree.h"
#include <iostream>

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif

int main()
{
	#ifdef _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	#endif

	// 정수형
	BinarySearchTree<int> tree;

	// 삽입.
	tree.InsertNode(20);
	tree.InsertNode(10);
	tree.InsertNode(5);
	tree.InsertNode(30);
	tree.InsertNode(25);
	tree.InsertNode(35);
	tree.InsertNode(8);

	// 삭제.
	tree.DeleteNode(30);
	tree.DeleteNode(10);
	tree.DeleteNode(8);

	std::cin.get();
	return 0;
}