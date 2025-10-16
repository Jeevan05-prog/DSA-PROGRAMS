#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
struct queue{
    int r,f;
    int data[SIZE];
};
typedef struct queue QUEUE;
void enqueue(QUEUE *q,int item)
{
    if(q->r==SIZE-1)
        printf("\nQueue is full");
    else{
        q->r=q->r+1;
        q->data[q->r]=item;
        if(q->f==-1)
            q->f=0;
    }
}
void dequeue(QUEUE *q)
{
    if(q->f==-1)
        printf("\nQueue is empty");
    else{
        printf("\nElement deleted is %d",q->data[q->f]);
        if(q->f==q->r)
        {
            q->f=-1;
            q->r=-1;
        }
        else{
            q->f=q->f+1;
        }
    }
}
void display(QUEUE q)
{
    int i;
    if(q.f==-1)
        printf("\nQueue empty");
    else{
        printf("\nQueue content is:\n");
        for(i=q.f;i<=q.r;i++)
            printf("\n%d\t",q.data[i]);
    }
}
int main()
{
    int item,ch;
    QUEUE q;
    q.f=-1;
    q.r=-1;
    for( ; ; )
    {
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nRead choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1: printf("\nRead element to be inserted:");
                scanf("%d",&item);
                enqueue(&q,item);
                break;
        case 2: dequeue(&q);
                break;
        case 3: display(q);
                break;
        case 4: exit(0);
        default:exit(0);
        }
    }
}



















