#pragma once

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct Stack
{
    StackNode *top;
} Stack;

Stack *stack_create();
void stack_print(Stack *stack);
int stack_check_empty(Stack *stack);
void stack_push(Stack *stack, int data);
int stack_peek(Stack *stack);
int stack_pop(Stack *stack);
void stack_clear(Stack *stack);
void stack_delete(Stack *stack);
void stack_test();