/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop
*/

#include "../include/helper.h"
#include "../include/my.h"

void add_items_to_fridge(char *linestr, char **inputarray, llist_t *fridge, \
int is_valid_field)
{
    llist_t *cur = fridge->prev;
    char *displaystring = NULL;
    int nb = my_getnbr(inputarray[2]);
    int len = my_strlen(linestr) - 1;

    for (; cur != NULL; cur = cur->next) {
        if (strcmp(inputarray[1], cur->item) == 0) {
            cur->quantity += nb;
            is_valid_field = 0;
            break;
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
    int is_valid_field = 0;

    if (strcmp(inputarray[0], command_array[1]) == 0) {
        add_items_to_fridge(linestr, inputarray, fridge, is_valid_field);
        return 1;
    }
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
