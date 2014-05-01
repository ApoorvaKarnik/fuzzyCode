#include <stdio.h>
#include <stdlib.h>

#ifndef NUMNODE
#define NUMNODE 10
#endif

struct node
{
    int number;
    struct node* prev;
    struct node* next;
};
void traverse(struct node* list_ptr)
{
    printf("Now traversing linked list from %d\n",list_ptr->number);
    while(list_ptr != NULL)
    {
        printf("Node# %d\n", list_ptr->number);
        list_ptr=list_ptr->next;
    }
}
void reverse(struct node* list)
{   
    printf("Reversing a linked list\n");
    struct node* curr = list;
    struct node* prev = NULL;
    struct node* next = list->next;
    while(curr != NULL)
    {
      next = curr->next;  
      curr->next = prev;
      if (prev != NULL)
        printf("Reversing a linked list curr %d->%d\n",curr->number,prev->number);
      prev =  curr;
      curr = next;
    }
}
int main()
{
    printf("First create a linked list\n");
    int i = 0;
    struct node* node_ptr, *first, *last;
    node_ptr = (struct node*)malloc(sizeof(struct node));
    first = node_ptr;
    for (i=0; i< NUMNODE; i++)
    {
      node_ptr->prev = NULL;
      node_ptr->number = i;
      node_ptr->next = (struct node*)malloc(sizeof(struct node));
      node_ptr = node_ptr->next;
    }
    node_ptr->next = NULL;
    node_ptr->prev = NULL;
    node_ptr->number = NUMNODE;
    last = node_ptr;
    
    traverse(first);
    reverse(first);
    traverse(last);
    return 1;
}
