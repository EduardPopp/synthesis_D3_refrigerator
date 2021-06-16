/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** exit_fridge
*/

#include "../include/helper.h"
#include "../include/my.h"

void save_fridge_inventory(llist_t *fridge)
{
    llist_t *cur = malloc(sizeof(llist_t));
    FILE *savefile;

    savefile = fopen(".save", "w");
    for (cur = fridge->prev; cur != NULL; cur = cur->next) {
        fprintf(savefile, "%s = %d\n", cur->item, cur->quantity);
    }
    fclose(savefile);
    free(cur);
}

void exit_command(llist_t *fridge)
{
    save_fridge_inventory(fridge);
    exit(0);
}