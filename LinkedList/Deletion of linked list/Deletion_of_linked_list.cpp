/*I will create a linked list, then
I will delete the linked list items

linked list 1 3 5 7 9;
*/

#include <iostream>
#include <stdio.h>

using namespace std;

//creatin Node for linked List
struct Node 
{
    int data;
    struct Node* next_data;
};

//below is the function for linked list traversal
void linked_list_traversal(struct Node* ptr)
{
    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next_data;
    }
}

//Deletion of 1st element of linked list
/*
so the things this function does :
it creates a new ptr and point to head
then assign head to head.next 
and free ptr = previous head*/

struct Node* deletion_of_first_element(struct Node* head)
{
    struct Node* ptr;
    ptr = head;

    head = head->next_data;
    free(ptr);

    return head;
}

//deletion of element in between somewhere
/*
so the things this function will do is :
its taking an index as argument
it means starting from 0 to nth term of linked list
it will delete the indexed element

it has p and q
p pointing to head
q pointing to head next . which is, q comes after p

runs a loop till index - 1;
for this loop q stands on the element needs to be deleted
at first we assign p and q at the position loop stopped

then we assign p next = q next
then delete q

and return head
*/
struct Node* deletion_of_in_betn(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head->next_data;

    for(int i = 0; i < (index - 1); i++)
    {
        p = p->next_data;
        q = q->next_data;
    }
    p->next_data = q->next_data;
    free(q);

    return(head);
}

//deletion of the last node
/*
    it has p and q
    p pointing to head
    q pointing to head next . which is, q comes after p

    running a loop , where the loop will run until 
    q.next = NULL

    for this loop q.next points to NULL
    at first we assign p and q at the position loop stopped

    then we say p next = NULL 
    and delete q then return head 
*/
struct Node* deletion_of_the_last_node(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next_data;

    int i = 0;
    while(q->next_data != NULL)
    {
       p = p->next_data;
       q = q->next_data;
       i++;
    }
    p->next_data = NULL;
    free(q);

    return head;

}

// below is the function to delete element with a given value
/*
    so the things this function will do is :

    it has p and q
    p pointing to head
    q pointing to head next . which is, q comes after p

    it runs a loop until q data != value and q next != NULL
    at first we assign p and q at the position loop stopped

    when data is found it goes to if statement 
    and assign p next = q next
    then delete q

    return head
*/
struct Node* deletion_at_given_value(struct Node* head, int value)
{
    struct Node* p;
    struct Node* q;

    p = head;
    q = head->next_data;

    while(q->data != value && q->next_data != NULL)
    {
        p = p->next_data;
        q = q->next_data;
    }
    
    if(q->data == value)
    {
        p->next_data = q->next_data;
        free(q);
    }

    return head;
}

int main()
{   
    //Declaration of the nodes
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *forth;
    struct Node *fifth;

    //creating node in heap memory
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    forth = (struct Node*)malloc(sizeof(struct Node));
    fifth = (struct Node*)malloc(sizeof(struct Node));

    //linking the nodes 
    // linking the head and second
    head->data = 1;
    head->next_data = second;

    //linking the second and third
    second->data = 3;
    second->next_data = third;

    //linking the third and forth
    third->data = 5;
    third->next_data = forth;

    //linking the forth and fifth
    forth->data = 7;
    forth->next_data = fifth;

    //linking the fifth and pointing to NULL
    fifth->data = 9;
    fifth->next_data = NULL;

    /*
    calling the traversal function of before
    deleting elements of linked list
    */
   printf("Linked list before deletion : \n");
   linked_list_traversal(head);

   printf("\n \n");

   /*
   called deletion_of_first_element function 
   to delete the first element of linked list
   */

    //called the deletion_of_first_element
    head = deletion_of_first_element(head); 

    //called the deletion_of_in_betn
    head = deletion_of_in_betn(head,2); 

    //called the deletion_of_the_last_node
    head = deletion_of_the_last_node(head); 

    //called the deletion_at_given_value
    head = deletion_at_given_value(head,4); 


    printf("Linked list after deletion : \n");
    linked_list_traversal(head);

    printf("\n");

    return 0;
}