#pragma once

#include "Node.h"

enum class SearchResult
{
	NotFound, // 못찾음
	ExactMatch, // 이름/점수 모두 같음
	SameName // 이름만 같음
};

template<typename T>
class BinarySearchTree
{

public:
	BinarySearchTree()
	{ }

	~BinarySearchTree()
	{ 
		// 트리 제거 함수 구현 후 호출.
		Destroy();
	}

	// 삽입(name, score 묶어 저장)
	// score로 비교해서 이진탐색트리 구성
	// score가 같으면 중복이지만 이름이 다르면 들어갈 수 있다.
	bool InsertNode(const T& newData)
	{
		// 중복 여부 확인.
		Node<T>* outNode = nullptr;
		if (SearchNode(newData, outNode))
		{
			// 중복된 값이 있으면 삽입 실패
			return false;
		}

		// 루트 없으면 바로 생성
		if (!root)
		{
			root = new Node<T>(newData); // 소멸자에서 지워야 함
			return true;
		}

		// 일반 삽입 로직
		root = InsertNodeRecursive(root, nullptr, newData);
		return true;

	}

	Node<T>* InsertNodeRecursive(Node<T>* node, Node<T>* parent, const T& newData)
	{
		// node가 null이면 노드 생성 후 반환.
		if (!node)
		{

		}
	}
	
	// 탐색(name으로 검색 후 출력)
	bool SearchNode(const T& data, Node<T>*& outNode)
	{
		return SearchNodeRecursive(root, data, outNode);
	}
	
	bool SearchNodeRecursive(Node<T>* node, const T& data, Node<T>*& outNode)
	{
		// 검색 실패.
		if (!node)
		{
			outNode = nullptr;
			return false;
		}
		
		// data를 바로 찾음
		// 0. 완전히 동일함
		if (node->data == data)
		{
			outNode = node;
			return true; 
		}
		
		// data를 바로 못찾음
		// 1. score가 기존 노드보다 작다면 -> 왼쪽
		if (node->data > data)
		{
			return SearchNodeRecursive(node->left, data, outNode);
		}
		// 2. score가 기존 노드보다 크다면 -> 오른쪽
		else if (node->data < data)
		{
			return SearchNodeRecursive(node->right, data, outNode);

		}
		// 3. score가 같다면 -> 오른쪽
		else if(node->data.IsSameScore())
		{
			return SearchNodeRecursive(node->right, data, outNode);
		}
	}

	// 삭제(name으로 검색 후 삭제)

	// 랭킹 출력(score가 높은 순 k명 출력)

	// 파괴(소멸자 호출)
	void Destroy()
	{
		DestroyRecursive(root);
	}

	void DestroyRecursive(Node<T>* )

private:
	// 루트 노드. 
	Node<T>* root = nullptr;

};