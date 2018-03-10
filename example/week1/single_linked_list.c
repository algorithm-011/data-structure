#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *ptr;
} NODE;

void add(NODE* n, int data);
void insert(NODE* prev, int data);
void delete(NODE* n, NODE* target);
void print(NODE* n);
NODE* search(NODE* n, int data);

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

void insert(NODE* prev, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->ptr = prev->ptr;
    prev->ptr = node;
}

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

void print(NODE* n)
{
    n = n->ptr;
    while(n != NULL)
    {
        printf("%d ", n->data);
        n = n->ptr;
    }
    printf("\n");
}

NODE* search(NODE* n, int data)
{
    while(n != NULL)
    {
        if(n->data == data)
            return n;
        n = n->ptr;
    }
    return NULL;
}

int main(void)
{
    NODE* head = NULL;
    NODE* target = NULL;

    head = malloc(sizeof(NODE));
    head->data = 0;
    head->ptr = NULL;

    add(head, 10);
    add(head, 20);
    add(head, 30);
    add(head, 50);
    print(head);

    // insert 40
    target = search(head, 30);
    if(target != NULL)
        insert(target, 40);
    print(head);

    // delete 40
    if(target != NULL)
        delete(head, target->ptr);
    print(head);

    free(head);
    return 0;
}
