#include "Container/BinarySearchTree.h"

#include <iostream>
#include <string>

int main()
{
	// BST 만들기
	BinarySearchTree<Entry> tree;

	// ====== 파일 읽기 =======
	FILE* file = nullptr;
	errno_t error = fopen_s(&file, "PlayerData.csv", "rt");
	if (error != 0)
	{
		std::cerr << "Failed to open csv file\n";
		__debugbreak();
		return;
	}
	
	// 읽어들일 임시 버퍼
	char buffer[256] = { };
	
	// 한줄 -> Jisung\t100\n\0
	while (fgets(buffer, sizeof(buffer), file))
	{
		// 한 줄에서 \t 문자로 자르기
		char* context = nullptr;
		char* name = nullptr;
		char* score = nullptr;

		// 자르기 시작 -> \t 문자로 구분
		name = strtok_s(buffer, "\t", &context);
		score = strtok_s(nullptr, "\n", &context);

		Entry entry;
		size_t length = strlen(name) + 1;
		entry.name = new char[length]; // char*이므로 메모리 해제 주의
		strcpy_s(entry.name, length, name); // 다음 while에서 buffer를 덮어쓰면 값이 같이 바뀌므로 복사함.

		entry.score = std::stoi(score); // 문자 -> int 변환

		// Node의 data(구조체)를 복사하면서 초기화, 주소 대입할때 얕은 복사가 발생함.
		// 따라서 Entry구조체 내부에서 복사생성자를 구현하고 deep copy로 구현해야함!
		tree.InsertNode(entry); 
		// while종료시 entry가 소멸하며 entry.name delete[] 되지만,
		// Node.data.name은 deep copy로 구현되었기에 데이터는 보존되고 메모리는 안전하다.
	}

	fclose(file);

	// ====== 로직 실행 =======
	while (true)
	{
		char buffer[256];
		std::cin >> buffer;

		if (strcmp(buffer, "quit") == 0)
		{
			return 0;
		}

		// 삽입

		// 삭제

		// 탐색

		// 정렬(랭킹 출력)

	}

	std::cin.get();
	return 0;
}