// this function is used to understand how i create my first tree 
#include <stdio.h>
#include <stdlib.h>
// this is use for creating tree
struct Node
{
    struct Node* left_child;
    int data;
    struct Node* right_child;
};
// this queue is used store the address of all the tree
struct queue
{
   struct Node* p;
   struct queue* next; 
};
// global variable to store the dequed address
struct queue devalue;
struct queue* enqueue(struct Node* p,struct queue* q)
{
    struct queue *t;
    struct queue *r;
    struct queue *temp=q;
    // // this is reason why we have to give return pointer also don't write
    // struct queue *last; //to avoid the unaessary loop
    t = (struct queue *)malloc(sizeof(struct queue));
    t->next=NULL;
    if (t == NULL)
        printf("Queue is FUll\n");
    else
    {
        t->p = p; //here tree pointinf is done
        if (q == NULL)
            {
                q=t;
                q->next=NULL;
            }
        else
        {
            while (temp->next)
            {
              temp=temp->next;    
            }
            temp->next=t;
        }
    }
    r=q;
    return r;
}
// this function deleting the dequeue
struct queue* dequeue(struct queue* q1)
{
    // here i am not deleting tree i want to delete the queue's value
    struct queue *t;
    struct queue *t2=q1;
    t=(struct queue*)malloc(sizeof(struct queue));
    if (q1==NULL)
        printf("Queue is Empty\n");
    else
    { 
        devalue.p=q1->p; //this store the value whuch is deleted
        t->p=q1->p;
        q1=q1->next;//in this first node delete wala case is covered 
        free(t);
    }
    return q1;
}
struct queue* dequeue_last(struct queue* q1)
{
    struct queue *t;
    struct queue *t2;
    if (q1==NULL)
        printf("Queue is Empty\n");
    else
    { 
        t=q1->next;
        t2=q1;
        while (t->next!=NULL)
        {
           t=t->next;
           t2=t2->next;
        }
        if (t2==q1)
        {
            free(t);
            q1=NULL;
            devalue.p=NULL;
        }
        else
        {
            devalue.p=t->p;
            free(t);
            t2->next=NULL;
        }
        
    }
    return q1;
}
struct Node* create(struct Node* root)
{
    struct queue* q=NULL; //  queue to store the add of tree nodes
    struct Node* p=NULL;
    struct Node* t;
    int x;
    printf("Enter the root value");
    scanf("%d",&x);

    // this is creating root node in heap memory
    root=(struct Node*)malloc(sizeof(struct Node));
    root->data=x;
    root->left_child=root->right_child=NULL;

    // entering the address of root of tree in queue
    q=enqueue(root,q);
    
    // now the values of left child and right child are giving 
    while (q)
    {
       q=dequeue(q);
       p=devalue.p;
    //    printf("Root values is %d",root->data);
       printf("Enter the root value left child(positive integers only):");
       scanf("%d",&x);
       if (x!=-1)
       {
           //creating new node in tree
           t=(struct Node*)malloc(sizeof(struct Node));
           t->data=x;
           t->left_child=t->right_child=NULL;
           p->left_child=t;
           q=enqueue(t,q);
       }
       printf("Enter the root value right child(positive integers only):");
       scanf("%d",&x);
       if (x!=-1)
       {
           //creating new node in tree
           t=(struct Node*)malloc(sizeof(struct Node));
           t->data=x;
           t->left_child=t->right_child=NULL;
           p->right_child=t;
           q=enqueue(t,q);
       }

    }
    //  printf("Root values is %d",root->data);    
    return root;
} 
void preorder(struct Node* p)
{
    struct queue* st=NULL;
    while (p!=NULL || st!=NULL)
    {
       if (p!=NULL)
       {
           printf("%d ",p->data);
           st=enqueue(p,st);
           p=p->left_child;
       }
       else
        {
            st=dequeue_last(st);
            p=devalue.p;
            p->right_child;
        }
       
    }
    
}
int main()
{
    struct Node* tree=NULL;
    tree=create(tree);
    preorder(tree);
    return 0;
}