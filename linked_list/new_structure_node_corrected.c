#include <stdio.h>
#include <stdlib.h>
// self referential structur
struct Node
{
    int data;
    struct Node *next;   //this statement become self referential structur 
} *first = NULL;          //this is structure pointer created globally
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;                                //here my first ka next is changed
        last = t;                                      
    }
}
void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        RDisplay(p->next);
        printf("%d ", p->data);
    }
}
//reverse linked list using tail recursion function
void reverse_r(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        reverse_r(p,p->next);    //this excute when above condition not became false 
        p->next=q;               //when p became last node then this line execute 
    }
    else
    {
        first=q;
    }

}
int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, 25, 8, 32, 2};
    create(A, 8);
    Display(first);
    printf("\n");
    reverse_r(NULL,first);
    Display(first);
    return 0;
}
