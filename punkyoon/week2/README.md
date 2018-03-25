# Binary Tree

## 참고 자료

1. https://en.wikipedia.org/wiki/Binary_tree
2. https://www.geeksforgeeks.org/binary-tree-data-structure/
3. https://medium.com/basecs/leaf-it-up-to-binary-trees-11001aaf746d
4. https://www.tutorialspoint.com/data_structures_algorithms/tree_data_structure.htm

## 내용

이진 트리는 모든 노드가 최대 두 개의 자식 노드를 가지는 트리 자료구조이다. 보통 `Binary Search Tree`와 `Binary Heap` 구현에 흔히 사용된다.

![binary tree](https://www.tutorialspoint.com/data_structures_algorithms/images/binary_tree.jpg)

자식이 모두 2개씩인 꽉 찬 트리를 `완전 이진 트리`라고 한다.

### `완전 이진 트리`에서..

#### Root Node = Level 1인 경우..

각 레벨당 `2^(level-1)`만큼의 노드를 가지게 된다.

즉, Level 5인 트리에서는 `2^(5-1) = 16`개의 노드를 갖게 된다. (Level 5까지 있는 트리의 전체 노드 개수가 아닌, Level 5에 있는 노드들의 전체 개수!)

또한, Level `i`의 최대 노드 수는 `(2^i)-1`로 정의할 수 있다.

배열로 구현할 경우, `i`번째 노드의 부모 노드 위치는 `i/2`이고, 왼쪽 자식 노드 위치는 `2i`, 오른쪽 자식 노드 위치는 `2i+1`의 Index를 가진다.

#### Root Node = Level 0인 경우.. (The Art of Computer Programming)

각 레벨당 `2^level`만큼의 노드를 가지게 된다.

즉, Level 4인 트리에서는 `2^4 = 16`개의 노드를 갖게 된다.

또한, Level `i`의 최대 노드 수는 `2^(i+1)-1`로 정의할 수 있다.

## 트리 순회

트리를 순회하는 대표적인 방법에는 4가지가 있다.

### 1. Preorder (Depth First Traversal)

`노드 방문 -> 왼쪽 서브트리 전위 순회 -> 오른쪽 서브트리 전위 순회`로 진행된다.

> Root, Left, Right

코드로 구현하면 다음과 같다.

```c
void preorder(NODE *node)
{
    printf("%c ", node->data);
    if(node->left != NULL)
        preorder(node->left);
    if(node->right != NULL)
        preorder(node->right);
}
```

### 2. Inorder (Symmetric Traversal)

`왼쪽 서브트리 중위 순회 -> 노드 방문 -> 오른쪽 서브트리 중위 순회`로 진행된다.

> Left, Root, Right

코드로 구현하면 다음과 같다.

```c
void inorder(NODE *node)
{
    if(node->left != NULL)
        inorder(node->left);
    printf("%c ", node->data);
    if(node->right != NULL)
        inorder(node->right);
}
```

### 3. Postorder

`왼쪽 서브트리 후위 순회 -> 오른쪽 서브트리 후위 순회 -> 노드 방문`으로 진행된다.

> Left, Right, Root

코드로 구현하면 다음과 같다.

```c
void postorder(NODE *node)
{
    if(node->left != NULL)
        postorder(node->left);
    if(node->right != NULL)
        postorder(node->right);
    printf("%c ", node->data);
}
```

### 4. Level-order (Breadth First Traversal)

모든 노드를 낮은 레벨부터 차례대로 순회한다.

### 트리 순회 예시

![binary tree](https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Sorted_binary_tree.svg/250px-Sorted_binary_tree.svg.png)

**1. Preorder:** F, B, A, D, C, E, G, I, H
**2. Inorder:** A, B, C, D, E, F, G, H, I
**3. Postorder:** A, C, E, D, B, H, I, G, F
**4. Level-order:** F, B, G, A, D, I, C, E, H

## 구현

```c
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef enum boolean
{
    FALSE,
    TRUE
} bool;

typedef struct Node
{
    char data;
    struct Node *left;
    struct Node *right;
} NODE;

void add(NODE *node, bool position, char data);
void preorder(NODE *node);
void inorder(NODE *node);
void postorder(NODE *node);

void add(NODE *node, bool position, char data)
{
    NODE *temp = malloc(sizeof(NODE));
    temp->data = data;
    temp->right = NULL;
    temp->left = NULL;

    // true = right
    if(position == true)
        node->right = temp;
    else
        node->left = temp;
}
        
void preorder(NODE *node)
{
    printf("%c ", node->data);
    if(node->left != NULL)
        preorder(node->left);
    if(node->right != NULL)
        preorder(node->right);
}

void inorder(NODE *node)
{
    if(node->left != NULL)
        inorder(node->left);
    printf("%c ", node->data);
    if(node->right != NULL)
        inorder(node->right);
}

void postorder(NODE *node)
{
    if(node->left != NULL)
        postorder(node->left);
    if(node->right != NULL)
        postorder(node->right);
    printf("%c ", node->data);
}

int main(void)
{
    NODE *root = NULL;
    root = malloc(sizeof(NODE));

    // Level 0
    root->data = 'F';
    root->right = NULL;
    root->left = NULL;

    // Level 1
    add(root, false, 'B');
    add(root, true, 'G');

    // Level 2
    add(root->left, false, 'A');
    add(root->left, true, 'D');
    add(root->right, true, 'I');

    // Level 3)
    add(root->left->right, false, 'C');
    add(root->left->right, true, 'E');
    add(root->right->right, false, 'H');

    // Traverse
    printf("======= Preorder\n");
    preorder(root);
    printf("\n======= Inorder\n");
    inorder(root);
    printf("\n======= Postorder\n");
    postorder(root);
    printf("\n");

    free(root);
    return 0;
}
```

# Heap

## 참고 자료

1. http://blog.weirdx.io/post/3122
2. http://blog.eairship.kr/249
3. https://visualgo.net/en/heap
4. https://www.geeksforgeeks.org/binary-heap/
5. 

## 내용

> `Max Heap`은 부모가 자식보다 값이 더 큰 경우, `Min Heap`은 부모가 자식보다 값이 더 작은 경우를 말한다. 여기서는 `Max Heap`을 기준으로 한다.

`Heap`은 완전 이진 트리로서, 부모 노드는 항상 다른 두 자식 노드들보다 큰 값을 가지는 구조이다. 또한, 가장 아랫단의 노드들은 왼쪽부터 차례대로 채워진다. 결과적으로, `Heap`의 Root Node는 전체 데이터 중에서 가장 큰 데이터를 갖게 된다.

> 배열로 구현할 경우, Root Node의 index가 0이라고 가정한다면 index 값이 작을수록 큰 데이터가 저장된다.

`Heap`은 `우선 순위 큐`의 일종으로, 우선 순위가 높은 요소를 효율적으로 선택할 수 있는 자료 구조기 때문에 `우선 순위 큐`의 생성, 삽입, 제거, 대치, 변경의 과정을 거쳐 만들어진다.

![heap](https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/501px-Max-Heap.svg.png)

## Heap 생성

Heap에 자료를 구성하면서 새로 삽입된 값이 Heap의 규칙에 맞게 위로 올라가는 동작을 `Upheap`이라고 하고, 제거하는 과정에서 하단으로 끌어 내리는 동작을 `Downheap`이라고 한다.

> Heap을 구성하는 방법도 나뉘는데, `Top-Down`과 `Bottom-Up`으로 나뉜다.

- Upheap은 데이터를 추가할 때 수행되는 과정이다.
- Downheap은 데이터를 삭제할 때 수행되는 과정이다.

## 구현

배열을 사용하여 구현한 heap이다. Root node의 index를 0을 기준으로 했기 때문에 index를 1로 한 코드들과는 다르다.

_참고_

(나의 현재 위치) = i | Root index = 0 | Root index = 1
------------ | ------------- | ------------
부모 노드 위치 | ((i + 1) / 2) - 1 | i / 2
왼쪽 자식 노드 위치 | (2 * (i + 1)) - 1 | 2 * i
오른쪽 자식 노드 위치 | 2 * (i + 1) | (2 * i) + 1

_Heap Sort: https://youtu.be/MtQL_ll5KhQ_

```c
#include <stdio.h>
#include <stdlib.h>

int *heap = NULL;
int n = 0;

void push(int data);
int pop(void);
void upheap(int idx);
void downheap();
void sort(int arr[], int size);

void push(int data)
{
    heap[n] = data;
    upheap(n++);
}

int pop(void)
{
    int temp = heap[0];
    heap[0] = heap[--n];
    downheap();

    return temp;
}

void upheap(int idx)
{
    int val = heap[idx];
    while(idx > 0 && heap[((idx+1)/2)-1] < val)
    {
        heap[idx] = heap[((idx+1)/2)-1];
        idx = ((idx+1)/2) - 1;
    }
    heap[idx] = val;
}

void downheap(void)
{
    int val = heap[0];
    int i = 0;
    while(i <= n/2)
    {
        int j = ((i+1)*2) - 1;
        if(j+1 <= n && heap[j] < heap[j+1])
            j++;
        if(val >= heap[j])
            break;
        heap[i] = heap[j];
        i = j;
    }

    heap[i] = val;
}

void sort(int arr[], int size)
{
    int i;
    for(i=0; i<size; i++)
    {
        arr[i] = pop();
        printf("%d: %d\n", i+1, arr[i]);
    }
}

int main(void)
{
    int arr[] = {15, 2, 8, 11, 9, 7};
    int i, size = sizeof(arr) / sizeof(int);

    heap = malloc(sizeof(int) * size + 1);

    for(i=0; i<size; i++)
        push(arr[i]);

    // heap arr
    printf("===== HEAP\n");
    for(i=0; i<size; i++)
        printf("%d ", heap[i]);
    printf("\n");

    sort(arr, size);    // heap sort

    // sorted arr
    printf("===== RESULT\n");
    for(i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(heap);
    return 0;
}
```

# Priority Queue

## 참고 자료

1.
2.

## 내용

`우선 순위 큐`는 자료의 집합이 있을 때, 각 자료들은 각각의 순위가 있다는 개념을 가진다. 각 요소에 우선 순위를 매겨서 반드시 가장 큰 우선 순위를 가진 요소를 꺼내는 것이다.

이를 구현하는 방법은 대표적으로 세 가지가 있다.

1. 배열 기반 구현
2. Linked List 기반 구현
3. Heap 기반 구현

배열과 Linked List를 활용한 구현은 데이터의 위치를 재조정 해주거나 탐색에 시간이 많이 들어가기 때문에 Heap을 이용한 구현이 일반적이다.

