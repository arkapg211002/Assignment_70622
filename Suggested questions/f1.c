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
    char ans;
    f=fopen("f1.dat","wb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    do
    {
        printf("Enter name:");
        scanf("%s",r.name);
        printf("Enter age:");
        scanf("%d",&r.age);
        printf("Enter marks:");
        scanf("%d",&r.marks);
        fwrite(&r,sizeof(RECORD),1,f);
        printf("Do you want to continue(y/n):");
        fflush(stdin);
        scanf("%c",&ans);
    }while(ans=='y');
    fclose(f);
}