#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"
#include "../color_print/colorPrint.c"

Node *linked_list_create_node(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

LinkedList *linked_list_create()
{
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

void linked_list_print(LinkedList *list)
{
    struct Node *temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void linked_list_append(LinkedList *list, int data)
{
    Node *newNode = linked_list_create_node(data);
    Node *temp = list->head;

    if (temp == NULL)
    {
        list->head = newNode;
        return;
    }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void linked_list_remove(LinkedList *list, int data)
{
    Node *temp = list->head;

    if (temp != NULL && temp->data == data)
    {
        list->head = temp->next;
        free(temp);
        return;
    }

    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            Node *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
}

void linked_list_clear(LinkedList *list)
{
    Node *temp = list->head;

    while (temp != NULL)
    {
        free(temp);
        temp = temp->next;
    }
    list->head = NULL;
}

void linked_list_delete(LinkedList *list)
{
    linked_list_clear(list);
    free(list);
}

void linked_list_test()
{
    color_print_green("Testing linked list...\n\n");

    LinkedList *list = linked_list_create();

    linked_list_print(list);

    linked_list_append(list, 5);
    linked_list_append(list, 7);

    linked_list_print(list);

    linked_list_remove(list, 7);
    linked_list_remove(list, 5);

    linked_list_print(list);

    linked_list_delete(list);

    color_print_green("\nLinked list test complete!\n");
}
