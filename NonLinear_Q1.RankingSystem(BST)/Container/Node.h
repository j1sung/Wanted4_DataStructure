#pragma once

#include <iostream>

template<typename T>
void SafeDeleteArray(T*& t)
{
	if (t)
	{
		delete[] t;
		t = nullptr;
	}
}

struct Entry
{
public:
	Entry() = default;

	~Entry()
	{
		SafeDeleteArray(name);
	}

	// 복사 생성자 (deep copy)
	Entry(const Entry& other)
		:score(other.score)
	{
		// 깊은 복사 구현
		size_t length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);
	}

	// 복사 대입 연산자 (deep copy)
	Entry& operator=(const Entry& other)
	{
		if (this == &other) return *this;

		SafeDeleteArray(name);
		score = other.score;

		size_t length = strlen(other.name) + 1;
		name = new char[length];
		strcpy_s(name, length, other.name);

		return *this;
	}

public:
	char* name = nullptr;
	int score = 0;
};

template<typename T>
class Node
{
	// friend 선언
	template<typename T>
	friend class BinarySerchTree;

public:
	Node(const T& data, Node<T>* parent = nullptr)
		: data(data), parent(parent)
private:
	// 노드에 저장 데이터
	T data = T();

	// 부모 & 자식 노드
	Node<T>* parent = nullptr;
	Node<T>* left = nullptr;
	Node<T>* right = nullptr;
};