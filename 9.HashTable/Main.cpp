#include "Container/HashTable.h"

#include <iostream>

int main()
{
	// 해시 테이블 객체 생성.
	HashTable table;

	// 데이터 추가.
	table.Add("Jisung", "010-12345678");
	table.Add("Kevin", "010-23456789");
	table.Add("Levi", "010-39283849");
	table.Add("Sinji", "010-57584849");
	table.Add("Mikasa", "010-29293394");
	table.Add("Hanji", "010-11239344");

	// 출력.
	table.Print();

	// 검색.
	Pair<std::string, std::string> outValue;
	if (table.Find("Sinji", outValue))
	{
		std::cout
			<< "검색 성공. key: " << outValue.key
			<< " | Value: " << outValue.value << "\n";
	}

	// 삭제.
	table.Delete("Mikasa");
	table.Delete("Hanji");

	table.Print();

	std::cin.get();
	return 0;
}