//Name: Avijeet Adhikari 

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ListLib.h"

void Addnode(char letter, char DC[], node **LinkedListHead)
{
    node *TempPtr, *NewNode;
    
    NewNode=malloc(sizeof(node));
    NewNode->letter=letter;
    strcpy(NewNode->DC,DC);
    NewNode->next_ptr =NULL;
    
    if(*LinkedListHead ==NULL)
    {
        *LinkedListHead=NewNode;
    }
    else
    {
        TempPtr=*LinkedListHead;
        
        
        while(TempPtr->next_ptr!=NULL)
        {
            TempPtr=TempPtr->next_ptr;
        }
        TempPtr->next_ptr=NewNode;
    }
}
void search(node **end, char add_drawcommand[], char c)
{
    while ((*end)!=NULL)
    {
        if((*end)->letter==c)
        {
            strcpy(add_drawcommand,(*end)->DC);
            *end=(*end)->next_ptr;
            return;
        }
        *end=(*end)->next_ptr;
    }
}



