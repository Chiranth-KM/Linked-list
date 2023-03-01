#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void display(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}
struct node *insert(struct node *head, int n)
{
    struct node *ptr = malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = n;
    return ptr;
}

struct node *delete(struct node *head)
{
    if (head == NULL)
        printf("Underflow\n");
    else
    {
        struct node *ptr = malloc(sizeof(struct node));
        ptr->next = head;
        head = head->next;
        free(ptr);
        return head;
    }
}

void main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 1;
    head->next = NULL;
    head = insert(head, 2);
    head = insert(head, 3);
    printf("Before...\n");
    display(head);
    printf("after...\n");
    head = delete (head);
    head = delete (head);
    head = delete (head);
    head = delete (head);
    display(head);
}