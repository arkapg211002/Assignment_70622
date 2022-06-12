/*
Open cmd move to the folder where you want keep the program file as well as the two txt files 
then run the program and see the output.

C:\Users\user\Desktop>mycopy a.txt b.txt
*/



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void main(int argc,char *argv[])
{
    FILE *fs,*ft;
    char c;
    if(argc!=3)
    {
        printf("enter the correct number of arguments");
        exit(0);
    }
    fs=fopen(argv[1],"rb");
    if(fs==NULL)
    {
        printf("file not found");
        exit(0);
    }
    ft=fopen(argv[2],"wb");
    if(ft==NULL)
    {
        printf("file not found");
        exit(0);
    }
    while((c=fgetc(fs))!=EOF)
    {
        fputc(c,ft);
    }
    fclose(fs);
    fclose(ft);
}