#pragma once

#include <iostream>

template<typename T, int capacity = 10>
class Stack
{
public:
	Stack()
		:top(0)
	{
	}

	bool Push(const T& value)
	{
		if (IsFull())
		{
			return false;
		}

		data[top] = value;
		top++;

		return true;
	}

	// temp: 필요 없으면 outValue 빼도 됨.
	bool Pop(T& outValue)
	{
		if (IsEmpty())
		{
			return false;
		}

		top--;
		outValue = data[top];
		//data[top] = T(); 굳이 초기화 안하고 push할때 덮어써도 됨.

		return true;
	}

	// Getter.
	inline bool IsEmpty() const { return top == 0; }
	inline bool IsFull() const { return top >= capacity; }
	inline int Count() const { return top; }

	void Print()
	{
		for (int ix=0; ix < top; ++ix)
		{
			std::cout << data[ix] << " ";
		}
		std::cout << "\n";
	}

private:
	int top;

	// 스택 데이터 저장 배열
	T data[capacity] = { };
};
