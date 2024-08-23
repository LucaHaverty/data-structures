#include <stdio.h>
#include "../hash_map/hashMap.h"
#include "../color_print/colorPrint.h"
#include "../linked_list/linkedList.h"
#include "../queue/queue.h"
#include "../stack/stack.h"

void structure_test_hash_map()
{
    color_print_green("Testing hash map...\n\n");
    printf("Testing hash map:\n\n");
    HashMap *map = hash_map_create();

    hash_map_insert(map, "key1", 10);
    hash_map_insert(map, "key2", 20);

    printf("key1: %d\n", hash_map_find(map, "key1"));
    printf("key2: %d\n", hash_map_find(map, "key2"));

    hash_map_remove_key(map, "key1");
    printf("key1 after removal: %d\n", hash_map_find(map, "key1"));

    hash_map_delete(map);

    color_print_green("\nHash map test complete!\n\n");
}

void structure_test_linked_list()
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

    color_print_green("\nLinked list test complete!\n\n");
}

void structure_test_queue()
{
    color_print_green("Testing queue...\n\n");

    Queue *queue = queue_create();

    printf("Enqueued 2\n");
    queue_enqueue(queue, 2);
    printf("Enqueued 5\n\n");
    queue_enqueue(queue, 5);

    queue_print(queue);

    printf("\nDequeued %d\n", queue_dequeue(queue));
    printf("Dequeued %d\n\n", queue_dequeue(queue));

    queue_print(queue);

    queue_delete(queue);

    color_print_green("\nQueue test complete!\n\n");
}

void structure_test_stack()
{
    color_print_green("Testing stack...\n\n");
    Stack *stack = stack_create();

    stack_print(stack);
    stack_push(stack, 5);
    stack_print(stack);
    stack_push(stack, 3);
    stack_print(stack);
    printf("Peeked at %d\n", stack_peek(stack));
    stack_print(stack);

    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);
    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);
    printf("Popped %d\n", stack_pop(stack));
    stack_print(stack);

    stack_delete(stack);

    color_print_green("\nStack test complete!\n\n");
}

void structure_test_all()
{
    structure_test_hash_map();
    structure_test_linked_list();
    structure_test_queue();
    structure_test_stack();
}