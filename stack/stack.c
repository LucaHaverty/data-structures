#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../color_print/colorPrint.c"

Node *stack_create_node(int data, Node *next)
{
    Node *node = (Node *)malloc(sizeof(Node));

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
    Node *temp = stack->top;

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
    Node *newNode = stack_create_node(data, stack->top);
    stack->top = newNode;
}

int stack_peek(Stack *stack)
{
    if (stack_check_empty(stack))
    {
        printf("Stack underflow! No elements to peek!\n");
        return INT_MIN;
    }

    return stack->top->data;
}

int stack_pop(Stack *stack)
{
    if (stack_check_empty(stack))
    {
        printf("Stack underflow! No elements to pop!\n");
        return INT_MIN;
    }

    Node *temp = stack->top;
    int poppedData = temp->data;
    stack->top = temp->next;
    free(temp);

    return poppedData;
}

void stack_clear(Stack *stack)
{
    Node *temp = stack->top;

    while (temp != NULL)
    {
        Node *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }
}

void stack_delete(Stack *stack)
{
    stack_clear(stack);
    free(stack);
}

void stack_test()
{
    color_print_green("Testing stack...\n\n");
    Stack *stack = stack_create();

    stack_print(stack);
    stack_push(stack, 5);
    stack_print(stack);
    stack_push(stack, 3);
    stack_print(stack);
    printf("Peeked at %d\n", stack_peek(stack));
    stack_print(stack);

    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);
    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);
    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);

    free(stack);

    color_print_green("\nStack test complete!\n");
}