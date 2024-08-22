#pragma once

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct LinkedList
{
    Node *head;
} LinkedList;

LinkedList *linked_list_create();
void linked_list_print(LinkedList *list);
void linked_list_append(LinkedList *list, int data);
void linked_list_remove(LinkedList *list, int data);
void linked_list_clear(LinkedList *list);
void linked_list_delete(LinkedList *list);
void linked_list_test();