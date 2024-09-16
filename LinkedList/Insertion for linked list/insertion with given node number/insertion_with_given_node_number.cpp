#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Node 
{
    int data;
    struct Node* next;
};

// below is the function for traversing the list till end
void linkedlist_traversal(struct Node* ptr) 
{
  while(ptr != NULL) // IT WILL PRINT UNTIL NULL IS FOUND
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

//below the function for creating linked list for given n
/*
so the things it will do is
create a tail node then point it to NULL

it will check if head is empty or not
if empty then head = that node

else a new ptr will move until NULL
then new ptr next = that node

then return head

*/
struct Node* creation_of_linkedlist(int n)
{
    struct Node* head = NULL;
    struct Node* tail = NULL;
    struct Node* p = NULL;
    for(int i = 0; i<n; i++)
    {
        tail = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter the data for %d : ",(i+1));
        scanf("%d",&(tail->data));
        tail->next = NULL;

        if(head == NULL)
        {
            head = tail;
        }
        else
        {
            p = head;
            while(p->next != NULL)
            {
                p = p->next;
            }
            p->next = tail;
        }
    }

    return head;
}


int main()
{
    int num_of_nodes;

    struct Node* head = NULL;

    printf("Enter Number of nodes : ");
    scanf("%d",&num_of_nodes);

    head = creation_of_linkedlist(num_of_nodes);
    linkedlist_traversal(head); 


    return 0;
}