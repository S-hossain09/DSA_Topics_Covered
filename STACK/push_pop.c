#include <stdio.h>
#include <stdlib.h>


// creating stack using array
typedef struct stack
{
    int size;
    int top;
    int * arr;
}stack;


int isFull(stack *ptr)
{
    if(ptr->top == ptr->size - 1)
    // it will check if it top is less than arr size - 1
    {
        return 1;
        // it will return 1(true) which is full.
    }

    else
    {
        return 0;
        // it will return 0(false) which is not full.
    }
}

int isEmpty(stack *ptr)
{
    if(ptr->top == - 1)
    // here -1 means it does not have any value store.
    {
        return 1;
        // it will return 1(true) which is empty.
    }

    else
    {
        return 0;
        // it will return 0(false) which is not empty.
    }
}

// push operation

void push(stack *ptr, int val)
{
    if(isFull(ptr))
    {
        printf("Cannot push . stack full \n");
    }
    // coz there is no empty space and top reached arr size - 1.

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

int pop(stack * ptr)
{
    if(ptr->top == -1)
    {
        printf("Cannot pop, stack is empty \n");
    }
    // coz top is -1, which is actually pointing towards nothing.
    // because there is no value stored

    else
    {
        ptr->top = ptr->top - 1;
    }
}

int main()
{
    stack *sp = (stack*)malloc(sizeof(stack));

    sp->size = 10;
    sp->top = -1;
    sp->arr = (int *)malloc((sp->size)*(sizeof(int)));

    printf("Stack has been successfully created \n\n");

    printf("Checking stack full or not %d\n", isFull(sp));
    printf("Checking stack empty or not %d\n", isEmpty(sp));

    printf("Pushed an element in stack \n");
    

    printf("Checking stack full or not %d\n", isFull(sp));
    printf("Checking stack empty or not %d\n", isEmpty(sp));



    return 0;
}