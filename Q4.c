/*Write a C program to solve a Quadratic Equation.*/
#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c,d,x1,x2;
    printf("Enter the coefficients of the quadratic equation:");
    scanf("%f%f%f",&a,&b,&c);
    d=b*b-4*a*c;
    if(d>0)
    {
        x1=(-b+sqrt(d))/(2*a);
        x2=(-b-sqrt(d))/(2*a);
        printf("The roots of the quadratic equation are %f and %f\n",x1,x2);
    }
    else if(d==0)
    {
        x1=-b/(2*a);
        printf("The roots of the quadratic equation are %f and %f\n",x1,x1);
    }
    else
    {
        printf("The roots of the quadratic equation are imaginary\n");
    }
    return 0;
}
