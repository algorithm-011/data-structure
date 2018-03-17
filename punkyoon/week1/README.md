# Map

key와 value를 함께 저장하는 자료구조다. key는 중복될 수 없다.

STL에서 중복 key를 허용하고 싶다면, `multimap`을 사용하면 된다.

`C++`에서는 `Map`을 사용한다면, `Python`에서는 `Dictionary`를 사용한다.

# Set

말그대로 집합. 중복값이 존재하지 않는 자료구조다.

STL에서 중복값을 허용하고 싶다면, `multiset`을 사용하면 된다.

교집합 등의 연산을 수행할 수 있다.

# Deque

기존의 `queue`가 뒤로만 값을 넣을 수 있고 앞에서만 값을 빼올 수 있었다면, `deque`는 양쪽에서 모두 값을 넣고 빼올 수 있는 자료구조다.

# Vector

동적 배열. 배열 중간에 데이터 삽입/삭제가 불가능하다. 다만, 배열의 앞이나 뒤에 값을 추가하는 것은 가능하다.

배열처럼 index를 통해 값에 쉽게 접근이 가능하고, 값들이 순차적으로 저장된다.

# List

`vector`의 단점인 배열 중간에 값 삽입/삭제가 가능하다.

하지만, 순차 접근을 필요로 하기 때문에 index를 통한 값 접근이 불가능하다.

# Tuple

## 참고자료

http://hashcode.co.kr/questions/1056/리스트랑-튜플은-각각-어떤-때-쓰나요

`Python`에서 `list`와 종종 비교되는 자료구조다.

list처럼 데이터의 순서 등이 유지되는 것은 같지만, `tuple`은 생성 이후 값의 추가/삭제가 불가능하다는 차이가 있다.

또한, `list` 대비 공간 효율적인 측면이 존재하기 때문에 `main`에서 `*args`를 받을 때에는 tuple을 사용한다.