/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** free_utils
*/

#include "../include/helper.h"
#include "../include/my.h"

void free_items(char **itemchain)
{
    for (int i = 0; itemchain[i] != NULL; i++) {
        free(itemchain[i]);
    }
    free(itemchain);
}

void list_free(llist_t *fridge, char **command_array)
{
    llist_t *cur = fridge->prev;
    llist_t *next;

    for (int i = 0; i < 5; i++) {
        free(command_array[i]);
    }
    free(command_array);
    while (cur != NULL) {
        next = cur->next;
        free(cur);
        cur = next;
    }
    fridge->prev = NULL;
    free(fridge);
    free(cur);
}