#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

StackNode *stack_create_node(int data, StackNode *next)
{
    StackNode *node = (StackNode *)malloc(sizeof(StackNode));

    node->data = data;
    node->next = next;

    return node;
}

Stack *stack_create()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

void stack_print(Stack *stack)
{
    StackNode *temp = stack->top;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int stack_check_empty(Stack *stack)
{
    return stack->top == NULL;
}

void stack_push(Stack *stack, int data)
{
    StackNode *newNode = stack_create_node(data, stack->top);
    stack->top = newNode;
}

int stack_peek(Stack *stack)
{
    if (stack_check_empty(stack))
    {
        return INT_MIN;
    }

    return stack->top->data;
}

int stack_pop(Stack *stack)
{
    if (stack_check_empty(stack))
    {
        return INT_MIN;
    }

    StackNode *temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedData;
}

void stack_clear(Stack *stack)
{
    StackNode *temp = stack->top;

    while (temp != NULL)
    {
        StackNode *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    stack->top = NULL;
}

void stack_delete(Stack *stack)
{
    stack_clear(stack);
    free(stack);
}
