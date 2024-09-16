#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

void linear_search(struct node* head, int searching_value)
{
    while(head->data != searching_value && head->next != NULL)
    {
        head = head->next;
    }
}

int main()
{
    struct node* first_node = (struct node*)malloc(sizeof(struct node));
    struct node* second_node = (struct node*)malloc(sizeof(struct node));
    struct node* third_node = (struct node*)malloc(sizeof(struct node));
    struct node* forth_node = (struct node*)malloc(sizeof(struct node));

    // giving value to first node and pointing it to second.
    first_node->data = 1;
    first_node->next = second_node;

    // giving value to second node and pointing it to third.
    second_node->data = 2;
    second_node->next = third_node;

    // giving value to third node and pointing it to forth.
    third_node->data = 3;
    third_node->next = forth_node;

    // giving value to forth node and pointing it to NULL.
    forth_node->data = 4;
    forth_node->next = NULL;


    linear_search(first_node, 2);



    return 0;
}