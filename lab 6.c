LAB 1: Stack implimentation

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




LAB 2: Infix to Postfix



#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 20
char postfix[20];
struct stack{
    int top;
    char data[SIZE];
};
typedef struct stack STACK;

void push(STACK *s,char item)
{
    s->data[++(s->top)]=item;
}

char pop(STACK *s)
{
    return s->data[(s->top)--];
}

int preced(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':return 1;
        case '*':
        case '/':return 3;
        case '^':return 4;
    }
}
void infixtopostfix(STACK *s,char infix[20])
{
    int i,j=0;
    char symbol,temp;
    for(i=0;infix[i]!='\0';i++)
    {
        symbol=infix[i];
        if(isalnum(symbol))
            postfix[j++]=symbol;
        else
        {
            switch(symbol)
            {
                case '(':push(s,symbol);
                         break;
                case ')':pop(s);
                         while(temp!='(')
                         {
                            postfix[j++]=temp;
                            temp=pop(s);
                         }
                         break;
                case '+':
                case '-':
                case '*':
                case '/':
                case '^':if(s->top==-1||s->data[s->top]=='(')
                             push(s,symbol);
                         else
                         {
                             while(preced(s->data[s->top])>=preced(symbol)&&s->top!=-1&&s->data[s->top]!='(')
                             {
                                 postfix[j++]=pop(s);
                             }
                             push(s,symbol);
                         }
                         break;
                
            }
        }
    }
    while(s->top != -1)
    {
        postfix[j++] = pop(s);
    }
    postfix[j] ='\0'; 
}
int main()
{
    char infix[20];
    STACK s;
    s.top=-1;
    printf("\nRead infix expression:");
    scanf("%s",infix);
    infixtopostfix(&s,infix);
    printf("\nPostfix expression is:%s",postfix);
    return 0;
}





LAB 3: Evaluation of post fix




#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#define SIZE 10
struct stack{
    int top;
    float data[SIZE];
};
typedef struct stack STACK;
void push(STACK *s,float item)
{
    s->data[++(s->top)]=item;
}
float pop(STACK *s)
{
    return (s->data[(s->top--)]);
}
float compute(float opr1,char symbol,float opr2)
{
    switch(symbol)
    {
        case '+':return opr1+opr2;
        case '-':return opr1-opr2;
        case '*':return opr1*opr2;
        case '/':return opr1/opr2;
        case '^':return pow(opr1,opr2);
        default: return 0;
    }
}
float evaluatetopostfix(STACK *s,char postfix[20])
{
    int i;
    float opr1,opr2,res;
    char symbol;
    for(i=0;postfix[i]!='\0';i++)
    {
        symbol=postfix[i];
        if(isdigit(symbol))
            push(s,symbol-'0');
        else
        {
            opr2=pop(s);
            opr1=pop(s);
            res=compute(opr1,symbol,opr2);
            push(s,res);
        }
    }
    return pop(s);
}
int main()
{
float res;
char postfix[20];
STACK s;
s.top=-1;
printf("\nRead postfix expression\n");
scanf("%s",postfix);
res=evaluatetopostfix(&s,postfix);
printf("\nreturn is:%f",res);
return 0;
}



LAB 5:Queue Implementation




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



LAB 4A: GCD



#include<stdio.h>
#include<stdlib.h>
int gcd(int a, int b)
{
    if(b!=0)
    {
        return gcd(b,a%b);
    }
    else
        return a;
}
int main()
{
    int a,b;
    printf("\nEnter values of a and b:\n");
    scanf("%d %d",&a,&b);
    printf("\nGCD of %d and %d id %d",a,b,gcd(a,b));
    return 0;
}



LAB 4B: TOH



#include<stdio.h>
#include<stdlib.h>
void toh(int n, char s, char d, char t)
{
    if(n>1)
    {
        toh(n-1,s,t,d);
        printf("\nMove disc %d from %c to %c",n,s,d);
        toh(n-1,t,d,s);
    }
    else
    {
        printf("\nMove disc %d from %c to %c",n,s,d);
    }
}
int main(int n)
{
    printf("\nRead number of disc's:");
    scanf("%d",&n);
    toh(n,'S','D','T');
    return 0;
}

LAB 6:Multiplication of polynomials using singly linked list.



#include<stdio.h>
#include<stdlib.h>

struct node {
    int co; 
    int po; 
    struct node *addr; 
};

typedef struct node* NODE; 

NODE insertend(NODE start, int co, int po) {
    NODE temp, cur;
    temp = (NODE)malloc(sizeof(struct node)); 
    if (temp == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    
    temp->co = co;
    temp->po = po;
    temp->addr = NULL;

    if (start == NULL) {
        return temp; 
    }
    
    cur = start;
    while (cur->addr != NULL) {
        cur = cur->addr;
    }
    cur->addr = temp;
    return start;
}

void display(NODE start) {
    NODE temp;
    if (start == NULL) {
        printf("\nPolynomial is empty.");
    } else {
        temp = start;
        while (temp->addr != NULL) {
            printf("%d*x^%d + ", temp->co, temp->po);
            temp = temp->addr;
        }
        printf("%d*x^%d", temp->co, temp->po); 
    }
}

NODE addterm(NODE res, int co, int po) {
    NODE cur;
    
    if (co == 0) return res; 

    cur = res;
    while (cur != NULL) {
        if (cur->po == po) {
            cur->co += co;
            return res;
        }
        cur = cur->addr;
    }

    res = insertend(res, co, po);
    return res;
}

NODE multiply(NODE poly1, NODE poly2) {
    NODE p1, p2, res = NULL;

    for (p1 = poly1; p1 != NULL; p1 = p1->addr) {
        for (p2 = poly2; p2 != NULL; p2 = p2->addr) {
            int new_co = (p1->co) * (p2->co);
            int new_po = (p1->po) + (p2->po);
            
            res = addterm(res, new_co, new_po);
        }
    }
    return res;
}

int main() {
    NODE poly1 = NULL, poly2 = NULL, poly_res;
    int co, po, n, i;

    printf("Enter number of terms in first polynomial: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input for number of terms.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Enter coefficient (co) and power (po) of term %d: ", i + 1);
        if (scanf("%d%d", &co, &po) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
        poly1 = insertend(poly1, co, po);
    }
    printf("\nFirst polynomial P1(x) is:\n");
    display(poly1);

    printf("\n\nEnter number of terms in second polynomial: ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Invalid input for number of terms.\n");
        return 1;
    }
    
    for (i = 0; i < n; i++) {
        printf("Enter coefficient (co) and power (po) of term %d: ", i + 1);
        if (scanf("%d%d", &co, &po) != 2) {
            printf("Invalid input.\n");
            return 1;
        }
        poly2 = insertend(poly2, co, po);
    }
    printf("\nSecond polynomial P2(x) is:\n");
    display(poly2);

    poly_res = multiply(poly1, poly2);
    
    printf("\n\nResultant polynomial after multiplication P1(x) * P2(x) is:\n");
    display(poly_res);
    
    printf("\n");

    return 0;
}