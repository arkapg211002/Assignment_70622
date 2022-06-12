#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    char name[10];
    int age;
    int marks;
}RECORD;
void main()
{
    FILE *f;
    RECORD r;
    f=fopen("f1.dat","rb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    while(fread(&r,sizeof(RECORD),1,f))
    {
        printf("%s\t%d\t%d\n",r.name,r.age,r.marks);
    }
    fclose(f);
}