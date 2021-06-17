/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** make_command
*/

#include "../include/helper.h"
#include "../include/my.h"

void make_pizza_ext(llist_t *cur, char *linestr)
{
    if (strcmp(cur->item, "pepper") == 0 && cur->quantity >= 8)
            cur->quantity -= 8;
    if (strcmp(cur->item, "ham") == 0 && cur->quantity >= 4)
            cur->quantity -= 4;
    if (strcmp(cur->item, "cheese") == 0 && cur->quantity >= 3)
            cur->quantity -= 3;
    if ((strcmp(cur->item, "pepper") == 0 && cur->quantity < 8) || \
    (strcmp(cur->item, "ham") == 0 && cur->quantity < 4) || \
    (strcmp(cur->item, "cheese") == 0 && cur->quantity < 3)) {
        low(linestr, cur->item);
        return;
    }
}

void make_pizza(char *linestr, llist_t *fridge)
{
    llist_t *cur = fridge->prev;

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(cur->item, "tomato") == 0 && cur->quantity >= 5)
            cur->quantity -= 5;
        if (strcmp(cur->item, "dough") == 0 && cur->quantity >= 1)
            cur->quantity -= 1;
        if (strcmp(cur->item, "onion") == 0 && cur->quantity >= 3)
            cur->quantity -= 3;
        if (strcmp(cur->item, "olive") == 0 && cur->quantity >= 8)
            cur->quantity -= 8;
        if ((strcmp(cur->item, "tomato") == 0 && cur->quantity < 5) || \
        (strcmp(cur->item, "dough") == 0 && cur->quantity < 1) || \
        (strcmp(cur->item, "onion") == 0 && cur->quantity < 3) || \
        (strcmp(cur->item, "olive") == 0 && cur->quantity < 8)) {
            low(linestr, cur->item);
        }
        make_pizza_ext(cur, linestr);
    }
}

void make_pasta(char *linestr, llist_t *fridge)
{
    llist_t *cur = fridge->prev;

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(cur->item, "tomato") == 0 && cur->quantity >= 5)
            cur->quantity -= 5;
        if (strcmp(cur->item, "pasta") == 0 && cur->quantity >= 2)
            cur->quantity -= 2;
        if (strcmp(cur->item, "olive") == 0 && cur->quantity >= 6)
            cur->quantity -= 6;
        if (strcmp(cur->item, "cheese") == 0 && cur->quantity >= 3)
            cur->quantity -= 3;
        if (strcmp(cur->item, "ham") == 0 && cur->quantity >= 4)
            cur->quantity -= 4;
        if ((strcmp(cur->item, "tomato") == 0 && cur->quantity < 5)|| \
        (strcmp(cur->item, "pasta") == 0 && cur->quantity < 2) || \
        (strcmp(cur->item, "olive") == 0 && cur->quantity < 6) || \
        (strcmp(cur->item, "cheese") == 0 && cur->quantity < 3) || \
        (strcmp(cur->item, "ham") == 0 && cur->quantity < 4))
            low(linestr, cur->item);
    }
}

void make_meal(char *linestr, char **inputarray, llist_t *fridge)
{
    char *displaystr = NULL;
    int len = my_strlen(inputarray[1]) - 1;

    if (strcmp(inputarray[1], "pizza\n") == 0)
        make_pizza(linestr, fridge);
    if (strcmp(inputarray[1], "pasta\n") == 0) {
        make_pasta(linestr, fridge);
    }
    if (strcmp(inputarray[1], "pizza\n") != 0 && \
    strcmp(inputarray[1], "pasta\n") != 0) {
        displaystr = strdup(inputarray[1]);
        displaystr[len] = '\0';
        printf("'%s': meal unknown\n", displaystr);
    }
    free(displaystr);
}

int do_make(char *linestr, char **inputarray, char **command_array, \
llist_t *fridge)
{
    if (strcmp(inputarray[0], command_array[2]) == 0) {
        make_meal(linestr, inputarray, fridge);
        return 1;
    }
    return 1;
}