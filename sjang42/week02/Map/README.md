# Map

## 설명
때때로 dictionary로 불리기도 하는 map은 [연관컨테이너](http://skmagic.tistory.com/210)의 한 종류로 Key와 Value를 한 쌍으로 저장하고 싶을 때 사용된다. list, 배열, 해시테이블, 이진트리 등을 이용해 구현할 수 있고 C++ STL에서는 레드블랙트리를 이용해 구현된다. 해시테이블을 사용해 구현할 경우 O(1)의 속도를 보이지만 메모리 부족 및 효율성, 그리고 순서를 유지하기 위해 [Balanced Tree](https://en.wikipedia.org/wiki/Self-balancing_binary_search_tree)를 이용해 구현하는 것이 일반적이라 O(logN)의 시간복잡도를 갖는다. Key의 중복을 허용하지 않으며 필요한 경우 [multimap](http://www.cplusplus.com/reference/map/multimap/)을 사용한다.

## STL \<map\> 멤버

| <center>멤버</center> | <center>설명</center> |
|--------|--------|
| begin | 첫 번째 원소의 랜덤 접근 반복자를 반환 |
| clear | 저장하고 있는 모든 원소를 삭제 |
| empty | 저장 하고 있는 요소가 없으면 true 반환 |
| end | 마지막 원소 다음의(미 사용 영역) 반복자를 반환 |
| erase | 특정 위치의 원소나 지정 범위의 원소들을 삭제 |
| find | key와 연관된 원소의 반복자 반환 |
| insert | 원소 추가 |
| lower_bound | 지정한 key의 요소를 가지고 있다면 해당 위치의 반복자를 반환 |
| operator[] | 지정한 key 값으로 원소 추가 및 접근 |
| rbegin | 역방향으로 첫 번째 원소의 반복자를 반환 |
| rend | 역방향으로 마지막 원소 다음의 반복자를 반환 |
| size | 원소의 개수를 반환 |
| upper_bound | 지정한 key 요소를 가지고 있다면 해당 위치 다음 위치의 반복자 반환 |

## STL 예제 코드
```C++
#include <map>
#include <string>
using namespace std;

int main(void) {
  map<string, int> my_map;

  // insert
  my_map["age"] = 27;
  my_map.insert(make_pair("year", 1992));
  my_map["height"] = 172;
  printf("[insert] %d %d\n", my_map["age"], my_map["year"]);  // 28 1992

  // count
  int count = my_map.count("age");

  printf("[count] %d\n", count);  // 1
  count = my_map.count("name");
  printf("[count] %d\n", count);  // 0

  // find and erase
  std::map<string, int>::iterator it;

  it = my_map.find("age");
  printf("[erase] %s: %d\n", it->first.c_str(), it->second);
  my_map.erase(it);

  // iterate
  for (it = my_map.begin(); it != my_map.end(); ++it)
    printf("[iter] %s: %d\n", it->first.c_str(), it->second);
  return (0);
}


```
