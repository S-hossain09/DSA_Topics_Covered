#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STACK_FULL 'F'
#define NOT_ 'N'
#define STACK_EMPTY 'E'


typedef struct stack_arr
{
    int size;
    int top;
    char *paran_arr;

}stack_arr;

char full_(stack_arr* ptr);
char empty_(stack_arr* ptr);
void pop_stack(stack_arr* ptr);
void push_stack(stack_arr* ptr, char element);



int main()
{
    char random_paranthesis[100];

    printf("Enter random set of characters\n");
    printf("Make sure it is between 100 characters :\n");

    scanf("%[^\n]", random_paranthesis);

    int counting_str_len = 0;
    // int counting_str_len = strlen(random_paranthesis);

    for(int i = 0; random_paranthesis[i] != '\0'; i++)
    {
        counting_str_len++;
    }

    stack_arr *test = (stack_arr*)malloc(sizeof(stack_arr));

    test->size = counting_str_len;
    test->top = -1;
    test->paran_arr = (char*)malloc(test->size * (sizeof(int)));


    for(int i = 0; random_paranthesis[i] != '\0'; i++)
    {
        if(random_paranthesis[i] == '(')
        {
            push_stack(test,random_paranthesis[i]);
        }

        else if(random_paranthesis[i] == ')')
        {
            pop_stack(test);
        }
    }

    if(empty_(test) == STACK_EMPTY)
    {
        printf("The paranthesis is perfectly balanced\n");
    }

    else
    {
        printf("The paranthesis is unbalanced\n");
    }


    return 0;
}


char full_(stack_arr* ptr)
{
    if(ptr->top == ptr->size)
    {
        return STACK_FULL;
    }

    else
    {
        return NOT_;
    }
}

char empty_(stack_arr* ptr)
{
    if(ptr->top == -1)
    {
        return STACK_EMPTY;
    }
    
    else
    {
        return NOT_;
    }
}

void pop_stack(stack_arr* ptr)
{
    if(empty_(ptr) == STACK_EMPTY)
    {
        printf("The paranthesis is Unbalanced because it cannot pop\n");
    }
    
    else
    {
        ptr->top--;
    }
}

void push_stack(stack_arr* ptr, char element)
{
    if(full_(ptr) == STACK_FULL)
    {
        printf("Stack Overflow\n");
    }

    else
    {
        ptr->top++;
        ptr->paran_arr[ptr->top] = element;
    }
}
