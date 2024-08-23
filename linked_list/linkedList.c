#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

ListNode *linked_list_create_node(int data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));

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
    struct ListNode *temp = list->head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void linked_list_append(LinkedList *list, int data)
{
    ListNode *newNode = linked_list_create_node(data);
    ListNode *temp = list->head;

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
    ListNode *temp = list->head;

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
            ListNode *toDelete = temp->next;
            temp->next = toDelete->next;
            free(toDelete);
            return;
        }
        temp = temp->next;
    }
}

void linked_list_clear(LinkedList *list)
{
    ListNode *temp = list->head;

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
