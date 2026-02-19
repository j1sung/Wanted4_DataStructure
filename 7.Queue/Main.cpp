#include "Container/Queue.h"
#include <iostream>

int main()
{
	// 큐 객체 생성.
	Queue<int> queue;
	const int count = 10;
	for (int ix = 0; ix < count; ++ix)
	{
		queue.Enqueue(ix + 1);
	}


	// 값 추출.
	int value;
	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	std::cin.get();
	return 0;
}