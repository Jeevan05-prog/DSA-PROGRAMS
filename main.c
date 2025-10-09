#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int top=-1, data[SIZE];

void push(int item)
{
    if(top==SIZE-1)
        printf("\n Stack Overflow");
    else{
        top=top+1;
        data[top]=item;
        printf("Element pushed is:%d",data[top]);
    }
}
void pop()
{
    if(top==-1)
        printf("\nStack Underflow");
    else{
        printf("Element popped is:%d",data[top]);
        top=top-1;
    }
}
void display()
{
    int i;
    if(top==-1)
        printf("\nStack is Empty");
    else{
        printf("\nstack Components are:\n");
        for(i=top;i>=0;i--)
        printf("%d\n",data[i]);
    }

}
int main()
{
int ch,item,i,n;
for(i=0;i<=n;i++)
{
    printf("\n1.PUSH");
    printf("\n2.POP");
    printf("\n3.DISPLAY");
    printf("\n4.EXIT");
    printf("\nRead Choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("\nRead element to be Pushed");
                scanf("%d",&item);
                push(item);
                break;
        case 2: printf("\nRead element to be Popped");
                scanf("%d",&item);
                pop(item);
                break;
        case 3: printf("\nRead element to be Displayed");
                scanf("%d",&item);
                display(item);
                break;
        case 4:exit(0);
        defoult:exit(0);
    }
}
}
