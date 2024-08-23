#pragma once

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    struct QueueNode *front;
    struct QueueNode *back;
} Queue;

Queue *queue_create();
int queue_is_empty(Queue *queue);
void queue_print(Queue *queue);
void queue_enqueue(Queue *queue, int data);
int queue_dequeue(Queue *queue);
int queue_peek(Queue *queue);
void queue_clear(Queue *queue);
void queue_delete(Queue *queue);