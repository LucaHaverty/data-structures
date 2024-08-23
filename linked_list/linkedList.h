#pragma once

typedef struct ListNode
{
    int data;
    struct ListNode *next;
} ListNode;

typedef struct LinkedList
{
    ListNode *head;
} LinkedList;

LinkedList *linked_list_create();
void linked_list_print(LinkedList *list);
void linked_list_append(LinkedList *list, int data);
void linked_list_remove(LinkedList *list, int data);
void linked_list_clear(LinkedList *list);
void linked_list_delete(LinkedList *list);
void linked_list_test();