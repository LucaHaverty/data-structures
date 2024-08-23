#pragma once

#define TABLE_SIZE 100

typedef struct HashMapNode
{
    char *key;
    int value;
    struct HashMapNode *next;
} HashMapNode;

typedef struct HashMap
{
    HashMapNode *table[TABLE_SIZE];
} HashMap;

HashMap *hash_map_create();
void hash_map_insert(HashMap *map, char *key, int value);
int hash_map_find(HashMap *map, char *key);
void hash_map_remove_key(HashMap *map, char *key);
void hash_map_clear(HashMap *map);
void hash_map_delete(HashMap *map);