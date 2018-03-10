#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE *prev;
    struct NODE *next;
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
    node->next = NULL;

    if(n == NULL)
    {
        node->prev = NULL;
        n = node;
        return;
    }

    // get last node
    while(n->next != NULL)
        n = n->next;
    n->next = node;
    node->prev = n;
}

void insert(NODE* prev, int data)
{
    NODE* node = malloc(sizeof(NODE));
    node->data = data;
    node->prev = prev;
    node->next = prev->next;
    prev->next = node;
}

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

void print(NODE* n)
{
    n = n->next;
    while(n != NULL)
    {
        printf("%d ", n->data);
        n = n->next;
    }
    printf("\n");
}

NODE* search(NODE* n, int data)
{
    while(n != NULL)
    {
        if(n->data == data)
            return n;
        n = n->next;
    }
    return NULL;
}

int main(void)
{
    NODE* head = NULL;
    NODE* target = NULL;

    head = malloc(sizeof(NODE));
    head->data = 0;
    head->prev = NULL;
    head->next = NULL;

    add(head, 10);
    add(head, 20);
    add(head, 30);
    add(head, 50);
    print(head);

    target = search(head, 30);
    insert(target, 40);
    print(head);

    delete(head, target->next);
    print(head);

    free(head);
    return 0;
}
