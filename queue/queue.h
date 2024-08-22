#pragma once

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct Queue
{
    struct Node *front;
    struct Node *back;
} Queue;

Queue *queue_create();
int queue_is_empty(Queue *queue);
void queue_print(Queue *queue);
void queue_enqueue(Queue *queue, int data);
int queue_dequeue(Queue *queue);
void queue_clear(Queue *queue);
void queue_delete(Queue *queue);
void queue_test();