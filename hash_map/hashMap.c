#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashmap.h"

unsigned int hash(char *key)
{
    unsigned int hash = 0;
    while (*key)
    {
        hash = (hash << 5) + *key++;
    }
    return hash % TABLE_SIZE;
}

HashMap *hash_map_create()
{
    HashMap *map = (HashMap *)malloc(sizeof(HashMap));
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        map->table[i] = NULL;
    }

    return map;
}

void hash_map_insert(HashMap *map, char *key, int value)
{
    unsigned int index = hash(key);
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->key = strdup(key);
    newNode->value = value;
    newNode->next = map->table[index];
    map->table[index] = newNode;
}

int hash_map_find(HashMap *map, char *key)
{
    unsigned int index = hash(key);
    Node *node = map->table[index];
    while (node != NULL)
    {
        if (strcmp(node->key, key) == 0)
        {
            return node->value;
        }
        node = node->next;
    }
    return -1; // Key not found
}

void hash_map_remove_key(HashMap *map, char *key)
{
    unsigned int index = hash(key);
    Node *node = map->table[index];
    Node *prev = NULL;

    while (node != NULL && strcmp(node->key, key) != 0)
    {
        prev = node;
        node = node->next;
    }

    if (node == NULL)
    {
        return; // Key not found
    }

    if (prev == NULL)
    {
        map->table[index] = node->next;
    }
    else
    {
        prev->next = node->next;
    }

    free(node->key);
    free(node);
}

void hash_map_clear(HashMap *map)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        Node *node = map->table[i];
        while (node != NULL)
        {
            Node *temp = node;
            node = node->next;
            free(temp->key);
            free(temp);
        }
    }
}

void hash_map_delete(HashMap *map)
{
    hash_map_clear(map);
    free(map);
}

void hash_map_test()
{
    printf("Testing hash map:\n\n");
    HashMap *map = hash_map_create();

    hash_map_insert(map, "key1", 10);
    hash_map_insert(map, "key2", 20);

    printf("key1: %d\n", hash_map_find(map, "key1"));
    printf("key2: %d\n", hash_map_find(map, "key2"));

    hash_map_remove_key(map, "key1");
    printf("key1 after removal: %d\n", hash_map_find(map, "key1"));

    hash_map_delete(map);
}