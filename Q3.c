/*Write  C functions to evaluate the following series without using standard math functions
(I) exponential series
(ii) sine series
(iii) cosine series*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int factorial(int n);
float exponential(float x);
float sine(float x);
int factorial(int n)
{
    int i,f=1;
    if(n==0) return 1;
    else
    {
        for(i=1;i<=n;i++)
        {
            f=f*i;
        }
        return f;
    }
    
}
float exponential(float x)
{
    float s=0.0,t;
    int i=0;
    while(i>=0)
    {
        t=pow(x,i)/(float)factorial(i);
        if( t<0.0000000001)
        {
            break;
        }
        s=s+t;i++;
    }
    return s;
}
float sine(float n)
{
    float s=0.0,t,x=n*22/(7*180);
    int i=0;
    if(x==0)return 0;
    while(i>=0)
    {
        t=pow(x,2*i+1)*pow(-1.0,i)/(float)factorial(2*i+1);
        if((t>0 && t<0.0000000001)||(t<0 && t>-0.0000000001))
        {
            break;
        }
        
        s=s+t;i++;
    }
    return s;
}
float cosine(float x)
{
    float s=0.0,t,n=((22/7)*x)/180;
    int i=0,k=0;
    if(n==0)return 1;
    while(k>=0)
    {
        t=pow(n,i)*pow(-1.0,k)/(float)factorial(i);
        if((t>0 && t<0.0000000001)||(t<0 && t>-0.0000000001))
        {
            break;
        }
        
        s=s+t;k+=1;i+=2;
    }
    return s;
}
void main()
{
    float x,n;
    printf("Enter the value of x:");
    scanf("%f",&x);
    printf("The exponential series is %f\n",exponential(x));
    printf("The sine series is %f\n",sine(x));
    printf("The cosine series is %f\n",cosine(x));
}


