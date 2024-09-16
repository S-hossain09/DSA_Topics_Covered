#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list
{
    int data;
    struct linked_list *next;
} node;

node *top = NULL;

int isEmpty(node *top);
int isFull(node *top);
node *push_in_LL_by_stack(node *top, int value);
int pop_out_LL_by_stack(node *top);
int peek_element_by_index(int index);
void linked_list_traversal(node *top);

int main()
{
    system("clear");

    top = push_in_LL_by_stack(top, 56);
    top = push_in_LL_by_stack(top, 54);
    top = push_in_LL_by_stack(top, 12);
    top = push_in_LL_by_stack(top, 14);
    top = push_in_LL_by_stack(top, 11);

    // linked_list_traversal(top);

    printf("The value is %d\n",peek_element_by_index(1));    

    return 0;
}

int isEmpty(node *top)
{
    if (top == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int isFull(node *top)
{
    node *p = (node *)malloc(sizeof(node));

    if (p == NULL)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

node *push_in_LL_by_stack(node *top, int value)
{
    if (isFull(top))
    {
        printf("Stack has overflow\n");
    }

    else
    {
        node *temp = (node *)malloc(sizeof(node));

        temp->data = value;
        temp->next = top;
        top = temp;

        return top;
    }
}

int pop_out_LL_by_stack(node *receiving_top)
{
    if (isEmpty(receiving_top))
    {
        printf("Stack is already empty\n");
    }

    else
    {
        node *deleting_with_this = receiving_top;

        top = (receiving_top)->next;
        // let suppose the data is ascending down
        // the next element is below the top data

        int checking_pop_value = deleting_with_this->data;

        free(deleting_with_this);

        return checking_pop_value;
        // we will return this value to the calling function
        // because we will display this value by using print
        // to see which data actually popped.
    }
}

int peek_element_by_index(int index)
{
    node* ptr = top;

    for(int i = 0; (i < index - 1 && ptr!=NULL); i++)
    {
        ptr = ptr->next;
    }

    if(ptr != NULL)
    {
        return ptr->data;
    }

    else
    {
        return -1;
        /*
            it reached NULL, but did not find values according 
            to index. means there might be some problem in index
            giving
        */
    }
}

void linked_list_traversal(node *ptr)
{
    printf("Element :\n");
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}