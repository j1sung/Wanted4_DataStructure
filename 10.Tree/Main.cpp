#include "Container/Node.h"
#include "Container/Tree.h"

#include <iostream>

int main()
{
	/*Node<int>* parent = new Node<int>(10);
	Node<int>* child = new Node<int>(5);
	parent->AddChild(child);
	child->SetParent(parent);

	parent->RemoveChild(child);*/

	Tree<int> tree(10);
	tree.AddChild(10, 9);
	tree.AddChild(10, 8);
	tree.AddChild(9, 7);
	tree.AddChild(9, 6);

	// 검색 테스트.
	Node<int>* outNode = nullptr;
	if (tree.Find(6, outNode))
	{
		int number2 = 30;
	}

	int number = 10;

	std::cin.get();
	return 0;
}