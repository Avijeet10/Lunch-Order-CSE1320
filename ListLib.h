//Name: Avijeet Adhikari 

#ifndef _LISTLIB_H
#define _LISTLIB_H
#define size 20
typedef struct node{
    struct node *next_ptr ;
    char letter;
    char DC[size];
    
}node;


void Addnode(char letter, char DC[], node **LinkedListHead);
void search(node **end, char add_drawcommand[], char c);
#endif
