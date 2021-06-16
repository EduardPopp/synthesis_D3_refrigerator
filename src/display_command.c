/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** display_command
*/

#include "../include/helper.h"
#include "../include/my.h"

void display_fridge_content(llist_t *fridge)
{
    llist_t *cur = malloc(sizeof(llist_t));

    for (cur = fridge->prev; cur != NULL; cur = cur->next) {
        printf("%s = %d\n", cur->item, cur->quantity);
    }
    free(cur);
}