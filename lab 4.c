#include<stdio.h>
#include<stdlib.h>
void toh(int n, char s, char d, char t)
{
    if(n>1)
    {
        toh(n-1,s,t,d);
        printf("Move disk %d disc from %c to %c\n",n,s,d);
        toh(n-1,t,d,s);
    }
    else
    {
        printf("Move disk %d from %c to %c\n",n,s,d);
    }
}
int main(int n)
{
    
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    toh(n,'S','D','T');
    return 0;
}