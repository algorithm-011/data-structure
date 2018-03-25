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

![complete binary tree](https://upload.wikimedia.org/wikipedia/commons/thumb/4/46/Complete_binary.svg/800px-Complete_binary.svg.png)


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

1. Preorder (Depth First Traversal)

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

2. Inorder (Symmetric Traversal)

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

3. Postorder

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

4. Level-order (Breadth First Traversal)

모든 노드를 낮은 레벨부터 차례대로 순회한다.

### 트리 순회 예시

![binary tree](https://upload.wikimedia.org/wikipedia/commons/thumb/6/67/Sorted_binary_tree.svg/250px-Sorted_binary_tree.svg.png)

1. Preorder: F, B, A, D, C, E, G, I, H
2. Inorder: A, B, C, D, E, F, G, H, I
3. Postorder: A, C, E, D, B, H, I, G, F
4. Level-order: F, B, G, A, D, I, C, E, H

## 구현

```c
#include <stdio.h>
#include <stdlib.h>

#define false 0
#define true 1

typedef enum boolean {
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

# Priority Queue
