#include <iostream>

int main()
{
	// 읽어들일 임시 버퍼
	char buffer[256] = { };

	FILE* file = nullptr;
	errno_t error = fopen_s(&file, "PlayerData.csv", "rt");
	if (error != 0)
	{
		std::cerr << "Failed to open csv file\n";
		__debugbreak();
		return;
	}

	while (true)
	{
		if (fgets(buffer, 256, file) == nullptr)
			break;
	}

	fclose(file);

	// 파일 데이터 토큰으로 잘라서 삽입
	char* context = nullptr; // 나머지 데이터 저장
	char* token = nullptr; // 잘라진 데이터 저장
	
	// 자르기 시작 -> \n 문자로 구분
	token = strtok_s(buffer, "\n", &context);

	// 반복 자르기
	while (token)
	{
		// 한 줄에서 \t 문자로 추가 자르기
		char* contextCol = nullptr;
		char* column = nullptr;

		// 자르기 시작 -> \t 문자로 구분
		column = strtok_s(token, "\t", &contextCol);

		while (column)
		{
			column = strtok_s(nullptr, "\t", &contextCol);
		}

		// 개행 문자로 문자열 분리.
		token = strtok_s(nullptr, "\n", &context);
	}


	// 로직 실행
	while (true)
	{
		char buffer[256];
		std::cin >> buffer;

		if (strcmp(buffer, "quit") == 0)
		{
			return 0;
		}


	}

	std::cin.get();
	return 0;
}