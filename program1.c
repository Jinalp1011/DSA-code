#include<stdio.h>
struct stack
{
    int s[6];
    int top;
};

void intialize(struct stack *p)
{
    p->top=-1;
}

void push(struct stack *p,int a)
{
    if(p->top==5)
    {
        printf("Stack is overflow!!");
    }
    else
    {
        p->top++;
        p->s[p->top]=a;
    }
}

int pop(struct stack *p)
{
    if(p->top==-1)
    {
        printf("Stack is underflow!!");
    }
    else
    {
        int temp=p->s[p->top];
        p->top--;
    }
}

void display(struct stack *p)
{
    if(p->top==-1)
    {
        printf("Stack is underflow!!");
    }
    else{
        for(int i=p->top ; i>=0 ; i--)
        {
            printf("%d\n",p->s[i]);
        }
    }
}

void peep(struct stack *p,int ps)
{
    if(p->top - ps<0)
    {
        printf("Invalid position");
    }
    else
    {
        printf("%d\n",p->top-ps+1);
    }
}

int change(struct stack *p,int pos,int value)
{
    if(p->top-pos+1<=0)
    {
        printf("Can't proceed");
    }
    else
    {
        return p->s[p->top-pos]=value;
    }
}

int main()
{  
    struct stack s;
    intialize(&s);
    push(&s,1);
    push(&s,2);
    push(&s,3);
    push(&s,4);
    push(&s,5);
    push(&s,6);
    pop(&s);
    display(&s);
    printf("Peep element is:");
    peep(&s,3);
    printf("Stack after change:\n");
    change(&s,3,8);
    display(&s);

     return 0;
}