#pragma once

// 데이터 필드/링크 필드를 갖는 노드 클래스.
// 연결 리스트에 저장되는 항목.
template<typename T>
class Node
{
	// 연결 리스트 friend 지정.
	template<typename T>
	friend class LinkedList; // friend로 선언해서 private인 멤버 접근 가능

	// 노드의 생성은 LinkedList 에서만 가능하도록 private으로 지정.
private:
	// 템플릿 클래스는 같은 파일 안에서 생성자/소멸자를 정의해야한다. 선언과 동시에 하거나 클래스 밖에다가 만들거나.
	// 안그러면 링크 오류가 난다.
	Node()
		:data(), next(nullptr)
	{ 
	}

	Node(T data)
		: data(data), next(nullptr)
	{
	}

private:
	// 데이터 필드.
	T data;

	// 링크 필드.
	Node* next = nullptr;
};

// #include "Node.inl"