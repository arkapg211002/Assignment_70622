#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
typedef struct
{
    char name[10];
    int age;
    int marks;
}RECORD;
void sortnameage(RECORD *p,int n)
{
    int i,j,flag;
    RECORD temp;
    for(i=0,flag=1;i<n-1 && flag;i++)
    {
        for(j=0,flag=0;j<n-i-1;j++)
        {
            if(strcmpi(p[j].name,p[j+1].name)>0 || (strcmpi(p[j].name,p[j+1].name)==0 && p[j].age>p[j+1].age))
            {
                
                temp=p[j];
                p[j]=p[j+1];
                p[j+1]=temp;
                flag=1;
            }
        }
    }
}
void main()
{
    FILE *f,*f1,*f2,*f3;
    RECORD *p,*p1,r,r1;
    char ans;
    int n,i=0;
    p=(RECORD *)malloc(sizeof(RECORD));
    f=fopen("sat.dat","wb");
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
    printf("the file is created\n");
    f=fopen("sat.dat","rb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    while(fread(&r1,sizeof(RECORD),1,f))
    {
        printf("%s\t%d\t%d\n",r1.name,r1.age,r1.marks);
    }
    fclose(f);


    printf("The sorted records are:\n");



    f=fopen("sat.dat","rb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    fseek(f,0,2);
    n=ftell(f)/sizeof(RECORD);
    p1=(RECORD *)malloc(n*sizeof(RECORD));
    rewind(f);
    while(fread(p1+i,sizeof(RECORD),1,f))
    {
        i++;
    }
    fclose(f);
    sortnameage(p1,n);
    f=fopen("sat2.dat","wb");
    if(f==NULL)
    {
        printf("File not found");
        exit(0);
    }
    for(i=0;i<n;i++)
    {
        fwrite(p1+i,sizeof(RECORD),1,f);
    }
    free(p1);
    fclose(f);
    f=fopen("sat2.dat","rb");
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