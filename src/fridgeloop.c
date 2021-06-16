/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop
*/

#include "../include/helper.h"
#include "../include/my.h"

void add_cheese(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_ham(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_pepper(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_olives(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_pasta(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_onions(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_dough(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_tomatoes(char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    int nb = my_getnbr(inputarray[2]);

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
    }
}

void add_items_to_fridge(char **inputarray, llist_t *fridge)
{
    if (strcmp(inputarray[1], "tomato") == 0)
        add_tomatoes(inputarray, fridge);
    if (strcmp(inputarray[1], "dough") == 0)
        add_dough(inputarray, fridge);
    if (strcmp(inputarray[1], "onion") == 0)
        add_onions(inputarray, fridge);
    if (strcmp(inputarray[1], "pasta") == 0)
        add_pasta(inputarray, fridge);
    if (strcmp(inputarray[1], "olive") == 0)
        add_olives(inputarray, fridge);
    if (strcmp(inputarray[1], "pepper") == 0)
        add_pepper(inputarray, fridge);
    if (strcmp(inputarray[1], "ham") == 0)
        add_ham(inputarray, fridge);
    if (strcmp(inputarray[1], "cheese") == 0)
        add_cheese(inputarray, fridge);
}

int do_add_items(char **inputarray, char **command_array, llist_t *fridge)
{
    if (strcmp(inputarray[0], command_array[1]) == 0) {
        add_items_to_fridge(inputarray, fridge);
        return 1;
    }
    return 1;
}

void free_input(char **inputarray)
{
    for (int i = 0; inputarray[i] != NULL; i++) {
    free(inputarray[i]);
    }
    free(inputarray);
}

int get_input(llist_t *fridge, char **command_array)
{
    char *linestr = NULL;
    size_t len = 0;
    int nread = 0;
    int retval = 0;
    char **inputarray = NULL;

    nread = getline(&linestr, &len, stdin);
    if (nread == -1)
        exit(84);
    inputarray = my_str_to_word_array(linestr, ' ', 0);
    retval = do_display(linestr, fridge);
    retval = do_add_items(inputarray, command_array, fridge);
    retval = do_exit(linestr, fridge);
    //if (strcmp(inputarray[0], command_array[2]) == 0)
        //make_meal(linestr, fridge);
    //check_for_invalid_commands(linestr, command_array, fridge);
    free(linestr);
    free_input(inputarray);
    return retval;
}

void fridge_loop(llist_t *fridge, int loopstate, char **command_array)
{
    while (loopstate == 1) {
        loopstate = get_input(fridge, command_array);
    }
}
