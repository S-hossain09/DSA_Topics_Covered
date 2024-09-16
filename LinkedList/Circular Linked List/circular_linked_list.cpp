/*
    so In this code , we will be learning about
    circular linked list

    Circular Linked List : Instead of pointing to Null, the last
    node will point to head
*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

 // point it to head , to make the traversal

//structure node for linked list . 
//contains one data and next link pointer
struct Node
{
    int data;
    struct Node * next;
};

// below is the function for traversing the list till I manually stop them
/*
    so the things function will do is 
    ptr will point it to head and move to next

    we are running a do while because
    
    do
    {
        //code
    } while(false)

    this loop will run one time before checking the condition

    instead of do while if we had used while loop, it wouldnt have 
    run because

    "
    ptr = head;
    while(ptr != head)
    {
        //code
    }

    it wouldnt have run because ptr is already head
    "
    

*/
void linkedlist_traversal(struct Node* head) 
{
    struct Node* ptr;
    ptr = head;

    do
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

struct Node* insert_at_first(struct Node* head, int data)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node* p;
    p = head->next;

    while(p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}


int main()
{
  //declaration part
  struct Node * head;
  struct Node * second;
  struct Node * third;
  struct Node * forth;


  
  
  //Allocate memory for nodes in the linked list in heap
  head = (struct Node*)malloc(sizeof(struct Node));
  
  second = (struct Node*)malloc(sizeof(struct Node));
  
  third = (struct Node*)malloc(sizeof(struct Node));

  forth = (struct Node*)malloc(sizeof(struct Node));
  
  //linked first and second nodes
  head->data = 2;
  head->next = second;
  
  //linked second and third nodes
  second->data = 4;
  second->next = third;
  
  //linked third and forth nodes
  third->data = 6;
  third->next = forth;
  
  //linked forth and pointing to head again
  forth->data = 8;
  forth->next = head;

  printf("before inserting element in the linked list : \n");

  // linked list before inserting data
  linkedlist_traversal(head);

  printf(". . . \n \n");

printf("after inserting element in the linked list : \n");

  // linked list after inserting data
  head = insert_at_first(head, 14);
  linkedlist_traversal(head);

  printf(". . .");
    
  return 0;
}