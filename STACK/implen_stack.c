#include <stdio.h>
#include <stdlib.h>

// Define a structure for stack
typedef struct stack {
    int size;  // The maximum size of the stack
    int top;   // The index of the topmost element in the stack
    int *arr;  // Pointer to an array that will hold the stack elements
} stack;

// Function to check if the stack is empty
int isEmpty(stack *ptr) {
    if (ptr->top == -1) {  // If top is -1, stack is empty
        return 1;
    } else {
        return 0;
    }
}

// Function to check if the stack is full
int isFull(stack *ptr) {
    if (ptr->top == (ptr->size - 1)) {  // If top equals size-1, stack is full
        return 1;
    } else {
        return 0;
    }
}

int main() {
    // Declare a pointer to a stack structure
    stack *st;

    // Dynamically allocate memory for the stack structure
    st = (stack *)malloc(sizeof(stack));

    // Initialize the stack
    st->size = 80;        // Set the size of the stack
    st->top = -1;         // Initialize top to -1 indicating the stack is empty
    st->arr = (int *)malloc(st->size * sizeof(int));  // Allocate memory for the stack elements

    // Push an element onto the stack
    st->arr[0] = 12;  // Push the value 12 at index 0
    st->top++;        // Increment top to indicate an element has been added

    // Check if the stack is full
    if (isFull(st)) {
        printf("Stack is full\n");
    } else {
        printf("Stack is not full\n");
    }

    // Free allocated memory
    free(st->arr);
    free(st);

    return 0;
}
