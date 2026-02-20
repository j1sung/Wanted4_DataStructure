#pragma once

#include "Pair.h"
#include <vector>
#include <string>

// 해시 테이블 클래스.
//template<typename Key, typename Value>
/*
template<typename Key>
으로 만들면,

Key가 int면 괜찮음

Key가 string이면 괜찮음

그런데 Key가 사용자 정의 타입이면?

→ 해시 함수가 없다면 에러 발생

그래서 수업 단계에서는

그냥 string으로 고정해서 단순화

했을 가능성이 크다.*/
class HashTable
{
private:
	// 장황한 타입을 Entry로 치환.
	// 왜 템플릿으로 key, value를 받는게 아니라 여기서 string으로 했는가 하니
	// 이 key가 해시값을 적용하는게 가능하게 함이니
	// string STL에 해시값을 가지게 하는게 구현되어있기 때문이다.
	// 근데 수업에서 굳이 맞진 않을 순 있따.
	using Entry = Pair<std::string, std::string>;

public:
	HashTable();
	~HashTable();


	// 키-값 조합으로 저장할 수 있도록.
	// 여기서 래퍼런스 뒤에 const를 왜 안붙이는가? 래퍼런스는 주소를 대입하지 못하는 특성이 있는 포인터 변수 별칭이다.
	// 따라서 const를 붙인거같은 특성이 있으니 굳이 안붙여도 붙인거랑 같은 의미.
	// void Add(const std::string* const key, const std::string* value);
	bool Add(const std::string& key, const std::string& value);

	// 삭제-키를 활용해 K-Value 조합데이터 삭제.
	bool Delete(const std::string& key);

	// 검색 함수.
	bool Find(const std::string& key, Entry& outEntry);

	// 출력 함수.
	void Print();

	// Getter.
	// inline을 남용하면 또 안좋다는데~
	bool IsEmpty() const;

private:
	// 내부 저장소 크기.
	// - 내부 저장소 크기는 소수(1과 자기 자신으로만 나눠지는 수)를 
	// 선택하는 게 해시 충돌 방지에 좋음.
	// 사용 가능한 소수 중에서 큰 수를 사용.
	static const int bucketCount = 19;

	// 이차 저장소(해시 충돌 해결 방법으로 체이닝(Chaining).)
	std::vector<Entry> table[bucketCount];
};