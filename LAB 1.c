#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
struct stack{
    int top;
    int data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s,int item)
{
    if(s->top==SIZE-1)
        printf("\nStack is Overflow");
    else
    {
        s->top=s->top+1;
        s->data[s->top]=item;
    }
}

void pop(STACK *s)
{
    if(s->top==-1)
        printf("\nStack is Under flow");
    else
    {
        printf("\nThe element popped is:%d",s->data[s->top]);
        s->top=s->top-1;
    }
}

void display(STACK s)
{
    int i;
    if(s.top==-1)
        printf("\nStack is Empty");
    else
    {
        printf("\nStack contents are:");
        for(i=s.top;i>=0;i--)
            printf("%d\n",s.data[i]);
    }
    
}
int main()
{
    int ch,item;
    STACK s;
    s.top=-1;
    for( ; ; )
    {
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.DISPLAY");
        printf("\n4.EXIT");
        printf("\nRead choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("\nEnter the item to be pushed:");
                    scanf("%d",&item);
                    push(&s,item);
                    break;
            case 2: pop(&s);
                    break;
            case 3: display(s);
                    break;
            case 4: exit(0);
            default :printf("\nInvaild Entry");
        }
    }
    
}
