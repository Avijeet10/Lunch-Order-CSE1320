//Name: Avijeet Adhikari 
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "ListLib.h"
#include <ctype.h>
#define Maxsize 20
#define MAXSIZE 100
void replacevertical(char [][Maxsize],int,int, int,char);
void replacehorizontal(char [][Maxsize],int,int, int,char);
void print(int,char [][Maxsize]);
void printletter(int,char [][Maxsize],char);
void ReadCmdLine(char *argv[],char name[], char value[] );
int Readinput(FILE **inputfile,node **LLH);

int main(int argc, char *argv[])
{
    node *LinkedListHead=NULL;
    char inputfile[Maxsize];
    char cmd[Maxsize];
    ReadCmdLine(argv,"DCFILE=",cmd);
    strcpy(inputfile,cmd);
    FILE *input;
    input=fopen(inputfile,"r");
    
    int Nodes= Readinput(&input,&LinkedListHead);
    if(Nodes>0)
    {
        char array [Maxsize][Maxsize];
        char l;
        printf("\nEnter the Background character ");
        scanf(" %c",&l);
        printletter(Maxsize,array,l);
        
        char letters [3];
        char tool [Maxsize];
        printf("\nPLease enter 1-3 letters ");
        scanf("%s",letters);
        int length;
        length=strlen(letters);
        while (length>3)
        {
            printf("\nNot a valid entry. PLease enter 1-3 letters ");
            scanf("%s",letters);
            length=strlen(letters);
            
        }
        int i;
        int j;
        for (i=0, j=0; i<length; i++)
        {
            node *endnode;
            endnode=LinkedListHead;
            
            while (endnode != NULL)
            {
                char type,printtype,cmd1,cmd2,cmd3,cmd4;
                int hzntl,vert,pnt;
                
                search(&endnode,tool,toupper(letters[i]));
                sscanf(tool,"%c %*c %d %*c %d %*c %d %*c %c",&type,&hzntl,&vert,&pnt,&printtype) ;
                type= tolower(type);
                if (type=='p'||type=='v'||type=='h')
                {
                    if(hzntl>=Maxsize || vert+j>=Maxsize)
                    {
                        printf("That drawing command is out of range!!!\n");
                        
                    }
                    else
                    {
                        if(type=='p')
                        {
                            array[hzntl][vert+j]=printtype;
                            
                        }
                        
                        if(type=='v')
                        {
                            if(pnt > (Maxsize-hzntl)) //checking for the available vertical spaces
                            {
                                printf("Drawing command is out of range!!!\n");
                                
                            }
                            else
                            {
                                replacevertical(array,hzntl,vert+j,pnt,printtype);
                                
                            }
                        }
                        
                        if(type=='h')
                        {
                            if(pnt>(Maxsize-vert+j))
                            {
                                printf("Drawing command is out of range!!!\n");
                                
                            }
                            else
                            {
                                replacehorizontal(array,hzntl,vert+j,pnt,printtype);
                                
                            }
                        }
                        
                    }
                    
                    
                }
                
            }
            j=j+7;
            
        }
        print(Maxsize,array);
        
    }
    return 0;
}


void replacevertical(char array[][Maxsize],int hzntl,int vert, int pnt,char type)
{
    int i;
    int j;
    for(i=0; i<pnt; i++)
    {
        for (j=0; j<pnt; j++)
        {
            array[hzntl+i][vert]=type;
        }
        
    }
}
void replacehorizontal(char array[][Maxsize],int hzntl,int vert, int pnt,char type)
{
    int i;
    int j;
    for(i=0; i<pnt; i++)
    {
        for (j=0; j<pnt; j++)
        {
            array[hzntl][vert+i]=type;
        }
    }
}

void printletter(int n,char array[][Maxsize],char letter)
{
    int i;
    int j;
    for(i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            array[i][j]=letter;
        }
        
    }
}


void ReadCmdLine(char *argv[],char name[], char value[] )
{
    int i=0;
    while(argv[++i]!=NULL)
    {
        if(!strncmp(argv[i],name,strlen(name)))
        {
            strcpy(value,strchr(argv[i],'=')+1);
        }
    }
    return;
}

int Readinput(FILE **inputfile,node **LinkedListHead)
{
    if(*inputfile==NULL)
    {
        perror("Sorry could not open the file");
        exit(0);
    }
    int i=0;
    char input[MAXSIZE];
    char *token;
    char letter;
    char copy[Maxsize];
    while(fgets(input,sizeof(input)-1,*inputfile)!= NULL)
    {
            token=strtok(input,"|");
            letter=(*token);
            token=strtok(NULL,"\n");
            strcpy(copy,token);
            Addnode(letter,copy,&(*LinkedListHead));
            i++;
    }
    fclose(*inputfile);
    return i;
}

void print(int n,char array[][Maxsize])
{
    
    printf("\n\n");
    int i;
    int j;
    for(i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            printf("%c ",array[i][j]);
        }
        printf("\n");
    }
}
