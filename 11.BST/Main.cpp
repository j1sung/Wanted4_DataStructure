#include "Container/BinarySearchTree.h"
#include <iostream>

int main()
{
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