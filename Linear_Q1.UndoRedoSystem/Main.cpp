#include "Container/Queue.h"

#include <iostream>

int main()
{
	

	Queue<char*> q;

	while (true)
	{
		char buffer[100];
		std::cin >> buffer;

		if(strcmp(buffer,"quit") == 0) 
			return 0;

		// 문자열 새 주소에 복사
		size_t length = strlen(buffer) + 1;
		char* str = new char[length];
		strcpy_s(str, length, buffer);

		// Enqueue -> 꽉찼으면 메모리 누수 방지
		if (!q.Enqueue(str))
		{
			delete[] str;
			str = nullptr;
		}

	}

	std::cin.get();
	return 0;
}