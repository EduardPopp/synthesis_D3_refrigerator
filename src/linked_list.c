/*
** EPITECH PROJECT, 2021
** linked_list.c
** File description:
** linked_list
*/

#include "../include/helper.h"
#include "../include/my.h"

llist_t *create_obj(llist_t *next_node, char **itemchain, int i)
{
    next_node->item = itemchain[i];
    next_node->quantity = atoi(itemchain[i + 2]);
    return (next_node);
}

int size_manager(llist_t *list, llist_t *next_node)
{
    if (list == NULL || next_node == NULL)
        return (-1);
    if (list->size == 0) {
        list->prev = next_node;
        list->next = next_node;
    } else {
        list->next->next = next_node;
        next_node->prev = list->next;
        list->next = next_node;
    }
    list->size += 1;
    return (0);
}

int new_node(llist_t *list, char **itemchain, int i)
{
    llist_t *next_node = malloc(sizeof(llist_t));

    if (list == NULL || next_node == NULL)
        return (-1);
    next_node->prev = NULL;
    next_node->next = NULL;
    next_node = create_obj(next_node, itemchain, i);
    if (next_node == NULL)
        return (-1);
    if (size_manager(list, next_node) == -1)
        return (-1);
    return (0);
}

llist_t *create_list(void)
{
    llist_t *list = malloc(sizeof(llist_t));

    if (list == NULL)
        return (NULL);
    list->prev = NULL;
    list->next = NULL;
    list->item = NULL;
    list->quantity = 0;
    list->size = 0;
    return (list);
}