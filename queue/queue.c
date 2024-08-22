#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Node *queue_create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));

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
    Node *temp = queue->front;

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
    Node *newNode = queue_create_node(value);
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

    Node *front = queue->front;
    int returnData = front->data;

    queue->front = front->next;
    free(front);

    return returnData;
}

void queue_clear(Queue *queue)
{
    Node *temp = queue->front;

    while (temp != NULL)
    {
        Node *toDelete = temp;
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

void queue_test()
{
    printf("Testing queue:\n\n");

    Queue *queue = queue_create();

    printf("Enqueued 2\n");
    queue_enqueue(queue, 2);
    printf("Enqueued 5\n\n");
    queue_enqueue(queue, 5);

    queue_print(queue);

    printf("\nDequeued %d\n", queue_dequeue(queue));
    printf("Dequeued %d\n\n", queue_dequeue(queue));

    queue_print(queue);

    free(queue);
}
