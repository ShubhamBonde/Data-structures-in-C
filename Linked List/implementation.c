//LINKED LIST IMPLEMENTATION.
#include<stdio.h>
#include<stdlib.h>
// Create a NODE
typedef struct node
{
    int number;
    struct node *next;
}node;
int main()
{
    node *list = NULL;

    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        return 1;
    }

    n -> number = 1;
    n -> next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list);
        return 1;
    }
    n -> number = 2;
    n -> next = NULL;
    list -> next = n;

    n = malloc(sizeof(node));
    if (n == NULL)
    {
        free(list->next);
        free(list);
        return 1;
    }
    n -> number = 3;
    n -> next = NULL;
    list -> next-> next = n;

    //Printing linked list
    for (node *ptr = list; ptr != NULL; ptr = ptr -> next)
    {
        printf("n = %i and its memory address is %x it is pointing at %x\n", ptr->number,&ptr->number,ptr->next);
    }

    while ( list != NULL)
    {
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}

/*
* ONE OF THE OUTPUTS OF THE PROGRAM:
* n = 1 and its memory address is cc19e8 it is pointing at cc19f8
* n = 2 and its memory address is cc19f8 it is pointing at cc1a08
* n = 3 and its memory address is cc1a08 it is pointing at 0 (NULL)
*/