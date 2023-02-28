#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
};

//Function for traversal

void traverse(struct node *ptr)
{
    while(ptr!=NULL)
    {
        printf("Element is: %d\n",ptr->data);
        ptr=ptr->next;
    }
}

//Function for node insertion at beginning

struct node *insertatbegin(struct node* head,int n)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    ptr->next=head;
    ptr->data=n;
    head=ptr;
    return ptr;
}

//Function for node insertion at index

struct node *insertatindex(struct node* head,int n,int index)
{
    int i=0;
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    struct node *p=head;
    while(i!=(index-1))
    {
        p=p->next;
        i++;
    }
    ptr->data=n;
    ptr->next=p->next;
    p->next=ptr;
    return head;

}

//Function for node insertion at last

struct node *insertatend(struct node* head,int n)
{
    struct node *ptr=(struct node*)malloc(sizeof(struct node*));
    struct node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->data=n;
    ptr->next=NULL;
    return head;

}

//Function for node deletion at beginning

struct node* deleteatbegin(struct node* head)
{
    struct node *p=head;
    head=head->next;
    free(p);
    return head;
}

//Function for node deletion at index

struct node *deleteatindex(struct node* head,int index)
{
    struct node *p= head;
    struct node *q= head->next;
    for(int i=0; i!=(index-1);i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

//Function for node deletion at end

struct node *deleteatlast(struct node* head)
{
    struct node *p= head;
    struct node *q= head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}


void main()
{
    struct node *head=(struct node*)malloc(sizeof(struct node*));  // header node
    struct node *first=(struct node*)malloc(sizeof(struct node*));  // first node
    struct node *second=(struct node*)malloc(sizeof(struct node*)); // second node

    head->data=5;
    head->next=first; //head pointing to next node
    first->data=6;
    first->next=second; //first pointing to next node
    second->data=7;
    second->next=NULL;  //second pointing to next null
    printf("Before:\n");
    traverse(head);
    head=deleteatlast(head);
    printf("After:\n");
    traverse(head);
}