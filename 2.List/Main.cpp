#include "List.h"
#include <iostream>

int main()
{
	List<int> list;
	for (int ix = 0; ix < 10; ++ix)
	{
		list.Add(ix + 1);
	}

	std::cin.get();
	return 0;
}