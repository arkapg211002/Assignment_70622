#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct modify
{
    char name[10];
    int marks;
    int age;
}RECORD;
void main()
{
    FILE *f;
    RECORD r,r1,r2,r3;
    int flag=0;
    char ans,name[10];
    f=fopen("s.DAT","wb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    do
    {
        printf("enter the name of the student:");
        scanf("%s",r.name);
        printf("enter the age of the student:");
        scanf("%d",&r.age);
        printf("enter the marks of the student:");
        scanf("%d",&r.marks);
        fwrite(&r,sizeof(RECORD),1,f);
        printf("do you want to continue(y/n):");fflush(stdin);
        scanf("%c",&ans);
    }while(ans=='y');
    fclose(f);
    f=fopen("s.DAT","rb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    while(fread(&r1,sizeof(RECORD),1,f)==1)
    {
        printf("%s\t%d\t%d\n",r1.name,r1.age,r1.marks);
    }
    fclose(f);

    printf("\n");
    printf("enter the name of the student to be modified");
    scanf("%s",name);
    f=fopen("s.DAT","rb+");
    if(f==NULL)
    {
        printf("file not found");
        exit(0);
    }
    while(fread(&r2,sizeof(RECORD),1,f))
    {
        if(strcmpi(r2.name,name)==0)
        {
            printf("enter the new age of the student");
            scanf("%d",&r2.age);
            printf("enter the new marks of the student");
            scanf("%d",&r2.marks);
            fseek(f,-sizeof(RECORD),1);
            fwrite(&r2,sizeof(RECORD),1,f);flag=1;
            break;
        }
    }
    if(flag==0)
    {
        printf("record not found");
    }
    fclose(f);
    printf("\n");
    f=fopen("s.DAT","rb");
    if(f==NULL)
    {
        printf("file not found");
        exit(0);
    }
    while(fread(&r3,sizeof(RECORD),1,f))
    {
        printf("%s\t%d\t%d\n",r3.name,r3.age,r3.marks);
    }
    fclose(f);
}