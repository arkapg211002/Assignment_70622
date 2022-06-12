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
    RECORD *p;
    char ans;
    p=(RECORD *)malloc(sizeof(RECORD));
    f=fopen("f2.dat","wb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    do
    {
        printf("Enter name:");fflush(stdin);
        scanf("%[^\n]s",p->name);
        printf("Enter age:");fflush(stdin);
        scanf("%d",&p->age);
        printf("Enter marks:");fflush(stdin);
        scanf("%d",&p->marks);
        fwrite(p,sizeof(RECORD),1,f);
        printf("Do you want to continue(y/n):");
        fflush(stdin);
        scanf("%c",&ans);

    }while(ans=='y');
    fclose(f);
}