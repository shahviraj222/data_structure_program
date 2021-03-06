// only for + , - , * , / this precidions are taken bracket's wala not cover 
// pushing the operators (+ - * /)only not oprand(like a,b,c) 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
    char data;
    struct node* next;
};
char popdata;

// in stack we insert the element at first or replace head
struct node* push(struct node* head,int data)
{
    struct node* t;
    t=(struct node*) malloc(sizeof(struct node));  
    t->next=NULL;
    if(t==NULL)
    {
        printf("Stack over flow");
    }
    else
    {
        t->data=data;
        t->next=head; //here i am creating new node before the head so linking (t->next) node to head or top
        head=t;       //now changing head or top to t
    }
    return head;
}
struct node* pop(struct node* t)
{
    if (t==NULL)
    {
        printf("Stack is Empty");
    }
    else
    {
        struct node* a=t;
        t=t->next;
        popdata=a->data;
        free(a);
    }
    return t;
} 
void Display(struct node *a)
{
    struct node *temp=a;
    while (temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    
}
int Isempty(struct node*p)
{
    if(p==NULL)
    {
        return 1;
    }
    return 0;
}
// stack out precidensis
int pre(char x)
{
    if(x=='+'||x=='-')
    {
        return 1;
    }
    else if(x=='*'||x=='/')
    {
        return 3;
    }
    else if(x=='^')
    {
        return 6;
    }
    else if(x=='(')
    {
        return 7;
    }
    // here i am returning 0 take care
    else if(x==')')
    {
        return 0;
    }
    else if(x=='{')
    {
        return 8;
    }
    else if(x=='}')
    {
        return -1;
    }
     else if(x=='[')
    {
        return 9;
    }
      else if(x==']')
    {
        return -2;
    }
     return -3;
} 
int prein(char x)
{
    if(x=='+'||x=='-')
    {
        return 2;
    }
    else if(x=='*'||x=='/')
    {
        return 4;
    }
    else if(x=='^')
    {
        return 5;
    }
     else if(x=='(')
    {
        return 0;
    }
      else if(x=='[')
    {
        return -2;
    }
      else if(x=='{')
    {
        return -1;
    }
}
int isOperator(char x)
{
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'||x=='{'||x=='}'||x=='['||x==']')
    {
        return 1; //take care
    }
    else
    {
        return 0;
    }
}
int evaluation(char *a)
{
    struct node *b=NULL;
    int i,x1,x2,r;
    for ( i = 0;a[i]!='\0'; i++)
    {
        if (!isOperator(a[i]))
        {
            // printf("\n a[i]=%c",a[i]);
            b=push(b,a[i]-'0'); //this is use to convert my string into integer value
        }
        else
        {
            b=pop(b);
            x2=popdata;
            b=pop(b);
            x1=popdata;
            switch (a[i])
            {
            case '+':
                // printf("\nx1=%d",x1);
                r=x1+x2;
                b=push(b,r);
                break;
            
            case '-':
                r=x1-x2;
                b=push(b,r);
                break;
            case '/':
                r=x1/x2;
                b=push(b,r);
                break;
            case '*' :
                r=x1*x2;
                b=push(b,r);
                break;
            case '^':
                r=1;
                for (int i = 0; i < x2; i++)
                {
                    r=r*x1;
                }  
                b=push(b,r);
                break;    
            default: 
                break;   
            }
        }
        
    }
    b=pop(b);
    return popdata;
}
// this can only convert the +,-,*,/
// here my length reduces due to we don't print brackets
void convert(char *p)
{
    char *q=(char*)malloc(sizeof(char)*(strlen(p)+1));                     //to store postfix converstion  
    struct node*a=NULL;         //stack for storing the operators
    printf("%s",p);
    int i=0,j=0;
    while (p[i]!='\0')
    {
        if(!isOperator(p[i]))
        {
            // printf("Yes operator %c",&p[i]);
            q[j++]=p[i++];
        }
        else
        {
            if (Isempty(a))
            {
                a=push(a,p[i++]);
            }
            else
            {
                if (pre(p[i])>prein(a->data))
                {
                    a=push(a,p[i++]);
                }
                else if(pre(p[i])==prein(a->data))
                {
                    a=pop(a);
                    i++;
                }
                else
                {
                    a=pop(a);
                    // printf(" pop=%c ",popdata);
                    q[j++]=popdata;
                }
            }
            
        }
    }
    while (a!=NULL)
    {
        a=pop(a);
        q[j++]=popdata;
    }
    q[j]='\0';
    // strcpy(result,q);
    // printf("MYstring in r=%s",result);
    int k=0;
    printf("\nAfter converting into postfix:");
    while (q[k]!='\0')
    {
        printf("%c",q[k]);
        k++;
    }
    int z=0;
    printf("\n!!HERE MY VARIABLE TAKE VALUE FROM 0 to 9 ONLY!!\n");
    while(q[z]!='\0')
    {
        if (isOperator(q[z]))
        {
            z++;
        }
        else
        {
            fflush(stdin);
            printf("Enter the value of %c =",q[z]);
            scanf("%c",&q[z]);
            z++;
        }
        
    }
    k=0;
    printf("Evaluation of your function is:");
    while (q[k]!='\0')
    {
        printf("%c ",q[k]);
        k++;
    }
    printf("= %d",evaluation(q));
}

int main()
{ 
    char a[100];
    printf("Enter your string:");
    scanf("%s",&a);
    convert(a);
    return 0; 
}