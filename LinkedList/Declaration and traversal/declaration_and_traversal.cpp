/*
This code was written By Sahil Hossain
Date : 22/07/2023
Topic : Created a linked list 
Here the list traverse till NULL
the list prints 2 4 6 8 10 12 . . .
*/

#include <stdio.h>
#include <stdlib.h>

using namespace std;


//structure node for linked list . 
//contains one data and next link pointer
struct Node
{
    int data;
    struct Node * next;
};

// below is the function for traversing the list till end
// point it to head , to make the traversal
void linkedlist_traversal(struct Node* ptr) 
{
  while(ptr != NULL) // IT WILL PRINT UNTIL NULL IS FOUND
  {
    printf("%d ", ptr->data);
    ptr = ptr->next;
  }
}


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

  printf("Data of the linked list : \n");

  // called traversing function below
  linkedlist_traversal(head);

  printf(". . .");
    
  return 0;
}