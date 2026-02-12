//#define WIN32_LEAN_AND_MEAN
//#define NO_MIN_MAX

//#include <Windows.h>
//#include <winsock2.h>

#include <iostream>
#include <cassert> // c언어 헤더는 .h, c++로 오면서 그냥 앞에 c붙임 => assert.h == cassert
#include <array>

// 템플릿으로 배열 만들기.
template<typename T, size_t size = 5>
class Array
{
public:
	size_t Size() const
	{
		return size;
	}

	// 배열 인덱스 접근을 위한 연산자 오버로딩.
	T& operator[](size_t index)
	{
		// 예외처리!
		
		// 어써트(꼭 검증이 필요한 구문에 활용).
		// 디버그 모드에서만 동작 -> Release에서는 
		
		// 인덱스 범위 확인. 
		// assert는 true면 통과, false면 중단. -> assert(false);일때 조건실패로 중단됨.
		assert(0 <= index && index < size);

		
		// 인덱스 범위 확인. -> assert 직접 구현
		/*if (index < 0  || index >= size)
		{
			__debugbreak();
		}
		*/
		return data[index];
	}

	const T& operator[](size_t index) const // 앞에 const 붙이면 this도 const해야함
	{
		return data[index];
	}

private:
	// 배열 변수.
	T data[size] = {};
};

int main()
{
	Array<int, 5> array;
	array[3] = 20;

	// const 접근.
	const auto& arrayReference = array;


	std::cin.get();
	return 0;
}