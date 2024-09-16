/*
This code was written By Sahil Hossain
Date : 22/07/2023
Topic : Created a linked list 
Here the list traverse till NULL
the list prints 2 4 6 8 10 12 . . .
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

// below is the function for traversing the list till end
void linkedlist_traversal(struct Node* ptr) 
{
  while(ptr != NULL) // IT WILL PRINT UNTIL NULL IS FOUND
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}

/*
So the things this function will do is :

it will create a new struct node* pointer, head.
head will have some space allocated to heap memory
head will point to the next head address
as the next head hasn't been freed from heap memory,
it is possible to print even saying head = head;
*/

//Below is the function for inserting data at HEAD
struct Node* insert_at_first(struct Node* head, int data_to_insert)
{
    struct Node* ptr;
    ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data_to_insert;

    return ptr;
}
//Below is the function for inserting data at anywhere in the middle

/*
  So the things this function will do is 

  it takes head, data, index as agrument for the 
  struct node pointer function

  takes index as argument because it create node 
  exactly before index-1;

  it creates a temporary node , then store 
  address of index - 1; and later passes the 
  address to permanent ptr function

  then the temporary next address becomes the address of the 
  permanent ptr;

  and it returns head not ptr because
  if we return ptr , the node will start from newly added
  data, so we are returning head, to start the node from 
  begining
*/


struct Node* insert_at_index(struct Node* head, int data, int index)
{
  struct Node* ptr;
  ptr = (struct Node*)malloc(sizeof(struct Node));

  struct Node* temporary_ptr;
  
  temporary_ptr = head;

  int i = 1;

  while(i != index - 1)
  {
    temporary_ptr = temporary_ptr->next;
    i++;
  }

  ptr->data = data;
  ptr->next = temporary_ptr->next;
  temporary_ptr->next = ptr;

  return head;

}


//Below is the function for inserting data at end
/*
  So the things this function will do is 
  it will work as the index insertion

  it will take a temp ptr , and run it till != NULL
  when reaches null, it will point the node before null

  after loop, temp ptr will point to permanent ptr
  and permanent ptr will point to null

  then return head
*/

struct Node* insert_at_end(struct Node* head, int data)
{
  struct Node* ptr;
  struct Node* temporary_ptr = head;

  ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;

  

  while (temporary_ptr->next != NULL)
  {
    temporary_ptr = temporary_ptr->next;
  }
  temporary_ptr->next = ptr;
  ptr->next = NULL;
  
  return head;
}

//Below is the function for inserting data at end
/*
  so the things this node will do is :
  this will take a prev node 
  our ptr will point to prev node.
  prev node will point to ptr;
*/

struct Node* insert_after_node(struct Node* head, struct Node* prev_node, int data)
{
  struct Node* ptr;
  ptr = (struct Node*)malloc(sizeof(struct Node));
  ptr->data = data;

  ptr->next = prev_node->next;
  prev_node->next = ptr;

  return head;

}

// main function starts
int main()
{
  //declaration part
  struct Node * head;
  struct Node * second;
  struct Node * third;
  struct Node * forth;
  struct Node * fifth;
  struct Node * sixth;
  
  
  //Allocate memory for nodes in the linked list in heap
  head = (struct Node*)malloc(sizeof(struct Node));
  
  second = (struct Node*)malloc(sizeof(struct Node));
  
  third = (struct Node*)malloc(sizeof(struct Node));

  forth = (struct Node*)malloc(sizeof(struct Node));

  fifth = (struct Node*)malloc(sizeof(struct Node));

  sixth = (struct Node*)malloc(sizeof(struct Node));
  
  //linked first and second nodes
  head->data = 2;
  head->next = second;
  
  //linked second and third nodes
  second->data = 4;
  second->next = third;
  
  //linked third and forth nodes
  third->data = 6;
  third->next = forth;
  
  //linked forth and fifth nodes
  forth->data = 8;
  forth->next = fifth;
  
  //linked fifth and sixth nodes
  fifth->data = 10;
  fifth->next = sixth;
  
  //linked list terminated at sixth nodes
  sixth->data = 12;
  sixth->next = NULL;

  printf("Data of the linked list before insertion : \n");

  linkedlist_traversal(head);

  printf(". . . \n");

  printf("\nData of the linked list after all the insertion : \n");

  //insert at first functin
  head = insert_at_first(head, 69);

  //insert at index
  head = insert_at_index(head, 69, 4);

  //insert at end
  head = insert_at_end(head, 69);

  //insert at after node
  insert_after_node(head, fifth, 69);

  //called the traversal linked list 
  linkedlist_traversal(head);

  printf(". . .");


    
  return 0;
}