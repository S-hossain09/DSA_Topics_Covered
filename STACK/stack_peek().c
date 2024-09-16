#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
    int size;
    int top;
    int *arr;

}stack;

int is_Full(stack * ptr_stack)
{
    if(ptr_stack->top == ptr_stack->size - 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int is_Empty(stack *ptr_stack)
{
    if(ptr_stack->top == -1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

void push(stack *ptr_stack, int value)
{
    if(is_Full(ptr_stack))
    {
        printf("Cannot Push %d, Stack is full\n",value);
    }

    else
    {
        ptr_stack->top++;
        ptr_stack->arr[ptr_stack->top] = value;
    }
}

void pop(stack *ptr_stack)
{
    if(is_Empty(ptr_stack))
    {
        printf("Cannot pop, Stack is empty\n");
    }

    else
    {
        ptr_stack->top--;
    }
}

void peek(stack* ptr_stack, int serial_no)
{
    int arr_index = ptr_stack->top - serial_no + 1;

    printf("%d ",ptr_stack->arr[arr_index]);
}


int main()
{
    stack *sp =(stack*)malloc(sizeof(stack));

    sp->size = 5;
    sp->top = -1;
    sp->arr = (int*)malloc(sp->size* sizeof(int));

    printf("\nThe stack has been created successfully \n");

    push(sp,12);
    push(sp,13);
    push(sp,14);
    push(sp,15);
    push(sp,16);
    push(sp,19);

    
    for(int i = 1; i <= sp->top + 1; i++)
    {
        peek(sp,i);
    }



    return 0;
}