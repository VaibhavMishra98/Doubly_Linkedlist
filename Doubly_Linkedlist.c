#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
//Insertion....
struct node *insert(struct node *head,int num)
{
 struct node *temp,*q;
    temp= (struct node*)malloc(sizeof(struct node));
    temp->data=num;
if(head == NULL)
 {
     head = temp;
     temp->next = NULL;
     temp->prev = NULL;
     return head;
 }
 else
    {
        q = head;
        while(q->next)
        {
            q=q->next;
        }
        q->next = temp;
        temp->next = NULL;
        temp->prev = q;
        return head;
    }
}

//Insert at specific position.....
void *insertatpos(struct node *head,int num,int num2)
{
    int i;
    struct node *temp,*q;
    temp = (struct node*)malloc(sizeof(struct node));
    temp->data =num;
    q = head;
    for(i=1;i<num2-1;i++)
    {
        q=q->next;
    }
        temp->next = q->next;
        q->next = temp;
        temp->prev = q;
        temp->next->prev = temp;

}

//Display...
void display(struct node *head)
{
   struct node *t=head;
   while(t)
    {
    printf("%d->",t->data);
        t=t->next;
    }
}
//Delete....
struct node *ddel(struct node *head,int num)
{
    struct node *p, *temp;
    if(head==NULL)
    {
        printf("\nList is Empty");
        return head;
    }
    if(head->data==num)
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
        return head;
    }
    p=head;
    while(p->next)
    {
        if(p->next->data==num)
        {
            temp=p->next;
            p->next=temp->next;
            temp->next->prev=p;
            free(temp);
            return head;
        }
        p=p->next;
    }
    printf("\n The number is not present in the list\n");
    return head;
}

//Sort....
void sort(struct node *head)
{
    struct node *f=head,*l=head;
    while(l->next)
    {
        l=l->next;
    }
    while(l->next!=f)
    {
        int t=f->data;
        f->data = l->data;
        l->data = t;
        f=f->next;
        l=l->prev;
    }
}
void main()
{
    struct node *head=NULL;
    int n,i,num,num2;
    printf("\nHow many numbers you want to insert");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
       {
           printf("\nEnter the number you want to insert");
           scanf("%d",&num);
           head=insert(head,num);
       }
    display(head);
    printf("\n....Insertion at specific location......");
    printf("\nEnter the number you want to insert");
    scanf("%d",&num);
    printf("\nEnter the position where you want to insert");
    scanf("%d",&num2);
    insertatpos(head,num,num2);
    display(head);
    printf("\nEnter the number you want to delete");
    scanf("%d",&num);
    head=ddel(head,num);
    display(head);
    sort(head);
    display(head);
}
