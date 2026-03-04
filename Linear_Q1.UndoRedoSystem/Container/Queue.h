#pragma once
#include "Stack.h"

#include <iostream>

enum class Code 
{
	none = -1,
	undo = 0,
	redo,
	show
};

template<typename T, int capacity = 10>
class Queue
{
public:
	Queue()
		:rear(0), front(0), code(Code::none)
	{
	}

	bool Enqueue(const T& value)
	{
		// 큐가 꽉 찼다면
		if (IsFull())
		{
			return false;
		}


		if (IsCode(value))
		{
			return false;
		}

		undo.Push(value);

		//data[rear + 1] = value; -> 그냥 다음 인덱스에 넣으면 최대 도달시 넣을 수 없으니 순환배열 사용
		rear = (rear + 1) % (capacity + 1);
		data[rear] = value;

		return true;
	}

	// temp: 필요없으면 outValue 빼도 됨.
	bool Dequeue(T& outValue) 
	{
		// 큐가 비었다면
		if (IsEmpty())
		{
			return false;
		}

		front = (front + 1) % (capacity + 1);

		// value값 넣기
		outValue = data[front];

		/*
			1. 기본 타입 (primitive type) -> 0으로 초기화
			타입	T() | 결과
			int()	|  0
			float()	| 0.0
			double()| 0.0
			char()	| '\0'
			bool()	|false

			2. 포인터 타입 -> nullptr으로 초기화
			3. 클래스 / struct(사용자 정의 타입) -> 생성자 초기화
		*/
		data[front] = T(); // 이렇게 기본값 넣어서 초기화 = value initialization
		//memset(&data[front], 0, sizeof(T));

		return true;
	}

	// 여기 이해가 핵심 -> 원형큐, front에 데이터 왜 넣으면 안되는지
	inline bool IsFull(){ return (rear + 1) % (capacity + 1) == front; }

	inline bool IsEmpty(){ return rear == front; }

	// 현재 설정된 명령어 Getter
	inline Code GetCode() const { return code; }

	// 명령어 판별 & 실행 -> 입력 큐의 책임을 벗어나는거 같긴 함
	bool IsCode(const T& value)
	{
		
		// undo는 
		if (strcmp(value,"undo")==0)
		{
			code = Code::undo;

			if (!undo.IsEmpty())
			{
				T val;
				undo.Pop(val);
				redo.Push(val);
			}

			return true;
		}
		else if (strcmp(value, "redo")==0)
		{
			code = Code::redo;

			if (!redo.IsEmpty())
			{
				T val;
				redo.Pop(val);
				undo.Push(val);
			}

			return true;
		}
		else if (strcmp(value, "show")==0)
		{
			code = Code::show;

			std::cout << "Undo: ";
			undo.Print();
			std::cout << "Redo: ";
			redo.Print();

			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int rear;
	int front;

	Code code;
	Stack<char*> undo = {};
	Stack<char*> redo = {};


	// 입력값 데이터 저장 배열
	T data[capacity + 1] = { };
};