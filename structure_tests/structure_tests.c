#include <stdio.h>
#include <stdlib.h>
#include "../hash_map/hash_map.h"
#include "../color_print/color_print.h"
#include "../linked_list/linked_list.h"
#include "../queue/queue.h"
#include "../stack/stack.h"
#include "../unit_test/unit_test.h"

void structure_test_hash_map()
{
    unit_test_describe_section("Hash map");

    HashMap *map = hash_map_create();

    hash_map_insert(map, "key1", 10);
    hash_map_insert(map, "key2", 20);

    unit_test_assert_int("Get existing key", hash_map_find(map, "key1"), 10);
    unit_test_assert_int("Get nonexisting key", hash_map_find(map, "key3"), INT_MIN);
    unit_test_assert_int("Get existing key", hash_map_find(map, "key2"), 20);

    hash_map_remove_key(map, "key2");

    unit_test_assert_int("Get removed key", hash_map_find(map, "key2"), INT_MIN);

    hash_map_insert(map, "key1", 12);
    hash_map_insert(map, "key2", 12);
    hash_map_clear(map);

    unit_test_assert_int("Clear hash map", hash_map_find(map, "key1"), INT_MIN);

    hash_map_delete(map);
}

void structure_test_linked_list()
{
    unit_test_describe_section("Linked list");

    LinkedList *list = linked_list_create();

    linked_list_append(list, 5);
    linked_list_append(list, 7);

    unit_test_assert_int("Get existing value", linked_test_get(list, 0), 5);
    unit_test_assert_int("Get existing value", linked_test_get(list, 1), 7);
    unit_test_assert_int("Get out of range value", linked_test_get(list, 3), INT_MIN);

    linked_list_remove(list, 5);

    unit_test_assert_int("Get removed value", linked_test_get(list, 1), INT_MIN);
    unit_test_assert_int("Get existing value", linked_test_get(list, 0), 7);

    linked_list_append(list, 7);
    linked_list_remove(list, 7);

    unit_test_assert_int("Get existing value", linked_test_get(list, 0), 7);

    linked_list_remove(list, 5);

    unit_test_assert_int("Remove nonexisting value", linked_test_get(list, 0), 7);

    linked_list_clear(list);

    unit_test_assert_int("Clear list", linked_test_get(list, 0), INT_MIN);

    linked_list_delete(list);
}

void structure_test_queue()
{
    unit_test_describe_section("Queue");
    Queue *queue = queue_create();

    queue_enqueue(queue, 2);
    queue_enqueue(queue, 5);

    unit_test_assert_int("Dequeue value", queue_dequeue(queue), 2);
    unit_test_assert_int("Dequeue value", queue_dequeue(queue), 5);
    unit_test_assert_int("Dequeue empty", queue_dequeue(queue), INT_MIN);

    queue_enqueue(queue, 2);
    queue_enqueue(queue, 5);

    unit_test_assert_int("Peek value", queue_peek(queue), 2);
    unit_test_assert_int("Peek value", queue_peek(queue), 2);

    queue_clear(queue);

    unit_test_assert_int("Clear queue", queue_dequeue(queue), INT_MIN);
    unit_test_assert_int("Peek empty", queue_peek(queue), INT_MIN);

    queue_delete(queue);
}

void structure_test_stack()
{
    unit_test_describe_section("Stack");

    Stack *stack = stack_create();

    unit_test_assert_int("Check empty true", stack_check_empty(stack), 1);

    stack_push(stack, 5);
    stack_push(stack, 3);

    unit_test_assert_int("Check empty false", stack_check_empty(stack), 0);

    unit_test_assert_int("Peek value", stack_peek(stack), 3);
    unit_test_assert_int("Pop value", stack_pop(stack), 3);
    unit_test_assert_int("Pop value", stack_pop(stack), 5);
    unit_test_assert_int("Peek empty", stack_peek(stack), INT_MIN);
    unit_test_assert_int("Pop empty", stack_pop(stack), INT_MIN);

    stack_push(stack, 5);
    stack_push(stack, 3);

    stack_clear(stack);

    unit_test_assert_int("Clear stack", stack_check_empty(stack), 1);

    stack_delete(stack);
}

void structure_test_all()
{
    structure_test_hash_map();
    structure_test_linked_list();
    structure_test_queue();
    structure_test_stack();
}