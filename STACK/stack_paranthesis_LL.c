#include <stdio.h>
#include <stdlib.h>

#define EMPTY 'E'
#define FULL 'F'
#define NOT_ 'N'

typedef struct stack_LL
{
    char element;
    struct stack_LL *next;

}stack_LL;

char is_empty(stack_LL *top);
char pop(stack_LL **top);
// void pop(stack_LL **top);
char is_full(stack_LL *top);
stack_LL *push(stack_LL *top, char paran);

int main()
{
    system("clear");

    char random_paranthesis[100];

    printf("Enter random set of characters\n");
    printf("Make sure it is between 100 characters :\n");

    scanf("%[^\n]", random_paranthesis);

    // int counting_str_len = 0;
    // int counting_str_len = strlen(random_paranthesis);

    // for(int i = 0; random_paranthesis[i] != '\0'; i++)
    // {
    //     counting_str_len++;
    // }

    stack_LL *top = NULL;

    for (int i = 0; random_paranthesis[i] != '\0'; i++)
    {
        if (random_paranthesis[i] == '(')
        {
            top = push(top, random_paranthesis[i]);
        }

        else if (random_paranthesis[i] == ')')
        {
            // pop(&top);
        }
    }

    if (is_empty(top) == EMPTY)
    {
        printf("The paranthesis is perfectly balanced\n");
    }

    else
    {
        printf("The paranthesis is unbalanced\n");
    }

    return 0;
}

char is_empty(stack_LL *top)
{
    if (top == NULL)
    {
        return EMPTY;
    }

    else
    {
        return NOT_;
    }
}

char is_full(stack_LL *top)
{
    stack_LL *checking_space = (stack_LL *)malloc(sizeof(stack_LL));

    if (checking_space == NULL)
    {
        return FULL;
    }

    else
    {
        return NOT_;
    }
}

stack_LL *push(stack_LL *top, char paran)
{
    if (is_full(top) == FULL)
    {
        printf("Cannot push stack is full");
    }

    else
    {
        stack_LL *temp_for_inserting = (stack_LL *)malloc(sizeof(stack_LL));

        temp_for_inserting->element = paran;
        temp_for_inserting->next = top;

        top = temp_for_inserting;

        return top;
    }
}

char pop(stack_LL **top)
{
    if (is_empty(*top) == EMPTY)
    {
        // printf("Cannot Pop, Stack is empty\n");
        return EMPTY;
    }

    else
    {
        stack_LL *deleting_with_this = *top;

        *top = (*top)->next;

        free(deleting_with_this);
    }
}

