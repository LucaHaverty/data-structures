#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueueNode *queue_create_node(int data)
{
    QueueNode *node = (QueueNode *)malloc(sizeof(QueueNode));

    node->data = data;
    node->next = NULL;

    return node;
}

Queue *queue_create()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));

    queue->front = NULL;
    queue->back = NULL;

    return queue;
}

int queue_is_empty(Queue *queue)
{
    return queue->front == NULL;
}

void queue_print(Queue *queue)
{
    printf("Queue:\n");
    QueueNode *temp = queue->front;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

/* Create a new node and add it to the back of the queue */
void queue_enqueue(Queue *queue, int value)
{
    QueueNode *newNode = queue_create_node(value);
    if (queue->front == NULL)
    {
        queue->front = newNode;
        queue->back = newNode;
    }
    else
    {
        queue->back->next = newNode;
    }
}

/** Pop the node off the front of the queue and return it's value */
int queue_dequeue(Queue *queue)
{
    if (queue->front == NULL)
    {
        printf("Stack underflow! No elements to peek!\n");
        return INT_MIN;
    }

    QueueNode *front = queue->front;
    int returnData = front->data;

    queue->front = front->next;
    free(front);

    return returnData;
}

void queue_clear(Queue *queue)
{
    QueueNode *temp = queue->front;

    while (temp != NULL)
    {
        QueueNode *toDelete = temp;
        temp = temp->next;
        free(toDelete);
    }

    queue->front = NULL;
    queue->back = NULL;
}

void queue_delete(Queue *queue)
{
    queue_clear(queue);
    free(queue);
}
