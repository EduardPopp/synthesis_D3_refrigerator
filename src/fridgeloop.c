/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop
*/

#include "../include/helper.h"
#include "../include/my.h"

void add_items_to_fridge(char *linestr, char **inputarray, llist_t *fridge)
{
    llist_t *cur = fridge->prev;
    char *displaystring = NULL;
    int nb = my_getnbr(inputarray[2]);
    int is_valid_field = 0;
    int len = my_strlen(linestr) - 1;

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
        }
        if (strcmp(inputarray[1], cur->item) != 0)
            is_valid_field = -1;
    }
    if (is_valid_field == -1) {
        displaystring = strdup(linestr);
        displaystring[len] = '\0';
        printf("'%s': Invalid operation\n", displaystring);
    }
    free(displaystring);
}

int do_add_items(char *linestr, char **inputarray, char **command_array, \
llist_t *fridge)
{
    if (strcmp(inputarray[0], command_array[1]) == 0) {
        add_items_to_fridge(linestr, inputarray, fridge);
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

void low(char *linestr, char *itemname)
{
    int len = my_strlen(linestr) - 1;
    char *displaystr = NULL;

    displaystr = strdup(linestr);
    displaystr[len] = '\0';
    printf("'%s': not enough %s\n", displaystr, itemname);
    free(displaystr);
}

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

int do_make(char *linestr, char **inputarray, char **command_array, llist_t *fridge)
{
    if (strcmp(inputarray[0], command_array[2]) == 0) {
        make_meal(linestr, inputarray, fridge);
        return 1;
    }
    return 1;
}

int check_for_invalid_commands(char *linestr)
{
    char *displaystr = NULL;
    int len = my_strlen(linestr) - 1;
    char **arraystr = my_str_to_word_array(linestr, '\n', 0);

    if (strcmp(arraystr[0], "disp fridge\n") != 0) {
        displaystr = strdup(linestr);
        displaystr[len] = '\0';
        printf("'%s': Invalid operation\n", displaystr);
    }
    free(displaystr);
    free_input(arraystr);
    return 1;
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
    retval = do_add_items(linestr, inputarray, command_array, fridge);
    retval = do_make(linestr, inputarray, command_array, fridge);
    retval = check_for_invalid_commands(linestr);
    retval = do_exit(linestr, fridge);
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
