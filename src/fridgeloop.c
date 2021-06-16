/*
** EPITECH PROJECT, 2021
** synthesis_D3_refrigerator
** File description:
** fridgeloop
*/

#include "../include/helper.h"
#include "../include/my.h"

void get_input(llist_t *fridge, char **command_array)
{
    char *linestr = NULL;
    size_t len = 0;
    int nread = 0;

    getline(&linestr, &len, stdin);
    if (nread == -1)
        exit(84);
    if (strcmp("disp fridge\n", command_array[0]) == 0)
        display_fridge_content(fridge);
    if (strcmp("addToFridge\n", command_array[1]) == 0)
        //add_items_to_fridge(linestr, fridge);
    if (strcmp("make\n", command_array[2]) == 0)
        //make_meal(linestr, fridge);
    if (strcmp("exit\n", command_array[3]) == 0)
        exit_command(fridge);
    //check_for_invalid_commands(linestr, command_array, fridge);
}

void fridge_loop(llist_t *fridge, int loopstate, char **command_array)
{
    while (loopstate == 1) {
        get_input(fridge, command_array);
    }
}
