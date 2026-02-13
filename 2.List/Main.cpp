#include "List.h"
#include <iostream>

int main()
{
	List<int> list;
	for (int ix = 0; ix < 10; ++ix)
	{
		list.Add(ix + 1);
	}

	// Range-based loop.
	std::cout << "Range-based loop\n";
	for (const int item : list)
	{
		std::cout << item << "\n";
	}

	// 내부 컨테이너 포인터로 자유자재 활용
	// 이터레이터는 내부 저장소 가리키는 포인터다.
	
	// Iterator-based loop
	/*std::cout << "Iterator-based loop\n";
	for (List<int>::Iterator it = list.begin();
		it != list.end();
		++it)
	{
		std::cout << *it << "\n";
	}*/

	std::cin.get();
	return 0;
}