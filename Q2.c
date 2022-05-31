/*Write a C program to display Armstrong Numbers of a given order within a given range.*/
#include<stdio.h>
#include<stdlib.h>
int order(int);
int armstrong(int);

void main()
{
    int i,n,m,o,flag=0;
    printf("Enter the first number of range:");
    scanf("%d",&n);
    printf("Enter the last number of range:");
    scanf("%d",&m);
    printf("Enter the order:");
    scanf("%d",&o);
    for(i=n;i<=m;i++)
    {
        if(order(i)==o && armstrong(i)==1)
        {
            printf("%d\n",i);flag=1;
        }
    }
    if(flag==0)
    {
        printf("No Armstrong numbers in given range\n");
    }
    
}

int order(int n)
{
    int c=0;
    while(n>0)
    {
        c++;n/=10;
    }
    return c;
}

int armstrong(int n)
{
    int sum=0,temp;
    temp=n;
    while(n>0)
    {
        sum+=(n%10)*(n%10)*(n%10);
        n/=10;
    }
    if(temp==sum)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
