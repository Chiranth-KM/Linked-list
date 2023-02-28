#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *pre;
    int data;
    struct node *next;
};

void traverse(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element is: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct node *insertatbeg(struct node *head, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    new->next = head;
    new->pre = NULL;
    new->data = n;
    head->pre = new;
    head = new;
    return head;
}

struct node *insertatindex(struct node *head, int n, int index)
{
    int i = 1;
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    struct node *ptr = head;
    struct node *p = head->next;

    while (i != (index - 1))
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = new;
    new->pre = ptr;
    new->data = n;
    new->next = p;
    p->pre = new;
    return head;
}

struct node *insertatend(struct node *head, int n)
{
    struct node *new = (struct node *)malloc(sizeof(struct node *));
    struct node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new;
    new->pre = ptr;
    new->data = n;
    new->next = NULL;
    return head;
}

struct node *deleteatbeg(struct node *head)
{
    struct node *ptr = head;
    head = ptr->next;
    head->pre = NULL;
    free(ptr);
    return head;
}

struct node *deleteatindex(struct node *head, int index)
{
    int i = 1;
    struct node *ptr = head;
    struct node *p = head->next;
    while (i != (index - 1))
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    (p->next)->pre = ptr;
    free(p);
    return head;
}

struct node *deleteatlast(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;
    while (p->next != NULL)
    {
        ptr = ptr->next;
        p = p->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}

void main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *first = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *last = (struct node *)malloc(sizeof(struct node));

    head->pre = NULL;
    head->data = 10;
    head->next = first;

    first->pre = head;
    first->data = 11;
    first->next = second;

    second->pre = first;
    second->data = 12;
    second->next = last;

    last->pre = second;
    last->data = 13;
    last->next = NULL;

    printf("Before..\n");
    traverse(head);
    // head = function calls
    printf("after..\n");
    traverse(head);
}