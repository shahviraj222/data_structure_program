#include<stdio.h>
#include<stdlib.h>
//size of array
//top is linke pointer logically but here we use the index number so that's why it integer type
//pointer pointing array
struct stack
{
    int size;
    int top;
    int *S;
};
// first creating stack in memory
void create(struct stack *st)
{
    printf("Enter the size of stack:");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int*) malloc(sizeof(st->size*sizeof(int)));
}
//adding element inside created stack
void push(struct stack *st,int data)
{
    //checking the size empty in stack 
    if(st->top==st->size-1)
    {
        printf("stack over flow");
    }
    else
    {
        st->top++;
        st->S[st->top]=data;
    }
}
//deleting element and also return that data 
int pop(struct stack *st)
{   
    int x=-1;
    //checking stack is not empty
    if(st->top==-1)
    {
        printf("stack under flow");
        return x;
    }
    else
    {
        x=st->S[st->top];
        st->top--;
    }
    return x;
}
//giving data which is present at that position 
int peek(struct stack st,int pos)
{   int index=st.top-pos+1;
    if(index<0)
    {
        printf("Invalid Index");
        return -1;
    }
    else
    {
        return st.S[index];
    }
}

void Display(struct stack st)
{
    for (int i = st.top; i>=0; i--)
    {
        printf("%d ",st.S[i]);
    }
    
}
int main()
{ 
    struct stack st;
    create(&st);
    push(&st,551);
    push(&st,55);
    push(&st,1);
    push(&st,51);
    //delete the last element deleted first
    pop(&st);
    // peek(st,1); //here i am giving position which never starts from 0 
    // here hoe our data is printed take note LIFO
    printf("Element is peeked is %d\n",peek(st,5));
    Display(st);
    return 0;
}