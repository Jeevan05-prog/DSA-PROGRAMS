#include <stdio.h>
#include <stdlib.h>
int tsize,hash[10],count=0;
int cal_hash(int key)
{
    return key % tsize;
}
int cal_rehash(int key)
{
    return (key + 1) % tsize;
}
void insert(int key)
{
int index;
if(count!=tsize)
{
    index=cal_hash(key);
    while(hash[index]!=-1)
    {
        index=cal_rehash(index);
    }
    hash[index]=key;
    count++;
}
else
{
    printf("Hash table is full\n");
}
}
int search(int key)
{
int index,i,loc=-1;
index=cal_hash(key);
for(i=0;i<tsize;i++)
{
    loc=(index+1)%tsize;
    if(hash[loc]==key)
    {
        return loc;
    }
}
return -1;
}
void delete(int key)
{
int loc;
if(count==0)
    printf("\nHash table empty,can't delete");
else
{
    loc=search(key);
    if(loc!=-1)
    {
        hash[loc]=-1;
        count--;
        printf("\nKey deleted");
    }
    else
        printf("\nKey not found");
        
}
}
void display()
{
int i;
printf("\nThe elements in the hash table are:\n");
for(i=0;i<tsize;i++)
{
    printf("\nElement at position %d: %d\n",i,hash[i]);
}
}
int main()
{
int ch,key,loc,i;
printf("Enter the size of hash table:");
scanf("%d",&tsize);
for(i=0;i<tsize;i++)
{
    hash[i]=-1;
}
while(1)
{
    printf("\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\n");
    printf("Enter your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the key to be inserted:");
                scanf("%d",&key);
                insert(key);
                break;
        case 2: printf("Enter the key to be searched:");
                scanf("%d",&key);
                loc=search(key);
                if(loc!=-1)
                    printf("\nKey found at location %d",loc);
                else
                    printf("\nKey not found");
                break;
        case 3: printf("Enter the key to be deleted:");
                scanf("%d",&key);
                delete(key);
                break;
        case 4: display();
                break;
        case 5: exit(0);
        default: printf("Invalid choice");
    }
}
return 0;
}