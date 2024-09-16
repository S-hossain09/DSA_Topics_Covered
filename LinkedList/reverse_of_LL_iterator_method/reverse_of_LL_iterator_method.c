#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node; 


node* creation_ll(int num)
{
    node* temp_node = NULL;
    node* head = NULL;
    node* ptr = NULL;

    printf("Enter data of %d element.\n",num);

    for(int i = 0; i < num; i++)
    {
        temp_node = (node*)malloc(sizeof(node));

        scanf("%d",&(temp_node->data));
        temp_node->next = NULL;

        if(head == NULL)
        {
            head = temp_node;
        }
        else
        {
            ptr = head;

            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }

            ptr->next = temp_node;
        }
    }

    return head;
}

void linked_list_traversal(node* ptr)
{
    printf("Element : \n");
    while(ptr != NULL)
    {   
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}


node* Reversed(node* head)
{
    node* current = head, *prev = NULL, *next = NULL;
    /*
        we will take three things as node* .
        for example:
                       1          2               
            ^          ^          ^               
           prev     current     next        
        we will :
        next = current->next;
        we will assign the next value to current next.

        then will:
        current->next = prev;
        this will make the direction shift to prev. 
        and make it free from pointing to next.

        then will:
        prev = current;
        this will make prev pointing to current.
        and it will repeat until current reaches to NULL.

        then will:
        current = next;
        this will make current pointing to next.
        and it will repeat until current reaches to NULL.

        when current reaches null. then linked list 
        will start from the end. which is now prev.

        after all this we will make the head = prev.

        now it successfully reversed.

    */
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;

    return head;
}



int main()
{
    node* head = NULL;

    head = creation_ll(5);

    printf("printing the data : \n");
    linked_list_traversal(head);

    printf("\n\n");

    printf("Reversed data : \n");
    head = Reversed(head);
    linked_list_traversal(head);



    return 0;
}