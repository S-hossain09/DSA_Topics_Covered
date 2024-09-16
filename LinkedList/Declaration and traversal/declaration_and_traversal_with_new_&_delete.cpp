#include <iostream>
#include <stdio.h>

using namespace std;

//structure node for linked list . 
//contains one data and next link pointer
struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(NULL) {};
    // Constructor to create a new Node with the given 'value' and set 'next' pointer to NULL.

};


// below is the function for traversing the list till end
// point it to head , to make the traversal
void linked_traversal(Node* head)
{
    Node* ptr = head;

    while(ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

// below is the function for deleting the list till end
// point it to head , to make the delete happen from head till end
void delete_linkedList(Node* head)
{
    Node* current = head;

    while(current->next != NULL)
    {
        Node* next_node = current->next;
        delete current;
        current = next_node;
    }
}

int main()
{
    // declaring part 
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    Node* forth = NULL;
    Node* fifth = NULL;
    Node* sixth = NULL;

    //initializing and creating memory in heap with new
    // this is how it creates memory in heap "data type = new same data type(value)"
    head = new Node(2);
    second = new Node(4);
    third = new Node(6);
    forth = new Node(8);
    fifth = new Node(10);
    sixth = new Node(12);

    head->next = second;

    second->next = third;

    third->next = forth;

    fifth->next = sixth;

    sixth->next = NULL;

    linked_traversal(head);

    delete_linkedList(head);


    return 0;
}