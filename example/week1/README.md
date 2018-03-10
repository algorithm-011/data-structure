# Array

## 참고 자료

1. https://en.wikipedia.org/wiki/Array_data_structure
2. http://ko.cppreference.com/w/cpp/container/array

## 내용

위치를 나타내는 숫자(index 혹은 key)와 해당 숫자에 대응하는 데이터들로 이루어진 자료 구조.

C에서는 다음과 같이 사용한다.

```c
#include <stdio.h>

int main(void)
{
    int first[5] = {1, 2, 3, 4, 5};
    int second[5] = {0, };

    second[0] = 5;
    second[1] = 4;

    return 0;
}
```

C++ STL을 사용하면 다음과 같다.

```cpp
#include <iostream>
#include <array>

using namespace std;

int main(void)
{
    array<int, 5> first = { {1, 2, 3, 4, 5} };
    array<string, 5> second = { {"github", "git", "linux", "ubuntu", "kernel"} };

    for(int i=0; i<5; i++)
        cout << second[i] << " ";
    cout << endl;

    return 0;
}
```

# Linked List

## 참고 자료

1. https://visualgo.net/en/list
2. https://www.geeksforgeeks.org/linked-list-set-1-introduction/
3. https://www.geeksforgeeks.org/doubly-linked-list/

## Single Linked List

![single linked list](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist.png)

데이터를 저장하는 노드와 다음 노드를 가리키는 포인터로 구성된다.

특정 위치의 데이터를 검색하는 데에 O(n)의 시간이 걸리고, 노드의 중간지점에서 자료의 추가/삭제가 O(1)의 시간에 가능하다.

C의 구조체를 활용하여 구현하면 다음과 같다.

```c
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *ptr;
} NODE;

int main(void)
{
    NODE* head = NULL;
    head = malloc(sizeof(NODE);
    head->data = 0;
    head->ptr = NULL;

    free(head);
    return 0;
}
```

### 데이터 추가

노드들의 맨 끝에 데이터를 추가하는 것과 노드들의 중간에 데이터를 추가하는 것을 구현해보았다.

노드의 포인터만 바꿔주면 되기 때문에 데이터 추가가 용이하다.

1. 맨 끝에 데이터를 추가하기

![add a node at the end](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist_insert_last.png)

```c
void add(NODE* n, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->ptr = NULL;

    if(n == NULL)
    {
        n = node;
        return;
    }

    while(n->ptr != NULL)
        n = n->ptr;
    n->ptr = node;
}
```

2. 중간에 데이터를 추가하기

![add a node after a given node](https://www.geeksforgeeks.org/wp-content/uploads/gq/2013/03/Linkedlist_insert_middle.png)

```c
// prev는 추가할 데이터의 직전 노드다.

void insert(NODE* prev, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->ptr = prev->ptr;
    prev->ptr = node;
}
```

### 데이터 삭제

특정 노드를 찾아 삭제하는 코드를 구현해보았다.

삭제 순서는 다음과 같다.

1. 삭제할 노드의 직전 노드를 찾는다.
2. 직전 노드의 포인터를 바꾼다.
3. 삭제할 노드의 메모리를 해제한다. 

![deleting a node](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/05/Linkedlist_deletion.png)

```c
// target이 삭제할 노드이다.

void delete(NODE* n, NODE* target)
{
    while(n != NULL)
    {
        if(n->ptr == target)
        {
            n->ptr = target->ptr;
            free(target);
            break;
        }
        n = n->ptr;
    }
}
```

[전체 코드 - C]()

## Doubly Linked List

![doubly linked list](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL1.png)

single linked list에서 다음 노드에 대한 포인터 하나만 가졌다면, doubly linked list에서는 이전 노드와 다음 노드를 가리키는 포인터 두 개를 갖는다.

양방향으로 탐색할 수 있다는 장점을 갖게 되고, single linked list 대비 노드의 삭제가 더 간편해진다.

C의 구조체를 이용하여 구현하면 다음과 같다.

```c
#include <stdio.h>

typedef struct NODE
{
    int data;
    struct NODE* prev;
    struct NODE* next;
} NODE;

int main(void)
{
    NODE* head = NULL;
    head = malloc(sizeof(NODE));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    free(head);
    return 0;
}
```

C++ STL을 이용하여 구현하면 다음과 같다.

```cpp
#include <iostream>
#include <list>

using namespace std;

int main(void)
{
    list<int> l;

    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    for(auto it=l.begin(); it!=l.end(); it++)
        cout << *it << " ";
    cout << endl;

    return 0;
}
```

## 데이터 추가

노드들의 맨 끝에 데이터를 추가하는 것과 노드들의 중간에 데이터를 추가하는 것을 구현해보았다.

1. 맨 끝에 데이터를 추가하기

![add a node at the end](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL_add_end1.png)

```c
void add(NODE* prev, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->next = NULL;

    if(n == NULL)
    {
        node->prev = NULL;
        n = node;
        return;
    }

    while(n->next != NULL)
        n = n->next;
    n->next = node;
    node->prev = n;
}
```

2. 중간에 데이터를 추가하기

![add a node after a given node](https://www.geeksforgeeks.org/wp-content/uploads/gq/2014/03/DLL_add_middle1.png)

```c
void insert(NODE* prev, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->prev = prev;
    node->next = prev->next;
    prev->next = node;
}
```

## 데이터 삭제

특정 노드를 찾아 삭제하는 코드를 구현해보았다.

기존 single linked list에서는 특정 노드를 삭제하기 위해 해당 노드 직전의 노드가 필요해서 traverse 과정이 필요했지만, doubly linked list에서는 각 노드가 이전 노드에 대한 포인터를 갖고있기 때문에 별도의 traverse 과정 없이 삭제를 진행할 수 있다.

```c
void delete(NODE* n, NODE* target)
{
    if(n == target)
        n = target->next;
    if(n->next != NULL)
        target->next->prev = target->prev;
    if(target->prev != NULL)
        target->prev->next = target->next;

    free(target);
}
```

[전체 코드 - C]()

# Linked List vs. Array

## 참고자료

https://www.geeksforgeeks.org/linked-list-vs-array/

## 내용

Array는 고정길이, Linked List는 가변길이라는 데에서 가장 큰 차이가 있다.

또한 Linked List가 Array보다 데이터의 추가/삭제가 더 용이하다는 이점이 있다.

반면에 Linked List는 random access가 불가능하기 때문에 첫번째 노드부터 순차적으로 접근해야하기 때문에 이진 탐색등을 수행할 수 없다는 단점이 있다.
