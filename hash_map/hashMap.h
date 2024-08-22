#pragma once

#define TABLE_SIZE 100

typedef struct Node
{
    char *key;
    int value;
    struct Node *next;
} Node;

typedef struct HashMap
{
    Node *table[TABLE_SIZE];
} HashMap;

HashMap *hash_map_create();
void hash_map_insert(HashMap *map, char *key, int value);
int hash_map_find(HashMap *map, char *key);
void hash_map_remove_key(HashMap *map, char *key);
void hash_map_clear(HashMap *map);
void hash_map_delete(HashMap *map);
void hash_map_test();